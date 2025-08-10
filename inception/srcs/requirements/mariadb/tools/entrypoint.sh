#!/bin/bash

chown -R mysql:mysql /var/lib/mysql
mysql_install_db

sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|" /etc/mysql/mariadb.conf.d/50-server.cnf;
sed -i "s|#port|port |" /etc/mysql/mariadb.conf.d/50-server.cnf

/usr/share/mysql/mysql.server start

mysql -u root -p"$MARIADB_ROOT_PASSWORD" <<-EOSQL
	USE mysql;
	SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$MARIADB_ROOT_PASSWORD');
	CREATE DATABASE IF NOT EXISTS wordpress;
	CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';
	GRANT ALL PRIVILEGES ON wordpress.* TO '$MARIADB_USER'@'%' WITH GRANT OPTION;
	FLUSH PRIVILEGES;
EOSQL

/usr/share/mysql/mysql.server status
mysqladmin --user=root --password=$MARIADB_ROOT_PASSWORD shutdown

exec /usr/bin/mysqld_safe --datadir='/var/lib/mysql'