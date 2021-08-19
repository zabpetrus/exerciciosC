def leitura1():
    x = -1
    while x <= 0:
        x = int(input("Digite o valor: "))
    return x

def leitura2():
    x = int(input("Digite um valor: "))
    while x <= 0:
        x = int(input("Digite um valor: "))
    return x

def troca(x, y):
    aux = x
    x = y
    y = aux

x = 10
y = 20
troca (x,y)
print("x =", x,"e y =",y)