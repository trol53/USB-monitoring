#! /bin/bash

snmpinform -v 2c -c public $4:$5   "" 1.3.3.3.3.3.3.3 1.2.2.2.2.2.2 s "Id Product:$1\nDevice type:$2\nVendor:$3"

