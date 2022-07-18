NAME	= inception


# if not work, you input "127.0.0.1 sashin.42.fr" in /etc/hosts
all: up

up:
	sudo mkdir -p ${HOME}/my_data/my_mariadb_data
	sudo mkdir -p ${HOME}/my_data/my_wordpress_data
	sudo docker-compose -f ./srcs/docker-compose.yml up
down:
	sudo docker-compose -f ./srcs/docker-compose.yml down --rmi all -v

clean: down

fclean: clean
	sudo rm -rf ${HOME}/my_data
	sudo docker volume prune -f
	sudo docker network prune -f

re: fclean up

.PHONY: all up down clean fclean re
