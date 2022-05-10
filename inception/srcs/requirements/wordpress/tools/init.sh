#!/bin/sh

if [ ! -d /var/www ];then
	mkdir /var/www
fi

if [ ! -d /var/www/html ];then
	mkdir /var/www/html
fi

mv wordpress /var/www/html/wordpress
mv ./wp-config.php /var/www/html/wordpress/wp-config.php
