FROM alpine:3.18.5

RUN apk update \
    && apk add php php-fpm \
    && mkdir /www

COPY ./conf/www.conf /etc/php81/php-fpm.d/www.conf

CMD ["php-fpm81", "-F"]
