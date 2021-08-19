def eh_primo(n):
    i = 2
    while(i < n):
        if(n % i == 0):
            return False
        i+=1
    return True


def n_primos(n):
    cont = 0
    i = 2
    while(i <= n):
        if(eh_primo(i)):
            cont += 1
        i+=1
    return cont

print(n_primos(121))