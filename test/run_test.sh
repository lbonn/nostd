#!/bin/sh

for c in *.c; do
    EXE=${c%.*}
    echo -n "running ${EXE}: "
    ./${EXE} > /dev/null
    if [[ $? = 0 ]]; then
        echo "SUCCESS"
    else
        echo "FAILURE"
    fi;
done;
