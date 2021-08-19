"""
r = input()
n = r.split(",")

n0 = int(n[0])
n1 = int(n[1])
n2 = int(n[2])

"""

n0 = int( input() )
n1 = int( input() )
n2 = int( input() )

if(( n0 < n1 ) and (n1 < n2)):
    print("crescente")
else:
    print("não está em ordem crescente")