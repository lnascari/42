#!/bin/sh

cat << EOF > /www/wp-config.php
<?php
define( 'DB_NAME', 'wp' );
define( 'DB_USER', '$1' );
define( 'DB_PASSWORD', '$2' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define( 'WP_DEBUG', true );
\$table_prefix = 'wp_';
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
EOF
