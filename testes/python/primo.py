n = int(input("Digite um número inteiro: "))
i = 2
nprimo = True

while((i < n) and (nprimo)):
    if(n % i == 0):
        nprimo = False    
    i+=1

if(nprimo):
    print("primo")
else:
    print("não primo")