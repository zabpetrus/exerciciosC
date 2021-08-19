numeros = [10, 20, 30, 40]

foo = range(0, 100, 2)
bar = range(100, 1, -2)

for x in foo:
    print(x, end = ", ")
print()

for y in bar:
    print(y, end = ", ")
print()

animais = ["gato", "cachorro", "papagaio", "arara", "jacaré"]
for x in range(len(animais)):
    print("--> ", animais[x])

pares = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]
for x in range(5, 10):
    print(pares[x])

pares = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30]
for x in range(len(pares)):
    print(pares[x])

for i in range(16,4,-3):
	print("---", i)

valores = []
for i in range(1, 10):
    if i % 2 == 0:
        valores.append(i)
print("-->", valores)

valores = []
for i in range(1, 10, 2):
    valores.append(i)
print(valores)

alfabeto = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
print(alfabeto[:13])

letras = alfabeto[1:10]
print(letras)