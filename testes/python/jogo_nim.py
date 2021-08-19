vc = 0
vu = 0

def choose(n, m):
    if(n % (m+1) == 0):
        print("\nVocê começa!\n")             
        return 1 #usuario

    print("\nComputador começa!\n")    
    return 0 #computador



def computador_escolhe_jogada(n, m):

    """
    stop = False
    if(n > m):
        while(stop == False):
            print(n)
            if(n % (m+1) == 0):
                print(n,"Foo")
                if(n <= m):
                    stop = True            
            n = n - 1
    """
    #if(n > m):
    n = n % (m + 1)
    

    if(n > 1):
        print("O computador tirou",n,"peças.")
    else:
        print("O computador tirou uma peça.")   
    return n


def usuario_escolhe_jogada(n, m):
    
    repeat = True
    f = m
    while(repeat):
        f = int(input("Quantas peças você vai tirar? "))
        if (f > 0) and (f <= m) and (f <= n):
            repeat = False
        else:
            print("\nOops! Jogada inválida! Tente de novo.\n")
       
    if(f == 1):
        print("Você tirou uma peça")
    else:
        print("Você tirou",f,"peças")

    return f



def campeonato():
    
    for i in range(1, 4):
        print("\n**** Rodada",i,"****\n")
        partida()

    print("\n**** Final do campeonato! ****\n")

    vc = globals()['vc']
    vu = globals()['vu']
    print("Placar: Você",vc,"X",vu,"Computador")


def showmsg(n,vez):

    if(n > 1):
        print("Agora restam",n,"peças no tabuleiro.\n")

    if(n == 1):
        print("Agora resta apenas uma peça no tabuleiro.\n")
        
    if(n == 0):
        if(vez == 0):
            print("Fim do jogo! Você ganhou!")
            globals()['vc'] = globals()['vc'] + 1
        else:
            print("Fim do jogo! O computador ganhou!")
            globals()['vu'] = globals()['vu'] + 1
        return 0


def partida():

    n = int(input("Quantas peças? "))
    m = int(input("Limite de peças por jogada? "))

    vez = choose(n, m)   #/0 e 1
    terminado = False

    while(terminado == False):

        if(vez == 0):
            p = computador_escolhe_jogada(n, m)
            n = n - p
            #print("PC: ", p, "-", n)
            vez = 1
        else:
            p = usuario_escolhe_jogada(n, m)
            n = n - p
            #print("User: ", p, "-", n)
            vez = 0

        showmsg(n, vez)

        if(n == 0):
            terminado = True

def main():

    opt = int(input("Bem-vindo ao jogo do NIM! Escolha:\n\n1 - para jogar uma partida isolada\n2 - para jogar um campeonato "  ))
    if(opt == 1):
        print("\nVoce escolheu uma partida isolada!")
        partida()
    if(opt == 2):
        print("\nVoce escolheu um campeonato!")
        campeonato()    
    
main()
