def remove_repetidos(lista):
    novo = []
    for x in lista:
        if x not in novo:
            novo.append(x)
    novo.sort()
    return novo
