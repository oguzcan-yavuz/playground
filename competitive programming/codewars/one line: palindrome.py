palindrome=lambda n,c:(c+c[-1-n%2::-1]).center(n,c[0])

print(palindrome(3, "ab"))
print(palindrome(20, "abcd"))
