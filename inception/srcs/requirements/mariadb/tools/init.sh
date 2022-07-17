#!/bin/sh


echo "-----2-----"
mv 50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

echo "-----3-----"
service mysql start
echo "-----4-----"
mysql < set_mysql.sql

echo "-----5-----"
service mysql restart



exec mysqld_safe --datadir=/var/lib/mysql