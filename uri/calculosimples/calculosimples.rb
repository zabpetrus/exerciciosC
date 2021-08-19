def calculosimples (npecasA, valorA, npecasB, valorB)
    return ( Float( npecasA ) * Float( valorA) ) +  (  Float( npecasB ) * Float( valorB) )
end

linha1 = gets.chomp
linha2 = gets.chomp
varA = linha1.split(" ")
varB = linha2.split(" ")

resultado = calculosimples( varA[1], varA[2], varB[1], varB[2])
puts "VALOR A PAGAR: R$ %.2f" % [ resultado ] 