#!/bin/bash

for i in $(find carteado -type f -name '*.cpp'); do 
	objs+=" "
	__obj=$(echo $i | cut -f 1 -d '.').o
	echo g++ -c $i -std=c++1y -Wall -Werror -Wshadow -o $__obj
	g++ -c $i -std=c++1y -Wall -Werror -Wshadow -o $__obj
	objs+=$__obj
done

echo ar rcs libcarteado.a $objs
ar rcs libcarteado.a $objs


