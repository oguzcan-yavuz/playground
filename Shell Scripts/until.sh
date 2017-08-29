#same as while, only difference is this shell won't show 10. 
#because this is until, while is while.
count=1
until [ $count -ge 10 ]
do
	echo $count
	count=`expr $count + 1`
done
