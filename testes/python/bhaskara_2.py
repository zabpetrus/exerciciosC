import math

def delta(a, b, c):
    t = ( b ** 2 ) - 4 * a * c
    return t

def main():

    a = int(input())
    b = int(input())
    c = int(input())

    d = delta(a, b, c)

    if(d > 0):

        x1 = ((-1 * b) + math.sqrt(d) ) / (2 * a)
        x2 = ((-1 * b) - math.sqrt(d) ) / (2 * a)

        if(x1 > x2):
            print("as raízes da equação são", x2, "e", x1)
        else:
            print("as raízes da equação são", x1, "e", x2)
    
    else:
        if(d == 0):

            x3 = (-1 * b) / (2 * a)
            print("a raiz desta equação é", x3 )
        else:
            print("esta equação não possui raízes reais")

main()