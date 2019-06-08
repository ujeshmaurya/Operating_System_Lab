NUM=1
while [ $NUM -lt 15 ]
do
    echo "Enter a number between 1 and 15. "
	echo "Enter 1 for ls"
	echo "Enter 2 for cd"
	echo "Enter 3 for locate"
	echo "Enter 4 for clear"
	echo "Enter 5 for touch"
	echo "Enter 6 for mv"
	echo "Enter 7 for rmdir"
	echo "Enter 8 for chmod"
	echo "Enter 9 for grep"
	echo "Enter 10 for ll"
	echo "Enter 11 for man"
	echo "Enter 12 for cp"
	echo "Enter 13 for rm"
	echo "Enter 14 for mkdir"
	echo "Enter 15 to exit the shell"
	
	read NUM

	case $NUM in
		1) ls ;;
		
		2) echo "Enter a directory" 
		   read directory
		   cd "$directory";;
		   
		3) echo "Enter something to search" 
		   read directory
		   sudo updatedb
		   locate "$directory";;
		   
		4) clear ;;
		
		5) echo "Enter a directory(with filename) to create file" 
		   read directory
		   touch "$directory";;
		   
		6) echo "Enter the source path"
		   read src
		   echo "Enter the destination path" 
		   read dest
		   mv "$src" "$dest";;
		   
		7) echo "Enter a directory to remove" 
		   read directory
		   rmdir "$directory";;
		   
		8) echo "Enter a 3 digit octal value for granting permission"
		   read octal
		   echo "Enter a directory(with filename)" 
		   read directory
		   #oct=obase=8;$octal | bc
		   chmod "$octal" "$directory";;
		   
		9) echo "Enter a pattern to search"
		   read pattern
		   echo "Enter a directory(with filename)" 
		   read directory
		   grep "$pattern" "$directory";;
		   
		10) ls -la ;;
		
		11) echo "Enter something to search" 
		    read interface
		    man "$interface";;
		    
		12) echo "Enter the source path"
		    read src
		    echo "Enter the destination path" 
		    read dest
		    cp "$src" "$dest";;
		    
		13) echo "Enter a directory(with filename) to delete" 
		    read directory
		    rm "$directory";;
		    
		14) echo "Enter a name to create directory" 
		    read name
		    mkdir "$name";;
		    
		15) echo "Exiting Shell Script" ;;
		
		*) echo "INVALID NUMBER!" ;;
		
	esac
done
