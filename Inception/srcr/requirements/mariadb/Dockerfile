FROM alpine:3.18.5

RUN apk update \
    && apk add mysql mysql-client \
    && chown -R mysql:mysql /var/lib/mysql \
    && mysql_install_db --datadir=/var/lib/mysql \
    && mkdir /run/mysqld \
    && chown -R mysql:mysql /run/mysqld

COPY ./tools/setup.sh /tmp/setup.sh

CMD ["/tmp/setup.sh"]
