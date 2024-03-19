FROM alpine:3.18.5

ARG MYSQL_USER

ARG MYSQL_PASSWORD

RUN apk update \
    && apk add php php-fpm php-mysqli \
    && mkdir /www

WORKDIR /www

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzvf latest.tar.gz \
    && mv wordpress/* . \
    && rm -r wordpress latest.tar.gz

COPY ./conf/www.conf /etc/php81/php-fpm.d/www.conf

COPY ./tools/config.sh /tmp/config.sh

RUN chmod 777 /tmp/config.sh

RUN /tmp/config.sh ${MYSQL_USER} ${MYSQL_PASSWORD}

CMD ["php-fpm81", "-F"]
