#!/bin/sh

mv 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start
mysql < set_mysql.sql


exec mysqld_safe --datadir=/var/lib/mysql