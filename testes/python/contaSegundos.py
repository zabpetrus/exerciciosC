n = int(input("Por favor, entre com o número de segundos que deseja converter: "))
p1 = n / 60
seg = int( n % 60 )

p2 = p1 / 60
min = int( p1 % 60 ) 

p3 = int( p2 / 24 )
horas = int( p2 % 24 )

print( p3, "dias,", horas,"horas,", min, "minutos e", seg, "segundos.")
