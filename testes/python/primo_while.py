execute = True

while execute:
    n = int(input("Entre com um numero: "))
    primo = True
    i = 2
    while(i < n):
        if(n % i == 0):
            primo = False
        i+=1

    if(n <= 0):
        print("Obrigado! ")
        execute = False
        break

    if(primo):
        print("O numero",n,"é primo. Próximo!\n")
    else:
        print("O numero",n,"não é primo. Próximo!\n")

    