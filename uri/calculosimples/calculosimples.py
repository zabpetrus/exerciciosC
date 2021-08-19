# ****************************************************************
"""
def calculosimples (npecasA, valorA, npecasB, valorB):
    return ( float( npecasA ) * float( valorA) ) +  (  float( npecasB ) * float( valorB) )

codeA, npecasA, valorA = raw_input().split()
codeB, npecasB, valorB = raw_input().split()
resultado = calculosimples( npecasA, valorA, npecasB, valorB)
print "VALOR A PAGAR: R$ {0:.2f}". format(resultado) 

"""

#**********************************************************************

def calculosimples (npecasA, valorA, npecasB, valorB):
    return ( float( npecasA ) * float( valorA) ) +  (  float( npecasB ) * float( valorB) )

codeA, npecasA, valorA = input().split()
codeB, npecasB, valorB = input().split()
resultado = calculosimples( npecasA, valorA, npecasB, valorB)
print ("VALOR A PAGAR: R$ {0:.2f}". format(resultado))
