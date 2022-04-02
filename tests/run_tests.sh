#!/bin/bash

diff_test()
{
	g++ $1
	if [[ ! -e a.out ]]
	then
		tput setaf 1
		echo -n Compilation failed.
		tput setaf 7
		echo " -$file"
		rm a.out 2> /dev/null
		return
	fi
	./a.out &> $file.logs/ft.txt ; rm a.out
	g++ $1 -D STD=
	if [[ ! -e a.out ]]
	then
		tput setaf 1
		echo -n Compilation failed.
		tput setaf 7
		echo " -$file"
		rm a.out 2> /dev/null
		return
	fi
	./a.out &> $file.logs/std.txt ; rm a.out
	if [ -z "$(diff $file.logs/ft.txt $file.logs/std.txt)" ]
	then
		tput setaf 2
		echo -n OK
		tput setaf 7
	else
		tput setaf 1
		echo -n KO
		tput setaf 7
	fi
	echo " -$file"
}

for file in *.cpp;
do
	rm -rf $file.logs >/dev/null
	mkdir -p $file.logs >/dev/null
	diff_test $file
	#rm ft.txt std.txt
done;
