echo "Enter a name:\c"
read fname
if [ -f $fname ]
then
	echo "You indeed entered a file name"
else
	echo "Don't provide me crazy inputs lol"
fi
