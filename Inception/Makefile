all: up

up:
	mkdir -p ~/data/website
	mkdir -p ~/data/database
	cd srcs && docker compose up -d --build

down:
	cd srcs && docker compose down --volumes

clean: down
	docker system prune -a --volumes

re: clean all
