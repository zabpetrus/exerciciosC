n = int(input("Digite um número inteiro: "))
m = n % 10
repetido = False
mv = 1

while(n > 1 and (not repetido) ):
    n = n // 10
    mv = n % 10
    if(mv == m):
        repetido = True
    m = mv
    
if repetido:
    print("sim")  
else:
    print("não") 
