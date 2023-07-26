#!/bin/bash

# sum of first 40 natural numbers

sumation=0

for (( i=1; i<=40; i++))
do
	((sumation = sumation + i))
done

echo sumation of first 40 natural numbers : $sumation

#statement 2

negative=0

number=0

sumA=0
while [[ $number -ge 0 ]]
	do
		
		(( sumA = sumA + number))
		echo "Enter the number"
		read number
		echo $number
	done	
	echo $sumA	
