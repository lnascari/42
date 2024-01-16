all:
	mkdir -p ~/data/website
	mkdir -p ~/data/database
	cd srcr && docker-compose up -d

clean:
	cd srcr && docker-compose down --volumes
