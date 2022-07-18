

up:
	docker-compose -f ./srcs/docker-compose.yml up
down:
	docker-compose -f ./srcs/docker-compose.yml down

clean:
	docker-compose -f ./srcs/docker-compose.yml down
	docker image rm my_nginx my_mariadb my_wordpress -f


fclean: clean
	sudo rm -rf /home/${USER}/inception
	docker volume prune -f
	docker network prune -f

.PHONY: up down clean fclean
