FROM alpine:3.14 

WORKDIR /home/

RUN apk update
RUN apk upgrade
RUN apk wget php7-fpm

RUN wget https://ko.wordpress.org/latest-ko_KR.tar.gz
RUN tar -xvf latest-ko_KR.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN rm -rf latest-ko_KR.tar.gz
COPY ./src/wp-config.php /var/www/html/wordpress/

# ENTRYPOINT [ "bash", "init.sh" ]

