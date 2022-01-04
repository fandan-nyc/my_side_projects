#!/bin/bash

db_set() {
    echo "$1,$2" >> database
}

db_get() {
    grep "^$1," database | sed -e "s/^$1,//" | tail -n 1
}

db_set 123 456
db_get 123
db_set 123 457
db_get 123
