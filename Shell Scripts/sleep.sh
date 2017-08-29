echo "Enter a sentence:\c"
read str

while true
do
	for word in $str
	do
		figlet $word
		sleep 1
	done
done
