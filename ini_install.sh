#!/bin/sh
INI_FILE=`php-config --ini-dir`/daytime.ini
cp daytime.ini $INI_FILE
echo "installed $INI_FILE"
