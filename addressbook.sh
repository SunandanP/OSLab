#! /bin/bash

# Name, address

close=0

file="addr.txt"

touch "$file"

while [[ $close -ne 1  ]]
do
	echo "Welcome to addressbook"
	echo "Select an option from the list below"
	
	echo "1. Create Address Book"
	echo "2. View Address Book"
	echo "3. Insert a Record"
	echo "4. Delete a Record"
	echo "5. Modify a record"
	echo "6. Exit"
	
	read input
	
	case $input in 
		1)
		echo "Enter the name for address book : "
		read file
		touch "$file"
	
		
		;;
		
		2)
		cat "$file.txt"
	
		
		;;
		
		3)
		echo "Enter the name of the person : "
		read personName
		echo "Enter the address : "
		read addr
	
		echo "$personName $addr" >> "$file.txt"
	
		;;
		
		4)
		echo "Enter the name of the person for deleting the record : "
		read personName
		
		sed -i "/$personName/d" "$file.txt"
		
		echo "successfully deleted!"
		cat "$file.txt"
		;;
		
		5)
		echo "Enter the name of the person whose record is to be modified : "
		read personName
		
		echo "Enter the new address : "
		read newAddr
		
		sed -i "/$personName/c\ $newAddr" "$file.txt"
		;;
		
		6)
		break
		;;
		
		*)
		echo "Invalid input"
		;;
		
		esac
		
done

echo 'closed'
