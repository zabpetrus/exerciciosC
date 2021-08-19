"""
def fatorial( n ):
    prod = 1
    while(n > 0):
        prod = prod * n
        n-=1

    return prod


chamado = True
while(chamado):
    n = int(input("Entre com um numero: "))
    if(n <= 0):
        chamado = False
    else:
        print("Fatorial de", n,"=", fatorial(n))

"""
n = int(input("Digite um numero inteiro: "))
while n >= 0:
    fatorial = 1
    while n > 1:
        fatorial = fatorial * n
        n = n - 1
    print(fatorial)
    n = int(input("Digite um numero inteiro: "))
