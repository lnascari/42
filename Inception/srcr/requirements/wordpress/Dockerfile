FROM alpine:3.18.5

RUN apk update \
    && apk add php php-fpm \
    && mkdir /www

WORKDIR /www

RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzvf latest.tar.gz \
    && mv wordpress/* . \
    && rm -r wordpress latest.tar.gz

COPY ./conf/www.conf /etc/php81/php-fpm.d/www.conf

CMD ["php-fpm81", "-F"]
