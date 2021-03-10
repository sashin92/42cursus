#!/bin/bash

#self signed certification(for ssl)
echo making rootCA...
openssl req -newkey rsa:2048 -nodes -keyout sashin-ssl.key \
-x509 -days 90 -subj "/C=KR/ST=Seoul/L=podong_podong_Gaepo-dong/O=42seoul/OU=Cluster/CN=localhost" -out sashin-ssl.crt
mv sashin-ssl.key /etc/ssl/private/
mv sashin-ssl.crt /etc/ssl/certs/

#service start
service nginx start
service php7.3-fpm start
service mysql start
service --status-all

#set mysql
mysql < set_mysql.sql
mysqladmin -u root -p password
service mysql reload

bash