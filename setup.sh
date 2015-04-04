# Shell2shell Install script 
# Created By  Akram Abed-Eslem Chaima 
# Under GPL 
#!/bin/bash
echo "Welcome .. install shell2shell "
echo "Installing ...."
gcc -o shell2shell src/shell2shell.c
cp  shell2shell /usr/bin/

file="/usr/bin/shell2shell"
if [ -f "$file" ]
then
        echo "---------------------------"
	echo "Done ! "
else
        echo "---------------------------"
	echo "Error Install ! "
fi

