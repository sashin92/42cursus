FROM alpine:3.14 

WORKDIR /tmp

RUN apk update
RUN apk add wget php7-fpm

COPY ./conf/wp-config.php /tmp

RUN wget https://ko.wordpress.org/latest-ko_KR.tar.gz
RUN tar -xf latest-ko_KR.tar.gz
RUN rm -rf latest-ko_KR.tar.gz
RUN mv /tmp/wp-config.php /tmp/wordpress/wp-config.php

RUN mkdir -p /var/www/html
RUN mv /tmp/wordpress /var/www/html/wordpress
