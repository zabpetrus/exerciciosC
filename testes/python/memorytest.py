lista1 = ["carro", "ônibus", "barco", "bicicleta"]
lista2 = ["carro", "ônibus", "barco", "bicicleta"]
lista3 = ["carro", "barco"]

# print(lista1 == lista2)

# print(lista1 is lista3)

# print(lista3 is lista2)

# print(lista1 is lista2)

lista1 = ["carro", "barco"]
lista2 = [["carro", "barco"], ["carro", "barco"], ["carro", "barco"]]
lista3 = ["carro", "barco", "carro", "barco", "carro", "barco"]
lista1[1] = "metrô"

print(lista1)
print(lista2)
print(lista3)
print(lista1)

print("****************")

lista1 = ["carro", "barco"]
lista2 = [lista1] * 3
lista3 = lista1 * 3
lista1[1] = "metrô"

print(lista1)
print(lista2)
print(lista3)


