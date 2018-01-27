ngx_http_set_hash_module
========================

Description
===========

This module allows you to set the hash (as a hexadecimal string) of an arbitrary
string as the value of a variable.  Currently only three are available (MD5, SHA1
and Murmurhash2 (32-bit)), but more will be added later.


Usage
=====

set_[hash]          $var_name   [value]
set_[hash]_upper    $var_name   [value]

[hash] ::= md5 | sha1 | murmur2 (more to be added soon)
[value] is any legal string value in Nginx, including variables



Uppercase or lowercase?
=======================

The suffix '_upper' indicates that the output should be in uppercase, otherwise any
letters are displayed in lowercase.

Note : unless you have a good reason to use uppercase, you should use lowercase because
the conversion to uppercase adds overhead.



Example
=======

log_format  hashes  "value : $hash_value  "
                    "md5 : $md5 $md5_upper  "
                    "murmur2 : $murmur2 $murmur2_upper  "
                    "sha1 : $sha1 $sha1_upper";

access_log  /var/log/hashes.log  hashes;

server {

    location / {

        set                     $hash_value         $request_uri;

        set_md5                 $md5                $hash_value;
        set_murmur2             $murmur2            $hash_value;
        set_sha1                $sha1               $hash_value;

        set_md5_upper           $md5_upper          $hash_value;
        set_murmur2_upper       $murmur2_upper      $hash_value;
        set_sha1_upper          $sha1_upper         $hash_value;
    }
}

This will log the md5/murmurhash 2/sha hash values of $request_uri to the log file.



Installation
============

To install, you must compile Nginx with OpenSSL and the Nginx Development Kit

./configure \
    --add-module=/path/to/ngx_devel_kit \
    --add-module=/path/to/ngx_http_set_hash
make
make install


Note : If Nginx can't find your system's OpenSSL shared libraries and headers, you
will either want to install the devel version using your package manager, e.g.

apt-get/yum install openssl-dev

or specify a path to a directory where you have extracted the OpenSSL source code :

./ configure --with-openssl=/path/to/openssl ...


Note : This module will work ok with the latest version of Agentzh's set_misc module,
and the result will be the same.


TODO
====

- More hash functions


License
=======

BSD


Copyright
=========

Marcus Clyne (c) 2010
