c=1
while [ $c -lt 15 ]
do
	
	
	echo "Press 1 to execute the command ls"
	echo "Press 2 to execute the command mkdir"
	echo "Press 3 to execute the command rmdir"
	echo "Press 4 to execute the command clear"
	echo "Press 5 to execute the command mv"
	echo "Press 6 to execute the command rm"
	echo "Press 7 to execute the command touch"
	echo "Press 8 to execute the command locate"
	echo "Press 9 to execute the command chmod"
	echo "Press 10 to execute the command ll"
	echo "Press 11 to execute the command grep"
	echo "Press 12 to execute the command cp"
	echo "Press 13 to execute the command cd"
	echo "Press 14 to execute the command man"
	echo "Press 15 for exit"
 
	


	read c
	
	if [ $c -eq 1 ]; then
		c1=1
		while [ $c1 -ne 0 ]
		do
			echo "Do you want use any option with ls command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				echo "1) -a (for all)"
				echo "2) -A (for Almost all)"
				echo "3) -l (for long list format)"
				echo "4) -al (for all long list format)"
				echo "5) -B (not to show the backup files)"
				echo "6) -d (to show only directories)"
				echo "Select the option which you want to use"
				read cr
				case $cr in
					1) ls -a ;;
					2) ls -A ;;
					3) ls -l ;;
					4) ls -al ;;
					5) ls -B ;;
					6) ls -d ;;
					*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 7" ;;
				esac
			elif [ "$alpha" = "n" ]; then
				ls
			elif [ "$alpha" = "q" ]; then
				c1=0
			else
				echo "Error!!!!"
				c1=0;
			fi
		done
		
	elif [ $c -eq 2  ]; then
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the directory name to create"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			echo "Do you want use any option with mkdir command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -m (for set the mod)"
					echo "2) -v (print a message for each created directory)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) echo "Enter the mode in octal ex-(777)" 
							read mo
							mkdir --mode=$mo $directory 
							#flag=1
							i=0 ;;
						2) mkdir -v $directory 
							#flag=1 
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 2" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				mkdir $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done

		
	elif [ $c -eq 3  ]; then
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the directory name to remove"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			echo "Do you want use any option with rmdir command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -v (print a message for each created directory)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) rmdir -v $directory 
							#flag=1 
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 1" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				rmdir $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done

		

	
	elif [ $c -eq 4  ]; then
		clear
	
	
	elif [ $c -eq 5  ]; then
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the source(ex-directory name/file name) path"
			echo "Press q for quit"
			read sourc
			
			if [ "$sourc" = "q" ]; then
				break
			fi
			
			echo "Enter the destinetion(ex-directory name/file name) path"
			echo "Press q for quit"
			read dest
			
			if [ "$dest" = "q" ]; then
				break
			fi
			
			echo "Do you want use any option with mv command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -f (Do not prompt before overwriting)"
					echo "2) -i (prompt before overwriting)"
					echo "3) -n (Do not overwriting an existing file )"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) 	mv -f $sourc $dest
							#flag=1
							i=0 ;;
						2) mv -i $sourc $dest 
							#flag=1 
							i=0 ;;
						3) mv -n $sourc $dest
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 3" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				mv $sourc $dest
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done
		


	elif [ $c -eq 6  ]; then
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the directory(file name) ex-(directory name/..../file name) to remove the file"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			echo "Do you want use any option with rm command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -f (ignore nonexistent files and arguments, never prompt)"
					echo "2) -i (prompt before every removal)"
					echo "3) -d (prompt before every removal)"
					echo "4) -v (prompt before every removal)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) rm -f $directory 
							#flag=1
							i=0 ;;
						2) rm -i $directory 
							#flag=1 
							i=0 ;;
						3) rm -d $directory
							i=0 ;;
						4) rm -v $directory
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 4" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				rm $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done
	
	elif [ $c -eq 7  ]; then
		
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the directory(file name) ex-(directory name/..../file name) to create the file"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			echo "Do you want use any option with touch command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -a (Change only the access time)"
					echo "2) -c (Do not create any files)"
					echo "3) -r (use this file's times instead of current time)"
					echo "4) -m (change only the modification time)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) touch -a $directory 
							#flag=1
							i=0 ;;
						2) touch -c $directory 
							#flag=1 
							i=0 ;;
						3) touch -r $directory
							i=0 ;;
						4) touch -m $directory
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 4" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				touch $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done


	elif [ $c -eq 8  ]; then
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo " Enter some pattern(or file name or directory name) to search in your system"
			echo "Press q for quit"
			read something
			sudo updatedb
			if [ "$something" = "q" ]; then
				break
			fi
			echo "Do you want use any option with locate command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -A (Print only entries that match all PATTERNs instead of requiring only one of them to match.)"
					echo "2) -c (Print only entries that match all PATTERNs instead of requiring only one of them to match.)"
					echo "3) -i (Ignore case distinctions when matching patterns.)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) locate -A $something 
							#flag=1
							i=0 ;;
						2) locate -c $something 
							#flag=1 
							i=0 ;;
						3) locate -r $something
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 4" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				locate $something
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done
	
	
	elif [ $c -eq 9  ]; then


		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the octal number ex(754) or permission(ex-u=rwx,g=rwx,o=rwx) to give permission"
			echo "Press q for quit"
			read num
			if [ "$num" = "q" ]; then
				break
			fi
			echo "Enter the path for ex-directory/directory/..../filename"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			echo "Do you want use any option with touch command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -c (like verbose but report only when a change is made)"
					echo "2) -v (output a diagnostic for every file processed)"
					echo "3) -f (suppress most error messages)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) chmod -c $num $directory 
							#flag=1
							i=0 ;;
						2) chmod -v $num $directory 
							#flag=1 
							i=0 ;;
						3) chmod -f $num $directory
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 4" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				chmod $num $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done
		
		
		
	elif [ $c -eq 10  ]; then
		ls -la		


	elif [ $c -eq 11  ]; then
	
		
		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter a pattern to be matched"
			echo "Press q for quit"
			read pattern
			if [ "$pattern" = "q" ]; then
				break
			fi
			echo "Enter the path for ex-directory/directory/..../filename"
			echo "Press q for quit"
			read directory
			if [ "$directory" = "q" ]; then
				break
			fi
			
			echo "Do you want use any option with grep command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -v (Invert the sense of matching, to select non-matching lines.)"
					echo "2) -c (count non-matching lines)"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) grep -v $pattern $directory
							#flag=1
							i=0 ;;
						2) grep -c $pattern $directory 
							#flag=1 
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 2" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				grep $pattern $directory
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done
		

		
	elif [ $c -eq 12  ]; then

		c2=1
		#flag=1
		while [ $c2 -ne 0 ]
		do
			echo "Enter the source(ex-directory name/file name) path"
			echo "Press q for quit"
			read sourc
			
			if [ "$sourc" = "q" ]; then
				break
			fi
			
			echo "Enter the destinetion(ex-directory name/file name) path"
			echo "Press q for quit"
			read dest
			
			if [ "$dest" = "q" ]; then
				break
			fi
			
			echo "Do you want use any option with mv command [y/n]"
			echo "Press q for quit"
			read alpha
			if [ "$alpha" = "y" ]; then
				i=1;
				while [ $i -eq 1 ]
				do
					echo "1) -f (prompt before overwrite (overrides a previous -n option))"
					echo "2) -i (prompt before overwrite (overrides a previous -n option))"
					echo "3) -n (prompt before overwrite (overrides a previous -n option))"
					echo "Select the option which you want to use"
					read cr
					case $cr in
						1) cp -f $sourc $dest
							#flag=1
							i=0 ;;
						2) cp -i $sourc $dest 
							#flag=1 
							i=0 ;;
						3) cp -n $sourc $dest
							i=0 ;;
						*) echo "INVALID INPUT !!!!!! Please Enter The choice from 1 to 3" 
						    #flag=0 
						    i=1 ;;
					esac
				done
			elif [ "$alpha" = "n" ]; then
				cp $sourc $dest
			elif [ "$alpha" = "q" ]; then
				c2=0
			else
				echo "Error!!!!"
				c2=0;
			fi
		done

				
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
	elif [ $c -lt 1  ]; then
		echo "INVALID INPUT !!!!! PLEASE ENTER A NUMBER FROM 1 to 15"
	fi
    
done
