#! /bin/bash

# pallindrome 

echo Enter a word to be checked if the word is pallindroem or not
read word

len=${#word}
rev=""
for ((i=$len - 1; i >= 0; i--))
do
	rev="$rev${word:$i:1}"	
done


if [ $rev = $word ]; then
	echo String is pallindrome
else
	echo String is not a pallindrome
fi	


