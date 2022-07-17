FROM debian:buster

WORKDIR /tmp

RUN apt update
RUN apt upgrade -y
RUN apt install curl php7.3-fpm php7.3-mysql -y

COPY ./tools/init.sh /tmp
COPY ./conf/wp-config.php /tmp
COPY ./conf/www.conf /tmp

ENTRYPOINT ["sh", "init.sh"]
