#!/bin/sh

mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

if [ ! -f /var/www/html/wordpress/wp-config.php ]; then
	cp /tmp/wp-config.php /var/www/html/wordpress

	cd /var/www/html/wordpress

	wp core install --allow-root --url="${DOMAIN_NAME}" --title="${WORDPRESS_NAME}" --admin_user="${WORDPRESS_ROOT_LOGIN}" --admin_password="${WORDPRESS_ROOT_PASSWORD}" --admin_email="${WORDPRESS_ROOT_EMAIL}" --skip-email
	wp user create --allow-root "${WORDPRESS_USER_LOGIN}" "${WORDPRESS_USER_EMAIL}" --user_pass="${WORDPRESS_USER_PASSWORD}" --role=author
fi

exec php-fpm7.3 -F
