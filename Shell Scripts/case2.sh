echo "Enter a word:\c"
read word
case $word in
[aeiou]* | [AEIOU]*)
			echo "The word begins with a vowel."
			;;
[0-9]*)
			echo "The word begins with a digit."
			;;
*[0-9])
			echo "The word ends with a digit."
			;;
???)
			echo "You entered three letter word."
			;;
*)
			echo "I don't know what you entered."
esac
