import re

def le_assinatura():
    '''A funcao le os valores dos tracos linguisticos do modelo e devolve uma assinatura a ser comparada com os textos fornecidos'''
    print("Bem-vindo ao detector automático de COH-PIAH.")
    print("Informe a assinatura típica de um aluno infectado:")

    wal = float(input("Entre o tamanho médio de palavra:"))
    ttr = float(input("Entre a relação Type-Token:"))
    hlr = float(input("Entre a Razão Hapax Legomana:"))
    sal = float(input("Entre o tamanho médio de sentença:"))
    sac = float(input("Entre a complexidade média da sentença:"))
    pal = float(input("Entre o tamanho medio de frase:"))

    return [wal, ttr, hlr, sal, sac, pal]

def le_textos():
    '''A funcao le todos os textos a serem comparados e devolve uma lista contendo cada texto como um elemento'''
    i = 1
    textos = []
    texto = input("Digite o texto " + str(i) +" (aperte enter para sair):")
    while texto:
        textos.append(texto)
        i += 1
        texto = input("Digite o texto " + str(i) +" (aperte enter para sair):")

    return textos

def separa_sentencas(texto):
    '''A funcao recebe um texto e devolve uma lista das sentencas dentro do texto'''
    sentencas = re.split(r'[.!?]+', texto)
    if sentencas[-1] == '':
        del sentencas[-1]
    return sentencas

def separa_frases(sentenca):
    '''A funcao recebe uma sentenca e devolve uma lista das frases dentro da sentenca'''
    return re.split(r'[,:;]+', sentenca)

def separa_palavras(frase):
    '''A funcao recebe uma frase e devolve uma lista das palavras dentro da frase'''
    return frase.split()

def n_palavras_unicas(lista_palavras):
    '''Essa funcao recebe uma lista de palavras e devolve o numero de palavras que aparecem uma unica vez'''
    freq = dict()
    unicas = 0
    for palavra in lista_palavras:
        p = palavra.lower()
        if p in freq:
            if freq[p] == 1:
                unicas -= 1
            freq[p] += 1
        else:
            freq[p] = 1
            unicas += 1

    return unicas

def n_palavras_diferentes(lista_palavras):
    '''Essa funcao recebe uma lista de palavras e devolve o numero de palavras diferentes utilizadas'''
    freq = dict()
    for palavra in lista_palavras:
        p = palavra.lower()
        if p in freq:
            freq[p] += 1
        else:
            freq[p] = 1

    return len(freq)

def compara_assinatura(as_a, as_b):
    '''IMPLEMENTAR. Essa funcao recebe duas assinaturas de texto e deve devolver o grau de similaridade nas assinaturas.'''
    tmp = abs( as_a[0] - as_b[0] )
    rtt = abs( as_a[1] - as_b[1] )
    rhl = abs( as_a[2] - as_b[2] )
    tms = abs( as_a[3] - as_b[3] )
    cms = abs( as_a[4] - as_b[4] )
    tmf = abs( as_a[5] - as_b[5] )
    soma = tmp + rtt + rhl + tms + cms + tmf    
    resultado = soma / 6.0
    return resultado



def calcula_assinatura(texto):

    '''IMPLEMENTAR. Essa funcao recebe um texto e deve devolver a assinatura do texto.'''
    tam_sentencas = 0   
    tam_frases = 0
    tam_palavras = 0

    num_palavras = 0
    num_sentencas = 0
    num_frases = 0
    array_palavras = []    

    tseparado = separa_sentencas( texto ) #lista

    for sentenca in tseparado:

        tam_sentencas = tam_sentencas + len(sentenca)
        num_sentencas += 1

        frases = separa_frases(sentenca) #lista
        tam_frases = tam_frases + len(frases)

        for frase in frases:

            palavras = separa_palavras(frase) #lista
            num_palavras = num_palavras + len(palavras)
            num_frases = num_frases + len(frase)

            for palavra in palavras:
                array_palavras.append( palavra )
                tam_palavras = tam_palavras + len(palavra)         
            

    tmp = tam_palavras / num_palavras
    rtt = n_palavras_diferentes(array_palavras) / num_palavras
    rhl = n_palavras_unicas(array_palavras) / num_palavras
    tms = tam_sentencas  / num_sentencas
    cs = tam_frases / num_sentencas
    tmf = num_frases / tam_frases

    # x = [num_palavras, tam_palavras, tam_frases, num_frases, tam_sentencas, num_sentencas]
    y = [tmp, rtt, rhl, tms, cs, tmf]

    # print(x)
    return y

def avalia_textos(textos, ass_cp):
    '''IMPLEMENTAR. Essa funcao recebe uma lista de textos e uma assinatura ass_cp e deve devolver o numero (1 a n) do texto com maior probabilidade de ter sido infectado por COH-PIAH.'''
    
    menor = 9999
    index = 0
    assinaturas = []
    for i in range (0, len(textos)):
        x = calcula_assinatura(textos[i])
        assinaturas.append(x)

    for j in range (0, len(assinaturas)):
        a = compara_assinatura(assinaturas[j], ass_cp)
        if a < menor:
            menor = a
            index = j

    return (index + 1)  


        

"""
ass_cp = le_assinatura()
# ass_cp = [4.51, 0.693, 0.55, 70.82, 1.82, 38.5]
texto_bruto = le_textos()
msg = avalia_textos(texto_bruto, ass_cp)
print ("O autor do texto", msg ,"está infectado com COH-PIAH")
"""


