#!/bin/bash
service nginx start
service php7.3-fpm start
service mysql start
service --status-all

mysql < set_mysql.sql
mysqladmin -u root -p password
service mysql reload

bash