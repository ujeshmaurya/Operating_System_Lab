c=1
while [ $c -lt 15 ]
do
	
	
	echo "Press 1 to execute the command ls"
	echo "Press 2 to execute the command mkdir"
	echo "Press 3 to execute the command rmdir"
	echo "Press 4 to execute the command clear"
	echo "Press 5 to execute the command cp"
	echo "Press 6 to execute the command rm"
	echo "Press 7 to execute the command touch"
	echo "Press 8 to execute the command locate"
	echo "Press 9 to execute the command chmod"
	echo "Press 10 to execute the command ll"
	echo "Press 11 to execute the command grep"
	echo "Press 12 to execute the command mv"
	echo "Press 13 to execute the command cd"
	echo "Press 14 to execute the command man"
	echo "Press 15 for exit"
 
	


	read c

	if [ $c -eq 1 ]; then
		ls


	elif [ $c -eq 2  ]; then
		echo "enter the directory name to create"
		read directory
		mkdir $directory

		
	elif [ $c -eq 3  ]; then
		echo "enter the directory name to remove"
		read directory
		rmdir $directory

	
	elif [ $c -eq 4  ]; then
		clear
	
	
	elif [ $c -eq 5  ]; then
		echo "Enter the source(ex-directory name(file name)) path"
		read sourc
		echo "Enter the destinetion(ex-directory name(file name)) path"
		read dest
		mv $sourc $dest


	elif [ $c -eq 6  ]; then
		echo "Enter the directory(file name) to remove the file"
		read directory
		rm $directory

	
	elif [ $c -eq 7  ]; then
		echo "Enter the directory name(file name) to create file"
		read directory
		touch $directory


	elif [ $c -eq 8  ]; then
		echo " Enter some pattern to search in your system"
		read something
		sudo updatedb
		locate $something
	
	
	elif [ $c -eq 9  ]; then
		echo "Enter the octal number ex(754) or permission(ex-u=rwx,g=rwx,o=rwx)"
		read num
		echo "Enter the path for ex-directory/directory/..../filename"
		read directory
		chmod $num $directory
		
		
	elif [ $c -eq 10  ]; then
		ls -la		


	elif [ $c -eq 11  ]; then
		echo "Enter a pattern to be matched"
		read pattern
		echo "Enter a directory(file name) in which you want to search pattern"
		read directory
		grep $pattern $directory

		
	elif [ $c -eq 12  ]; then
		echo "Enter the source(ex-directory name(file name)) path"
		read sourc
		echo "Enter the destinetion(ex-directory name) path"
		read dest
		mv $sourc $dest

				
	elif [ $c -eq 13  ]; then
		echo "Enter the directory name/directory name/... to enter inside the directory"
		read directory
		cd $directory


	elif [ $c -eq 14  ]; then
		echo "Enter the command to find manual of that command"
		read commd
		man $commd


	elif [ $c -eq 15 ]; then
		c=15	
	
	elif [ $c -gt 15  ]; then
		echo "INVALID INPUT !!!!! PLEASE ENTER A NUMBER FROM 1 to 15"
	
	elif [ $c -gt 15  ]; then
		echo "INVALID INPUT !!!!! PLEASE ENTER A NUMBER FROM 1 to 15"
	fi
    
    #read c
done
