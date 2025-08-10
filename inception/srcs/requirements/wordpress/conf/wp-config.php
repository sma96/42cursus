<?php

define( 'DB_NAME', getenv('MARIADB_DB'));
define( 'DB_USER', getenv('MARIADB_USER'));
define(	'DB_PASSWORD', getenv('MARIADB_PASSWORD'));
define(	'DB_HOST', 'mariadb');
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );


define('AUTH_KEY',         '{|4dh|W2Aj(PTQ3)ikx+HWhK03/J*!,XVdw|-SH@#}0Q+-,mmY;?}LK#SG;W#;#w');
define('SECURE_AUTH_KEY',  '_x]s<YV.08B*Un^a~_C@#[y>-, E5bn^X~J? ZYS<<X_4lJcQc1XO%=JDum2q-86');
define('LOGGED_IN_KEY',    'KDXSBc`B?bh7*_.@0]x1WEE_)dq!UT>HjRmHt5`<FBUcW1i&<bdb@q:9#u~|<Dwh');
define('NONCE_KEY',        'cz)%-_P[|L]-|dbFj)Q!7(CA<ZaPacdgjxP:;ET%I~}(B-tI0)kdW!hq&4C%2XWh');
define('AUTH_SALT',        '}9X@[+UiF;9=H#nL$lZ0IohpB2tCzmTW,0Rbd #wyd=KG(8(kKQGg#q>N[}H?2sQ');
define('SECURE_AUTH_SALT', '-veFcR*^#N&2_nv)5CLuYHto@nY*/~v#m0]+1z-<$]?{zJhcMu-5?s]M6DGZ*U_$');
define('LOGGED_IN_SALT',   '*f4=^iaZDiSGAh_f.=-f2,Txoccev|_Hxsw&w,uga-$M$xyrNA`l`N-Rpk?tB6R-');
define('NONCE_SALT',       'U}mt2Y0>y^r>=+yl]YA`{Za^vi}Fm^Z *{QP-t`<*B^c|UgttT);>|G[ZWT3Yw9E');


$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */
/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

define('CONCATENATE_SCRIPTS', false);

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
