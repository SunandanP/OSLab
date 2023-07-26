#!bin/bash

# creation of address book
exit=0
fileOP=addr.txt
name=""

while [[ $exit -ne 0 ]]
	do
		echo Enter a name : 
		read name
		name > fileOP
		
		echo "continue? (0/1)"
		read exit
	done
echo exited
