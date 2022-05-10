FROM alpine:3.14 

WORKDIR /tmp

RUN apk update
RUN apk add wget php7-fpm

RUN wget https://ko.wordpress.org/latest-ko_KR.tar.gz
RUN tar -xf latest-ko_KR.tar.gz
RUN rm -rf latest-ko_KR.tar.gz

COPY ./conf/wp-config.php /tmp
COPY ./tools/init.sh /tmp

RUN sh ./init.sh





# ENTRYPOINT ["sh", "init.sh"]
