FROM debian:buster

WORKDIR /tmp

RUN apt update
RUN apt upgrade -y
RUN apt install mariadb-server -y

COPY ./tools/init.sh /tmp
COPY ./tools/set_mysql.sql /tmp
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf
RUN service mysql start && mysql < set_mysql.sql

EXPOSE 3306

ENTRYPOINT exec mysqld_safe --datadir=/var/lib/mysql
