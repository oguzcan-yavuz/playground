echo "Enter a number between 10 and 20:\c"
read num
if [ $num -lt 10 ]
then
	echo "Number is under 10"
elif [ $num -gt 20 ]
then
	echo "Number is higher then 20"
else
	echo "Number is good"
fi
