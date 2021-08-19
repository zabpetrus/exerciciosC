"""

texto = "computação"
idade = 18
a = 0
b = 2
c = 1

if len(texto) > 10:
    print ("texto com mais de 10 caracteres")
else:
	print ("texto com 10 ou menos caracteres")

if (idade < 18): 
       print ("Não pode tirar carteira de habilitação")
else: 
    print ("Pode tirar a carteira de habilitação")

if (a > 0):
    if (b > 0):
        print ("Tudo ok para decolagem!")
    else:
        print ("Tanque principal vazio; voando com combustível reserva!")
else:
    if (c > 0):
        print ("Foguete não tem piloto, mas há outros foguetes disponíveis!")

"""

terminou = False
p = i = 0
while (not terminou):
    n = int(input("Digite um número, ou zero para terminar: "))
    if n == 0:
        terminou = True
    else:
        if n % 2 == 0:
            p = p + 1
        else:
            i = i + 1

print ("P = ", p)
print ("I = ", i)