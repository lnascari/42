FROM alpine:3.18.5

RUN apk update \
    && apk add nginx openssl \
    && adduser -D -g 'www' www \
    && mkdir /www \
    && chown -R www:www /www \
    && mkdir /etc/nginx/ssl \
    && openssl req -x509 -newkey rsa:2048 -keyout /etc/nginx/ssl/key.pem -out /etc/nginx/ssl/cert.pem -sha256 -days 365 -nodes -subj "/CN=localhost"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
