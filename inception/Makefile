NAME	= inception


# if not work, you input "127.0.0.1 sashin.42.fr" in /etc/hosts
all: up

up:
	mkdir -p ${HOME}/my_data/my_mariadb_data
	mkdir -p ${HOME}/my_data/my_wordpress_data
	docker-compose -f ./srcs/docker-compose.yml up
down:
	docker-compose -f ./srcs/docker-compose.yml down --rmi all -v

clean: down

fclean: clean
	rm -rf ${HOME}/my_data
	docker volume prune -f
	docker network prune -f

re: fclean up

.PHONY: all up down clean fclean re
