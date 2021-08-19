def fat( n ):
    if(n > 1):
        return n * fat(n - 1)
    else:
        return 1

n = int(input("Digite o valor de n: "))
print(fat(n))