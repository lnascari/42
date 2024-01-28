#!/bin/sh

echo "CREATE DATABASE wp;" > /tmp/a.sql

mysqld_safe --init-file=/tmp/a.sql --user=root
