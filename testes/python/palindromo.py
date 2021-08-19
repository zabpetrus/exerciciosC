# Nomes que não ajudam
def p(a):
    i = 0
    while i < len(a):
        if (a[i] != a[len(a) - i - 1]):
            return False
        i = i + 1
    return True
        
# Nomes que ajudam a entender intuitivamente o problema
def eh_palindromo(palavra):
    letra = 0
    while letra < len(palavra):
        if palavra[letra] != palavra[len(palavra) - letra - 1]:
            return False
    return True

c = p("cascata")
palavra = "ovo"
print(eh_palindromo(palavra))

    