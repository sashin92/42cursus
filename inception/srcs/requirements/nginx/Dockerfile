FROM alpine:3.14

WORKDIR /tmp


RUN apk update
RUN apk upgrade
RUN apk add nginx openssl

COPY ./conf/default.conf /tmp
COPY ./tools/init.sh /tmp

EXPOSE 443

# ENTRYPOINT ["sh", "init.sh"]
