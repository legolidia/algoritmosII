num = input()

for i in range(len(num)-1, -1, -1):
    print(num[i], end="")
    if i==0:
        print(" ", end="")

print()
