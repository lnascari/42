all: up

up:
	mkdir -p ~/data/website
	mkdir -p ~/data/database
	cd srcr && docker-compose up -d

down:
	cd srcr && docker-compose down --volumes

clean: down
	rm -rf ~/data
