#!/bin/sh
(export DIR=./gentoo; echo \#\!/bin/sh -e; cat /tmp/tar-stderr.txt | grep 'Cannot create symlink to' | sed -e 's7^tar: \.\([^:]\+\): Cannot create symlink to .\([^:]\+\).*$7\1:\27' -e "s7^\(.\+\)/\([^:]\+\):\(.\+\).\$7cd $DIR\1 \&\& cp \3 \2;7")
