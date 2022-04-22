#!/bin/bash

LOG_DIR=logs


diff_test()
{
	g++ -std=c++98 $1
	if [[ ! -e a.out ]]
	then
		tput setaf 1
		echo -n Compilation failed.
		tput setaf 7
		echo " -$1"
		rm a.out 2> /dev/null
		return
	fi
	./a.out &> ft.txt ; rm a.out
	g++ $1 -std=c++98 -D STD=
	if [[ ! -e a.out ]]
	then
		tput setaf 1
		echo -n Compilation failed.
		tput setaf 7
		echo " -$1"
		rm a.out 2> /dev/null
		return
	fi
	./a.out &> std.txt ; rm a.out
	diff ft.txt std.txt > diff.txt
	if [ -z "$(cat diff.txt)" ]
	then
		tput setaf 2
		echo -n OK
		tput setaf 7
	else
		tput setaf 1
		echo -n KO
		tput setaf 7
	fi
}

if [ ! -d $LOG_DIR ]
then
	echo "Log folder: $LOG_DIR"
	mkdir $LOG_DIR
else
	rm -r $LOG_DIR/*
fi

for FILE in *.cpp;
do
	TEST_NAME=${FILE%.cpp}
	LOG_THIS=$LOG_DIR'/'$TEST_NAME

	echo $FILE
	if [ ! -d $LOG_THIS ]
	then
		mkdir $LOG_THIS
	else
		rm -r $LOG_THIS/*
	fi
	cd $LOG_THIS
	diff_test $OLDPWD'/'$FILE
	cd - > /dev/null
	echo " -$TEST_NAME"
done;
