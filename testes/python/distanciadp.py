import math

dx1 = float(input())
dy1 = float(input())
dx2 = float(input())
dy2 = float(input())

h1 = (dx1 - dx2) ** 2
h2 = (dy1 - dy2) ** 2

dab = math.sqrt( h1 + h2 )

if(dab >= 10):
    print("longe")
else:
    print("perto")

