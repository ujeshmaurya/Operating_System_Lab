NUM=1
while [ $NUM -lt 15 ]
do
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "=================================================="
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "                Welcome to Shell                  "
    echo "         Enter a number between 1 and 15.         "
	echo "Press 1: for list of all items in current directory"					#ls
	echo "Press 2: for changing the current directory"							#cd
	echo "Press 3: for locating a file"											#locate
	echo "Press 4: to clear terminal screen"									#clear
	echo "Press 5: for creating a new file"										#touch
	echo "Press 6: for moving a file"											#mv
	echo "Press 7: for deleting an empty folder"								#rmdir
	echo "Press 8: for changing mode/permissions of a file"						#chmod
	echo "Press 9: to search for a pattern in a file"							#grep
	echo "Press 10: for list of all items in current directory(with details)"	#ll
	echo "Press 11: for manual page of any command"								#man
	echo "Press 12: for copying a file"											#cp
	echo "Press 13: for removing a file"										#rm
	echo "Press 14: for creating a new directory/folder"						#mkdir
	echo "Press 15: to exit the Shell"											#break while loop
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "=================================================="
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++"
	read NUM

	case $NUM in
		1) echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				ls "$options"
		   else
				ls
		   fi ;;

		2) echo "Enter a directory name or '..' for previous directory"
		   read directory
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				cd "$options" "$directory"
		   else
				cd "$directory"
		   fi ;;

		3) echo "Enter something to search"
		   read directory
		   #sudo updatedb
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				locate "$options" "$directory"
		   else
				locate "$directory"
		   fi ;;

		4) clear ;;

		5) echo "Enter a directory(with filename) to create file"
		   read directory
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				touch "$options" "$directory"
		   else
				touch "$directory"
		   fi ;;

		6) echo "Enter the source path"
		   read src
		   echo "Enter the destination path"
		   read dest
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				mv "$options" "$src" "$dest"
		   else
				mv "$src" "$dest"
		   fi ;;

		7) echo "Enter a directory to remove"
		   read directory
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				rmdir "$options" "$directory"
		   else
				rmdir "$directory"
		   fi ;;

		8) echo "Enter a 3 digit octal value for granting permission"
		   echo "You can also enter in this format {u=rwx,g=rwx,o=rwx}"
		   read octal
		   echo "Enter a directory(with filename)"
		   read directory
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				chmod "$options" "$octal" "$directory"
		   else
				chmod "$octal" "$directory"
		   fi ;;

		9) echo "Enter a pattern to search"
		   read pattern
		   echo "Enter a directory(with filename)"
		   read directory
		   echo "If you want to add any options press 1, otherwise 0"
		   read choice
		   if [ $choice -eq 1 ]
		   then
				echo "Enter options in a single line"
				read options
				grep "$options" "$pattern" "$directory"
		   else
				grep "$pattern" "$directory"
		   fi ;;

		10) ls -la ;;

		11) echo "Enter something to search"
		    read interface
		    echo "If you want to add any options press 1, otherwise 0"
		    read choice
		    if [ $choice -eq 1 ]
		    then
				echo "Enter options in a single line"
				read options
				man "$options" "$interface"
		    else
				man "$interface"
		    fi ;;


		12) echo "Enter the source path"
		    read src
		    echo "Enter the destination path"
		    read dest
		    echo "If you want to add any options press 1, otherwise 0"
		    read choice
		    if [ $choice -eq 1 ]
		    then
				echo "Enter options in a single line"
				read options
				cp "$options" "$src" "$dest"
		    else
				cp "$src" "$dest"
		    fi ;;

		13) echo "Enter a directory(with filename) to delete"
		    read directory
		    echo "If you want to add any options press 1, otherwise 0"
		    read choice
		    if [ $choice -eq 1 ]
		    then
				echo "Enter options in a single line"
				read options
				rm "$options" "$directory"
		    else
				rm "$directory"
		    fi ;;

		14) echo "Enter a name to create directory"
		    read name
		    echo "If you want to add any options press 1, otherwise 0"
		    read choice
		    if [ $choice -eq 1 ]
		    then
				echo "Enter options in a single line"
				read options
				mkdir "$options" "$name"
		    else
				mkdir "$name"
		    fi ;;

		15) echo "Exiting Shell.." ;;

		*) echo "INVALID NUMBER!" ;;

	esac
done
