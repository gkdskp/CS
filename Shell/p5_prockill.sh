#! /bin/sh

# Shell script which starts on system boot up and kills every process which uses more
# than a specified amount of memory or CPU.

cuser="gokul"
memlimit=3.5;
cpulimit=4.0;
while ( true )
do
    echo "Script running .."
    ps -e -o  pmem=,pcpu=,pid=,user=,comm= --sort=-pmem |
    while read size cpu pid user comm
    do
        kill_mem=0
        kill_cpu=0
        if [ $user = $cuser ]
        then
            kill_mem=`echo "$size>$memlimit" | bc `
            kill_cpu=`echo "$cpu>$cpulimit" | bc `
            if [ $kill_mem = "1" ]
            then
                echo " process with PID $pid killed "
                kill $pid
            elif [ $kill_cpu = "1" ]
            then
                echo " process with PID $pid killed "
                kill $pid
            else
                continue
            fi
        fi
    done
    sleep 1
done
