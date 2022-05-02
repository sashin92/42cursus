FROM alpine:3.14

WORKDIR /


RUN apk update
RUN apk upgrade
RUN apk add nginx openssl

RUN wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64
RUN chmod +x /usr/local/bin/dumb-init

COPY ./conf/default.conf /etc/nginx/http.d/
COPY ./tools/init.sh /

EXPOSE 443

# Runs "/usr/bin/dumb-init -- /my/script --with --args"
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# or if you use --rewrite or other cli flags
# ENTRYPOINT ["dumb-init", "--rewrite", "2:3", "--"]

CMD ["sh", "", "init.sh"]

# ENTRYPOINT ["sh", "init.sh"]