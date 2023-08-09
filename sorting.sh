#! /bin/bash

index_array=(1 2 3 4 5 6 7 8 9 0)

for i in ${index_array[@]}
do
        echo $i
done

for ((i=0; i < ${#index_array[@]}; i++))
do
	for ((j=0; j < ${#index_array[@]}; j++))
	do
		if [ ${index_array[$i]} >  ${index_array[((i+1))]} ]; 
		then
			if [ ${i+1} <= ${#index_array[@]}	 ]
			 index_array[$i]=${index_array[i+1]}
		fi		
	done
done

for i in ${index_array[@]}
do
        echo $i
done
