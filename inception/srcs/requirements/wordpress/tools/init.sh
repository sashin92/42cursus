#!/bin/sh

mv /tmp/www.conf /tec/php/7.3/fpm/pool.d/www.conf

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir -p /var/www/html/wordpress
wp core download --allow-root --path=/var/www/html/wordpress
mv /tmp/wp-config.php /var/www/html/wordpress
cd /var/www/html/wordpress

# wp core install --allow-root --url=${DOMAIN_NAME} --title=${WORDPRESS_NAME} --admin_user=${WORDPRESS_ROOT_LOGIN} --admin_password=${MYSQL_ROOT_PASSWORD} --admin_email=${WORDPRESS_ROOT_EMAIL}
# wp user create --allow-root ${MYSQL_USER} ${WORDPRESS_USER_EMAIL} --user_pass=${MYSQL_PASSWORD} --role=author

wp core install --allow-root --url=sashin.42.fr --title=wordpress --admin_user=root --admin_password=921206 --admin_email=root@42.fr
wp user create --allow-root sashin sashin@student.42seoul.kr --user_pass=921206 --role=author


wp plugin install --allow-root redis-cashe --active --path=/var/www/html/wordpress
wp plugin update --allow-root --all

wp redis --allow-root enable

exec php-fpm7.3 -F