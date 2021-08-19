l = int(input("digite a largura: "))
a = int(input("digite a altura: "))

i = j = 0
while(i < a):
    while(j < l): 
        if((j == 0) or (j == l-1) or (i == 0) or (i == a - 1)):
            print("#", end = "")
        else:
            print(" ", end = "")

        j += 1
    print()
    j = 0
    i += 1
