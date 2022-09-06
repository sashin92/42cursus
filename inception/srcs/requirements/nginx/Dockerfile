FROM debian:buster

WORKDIR /tmp

RUN apt update
RUN apt upgrade -y
RUN apt install nginx openssl -y

COPY ./conf/default.conf /tmp
COPY ./tools/init.sh /tmp

EXPOSE 443

ENTRYPOINT ["sh", "init.sh"]
