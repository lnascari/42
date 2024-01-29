#!/bin/sh

cat << EOF > /tmp/init.sql
CREATE DATABASE wp;
GRANT ALL PRIVILEGES ON wp.* TO ${MYSQL_USER}@localhost IDENTIFIED BY '${MYSQL_PASSWORD}';

EOF

mysqld_safe --init-file=/tmp/init.sql --user=root
