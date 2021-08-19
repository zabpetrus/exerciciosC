def computador_escolhe_jogada(n, m):
    
    if(n > 0):
        while(n > 0):
            if(n % (m+1) == 0):
                return n
            if(n == 1):
                return 1
            n = n - 1

def usuario_escolhe_jogada(n, m):

    retirado = 0
    while(retirado == 0):
        f = int(input("Quantas peças você vai tirar? "))
        if (f > 0) and (f <= m) and (f < n):
            retirado = f
        else:
            print("Oops! Jogada inválida! Tente de novo.")

    return retirado

def campeonato():
    for i in range(1, 3):
        print("**** Rodada",i,"****")
        partida()