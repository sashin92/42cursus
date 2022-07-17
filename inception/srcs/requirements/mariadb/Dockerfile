FROM debian:buster

WORKDIR /tmp

RUN apt update
RUN apt upgrade -y
RUN apt install mariadb-server -y

COPY ./tools/init.sh /tmp
COPY ./tools/set_mysql.sql /tmp
COPY ./conf/50-server.cnf /tmp

EXPOSE 3306

ENTRYPOINT ["sh", "init.sh"]
