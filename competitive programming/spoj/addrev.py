n = int(input(""))

for _ in range(n):
  n_1, n_2 = input("").split(" ")
  n_1 = int(n_1[::-1])
  n_2 = int(n_2[::-1])
  print(int(str(n_1 + n_2)[::-1]))
