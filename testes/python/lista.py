"""
finish = False
lista = []

while(not finish):
    n = int(input("Entre com um numero: "))
    if(n > 0 and n % 10 == 0):
        lista.append(n)
        print("Proximo! ")

    else:

        if(n <= 0):
            print("Obrigado")
            finish = True
        else:
            print("Numero não permitido. Somente multiplos de 10. Próximo!")

# lista.reverse()
print(lista)

print(lista[4])
print(lista[-1])

"""


flores = ["margarida", "rosa", "tulipa", "cravo"]
tam = len(flores) - 1
while tam >= 0:
    print(flores[tam], end=", ")
    tam = tam - 1

teste = ["Elvis", 64, "Beatles", 10]
teste[1] = teste[1] + 6

print(type(teste[2]))