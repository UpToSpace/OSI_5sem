#!/bin/bash
if [ "$1" = "" ]; then 
	echo theres no params
	exit
	fi
if ! [[ "$1" =~ ^[[:digit:]]+$ ]]; then 
	echo pid = $1 is not an int
	exit
	fi
if test -d /proc/"$1"/; then
	echo Name: $(ps -p $1 -o comm=)
	echo Pid: $1
	echo PPid: $(ps -o ppid= -p $1)
		if [ "$2" = "fd" ]; then
			for i in $(ls -l /proc/$1/fd | awk '{print $9}')
			do 
			echo "fd = "$i
			done
		fi 
else 
	echo pid = $1 process not found
	exit
fi


