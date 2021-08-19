
print("********** Tabuada 1 **************")
def tabuada():
    # parte faltante
    tab = 1
    while tab <= 10:
        print("Tabuada do", tab, ":", end="\t")
        i = 1
        while i <= 10:
            print(tab*i, end = "\t")
            i = i + 1
        
        tab = tab + 1
        print("\n")


tabuada()

print("********** Tabuada 2 **************")

def tabuada2():
    tab = 0
    while tab < 10:
        tab = tab + 1
        i = 0
        while i < 10:
            i = i + 1
            print(tab,"x",i,"=",tab*i)
        print()

tabuada2()

print("********** Tabuada 3 **************")

def tabuada3():
    tab = 1
    while tab <= 10:
        i = 1
        while i <= 10:
            print(tab,"x",i,"=",tab*i)
            i = i + 1
        print()
        tab = tab + 1

tabuada3()

print("********** while1 **************")

def whileone():
    x = 1
    cont = 0
    while x < 3:
        y = 0
        while y <= 4:
            # Iteração
            cont += 1
            y = y + 1
        x = x + 1
    print(cont)

whileone()

print("********** while 2 **************")

def whiletwo():
    fora = 5
    while fora > 0:
        dentro = 0
        while dentro < fora:
            print("oi", end="\t")
            dentro = dentro + 1
        fora = fora - 1
    print()

whiletwo()

print("*********** while 3 **************")

def whilesan():
    x = 2
    cont = 0
    while x >= 0:
        y = 0
        while y >= 4:
            #comando qualquer
            cont += 1
            y = y + 1
        x = x - 1

    print(cont)

whilesan()

print("*************** while4 *****************")

def whilefour(): 
    x = 2
    cont = 0
    while x >= 0: #x = 2 v
        y = 0
        while y <= 4: #v
            print("Foo")
            cont += 1
            #comando qualquer
            y = y + 1 #o certo eo + aqui. Dá loop infinito com o sinal de -
        x = x - 1
    

whilefour()

print("*************** while5 *****************")

i = 0
while i < 3:
    j = 0
    while j < 3:
        print(3 * i + j + 1, end=" ")
        j = j + 1
    i = i + 1