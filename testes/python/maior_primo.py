def maior_primo( n ):

    i = 2    
    while(i < n):
        if(n % i == 0):
            n = n - 1            
            i = 2        
        i+=1        
    
    return n   

a = int(input("Entre com um numero: "))
print(maior_primo(a))