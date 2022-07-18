FROM debian:buster

WORKDIR /tmp

RUN apt update
RUN apt upgrade -y
RUN apt install curl php7.3-fpm php7.3-mysql -y

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
RUN mkdir -p /var/www/html/wordpress
RUN wp core download --allow-root --path=/var/www/html/wordpress

COPY ./tools/init.sh /tmp
COPY ./conf/wp-config.php /tmp
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

ENTRYPOINT ["sh", "init.sh"]
