#!/bin/sh

echo making rootCA...
openssl req -new -newkey rsa:4096 -sha256 -nodes -keyout sashin-ssl.key \
-x509 -days 90 -subj "/C=KR/ST=Seoul/L=podong_podong_Gaepo-dong/O=42seoul/OU=Cluster/CN=localhost" -out sashin-ssl.crt

if [ ! -d /etc/ssl/certs ];then
	mkdir /etc/ssl/certs
fi

if [ ! -d /etc/ssl/private ];then
	mkdir /etc/ssl/private
fi

mv sashin-ssl.key /etc/ssl/private
mv sashin-ssl.crt /etc/ssl/certs

echo moving nginx configure file...
mv default.conf /etc/nginx/http.d/default.conf

echo Done!

exec nginx -g "daemon off;"
