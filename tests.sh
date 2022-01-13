#!/bin/zsh
for i in {10..400..10}; do
	for d in {3..9}; do
		python fast_generator.py 10 $i graph 0."$d"
		make clean
		make
		/usr/bin/time -a -o "$d"times.txt sh bis_test.sh
	done
done

for i in {4..9}; do
	cat "$i"times.txt | awk '{print $1}' | tr ',' '.' | tr '\n' ',' >> displaying.py
done
