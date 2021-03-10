FROM debian:buster

WORKDIR /root/

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y vim nginx wget mariadb-server \
php-mysql php7.3-fpm php-xml openssl

COPY ./src/default /etc/nginx/sites-available/
COPY ./src/phpinfo.php /var/www/html/
COPY ./src/set_mysql.sql /root/
COPY ./src/init.sh /root/

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.1.0-all-languages.tar.gz
RUN mv phpMyAdmin-5.1.0-all-languages /var/www/html/phpmyadmin
RUN rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz
COPY ./src/config.inc.php /var/www/html/phpmyadmin/

RUN wget https://ko.wordpress.org/latest-ko_KR.tar.gz
RUN tar -xvf latest-ko_KR.tar.gz
RUN mv wordpress /var/www/html/wordpress
RUN rm -rf latest-ko_KR.tar.gz
COPY ./src/wp-config.php /var/www/html/wordpress/

ENTRYPOINT [ "bash", "init.sh" ]