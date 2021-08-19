n = 0
m = 0
vez = ""

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

def partida():
    
    globals()['n'] = int(input("Quantas peças? "))
    globals()['m'] = int(input("Limite de peças por jogada? "))
    
    #comeco
    if(n % (m+1) == 0):
        print("Você começa!")
        p = usuario_escolhe_jogada(n,m)
        globals()['vez'] = "Usuário"

    else:
        print("Computador começa!")
        p = computador_escolhe_jogada(n, m)
        globals()['vez'] = "Computador"


    globals()['n'] = globals()['n'] - p
    if( globals()['vez'] == 'Usuário'):        
        print("Você tirou",p,"peças.")
    else:
        print("O computador tirou",p,"peças.")
          

def campeonato():
    for i in range(1, 3):
        print("**** Rodada",i,"****")
        partida()

def main():

    #print("Bem-vindo ao jogo do NIM! Escolha:\n")
    #print("1 - para jogar uma partida isolada\n2 - para jogar um campeonato ")

    opt = int(input("Bem-vindo ao jogo do NIM! Escolha:\n1 - para jogar uma partida isolada\n2 - para jogar um campeonato "  ))
    if(opt == 1):
        print("Voce escolheu uma partida isolada!")
        partida()

    if(opt == 2):
        print("Voce escolheu um campeonato!")
        campeonato()


    #print("Placar: Você 0 X 3 Computador")

main()
