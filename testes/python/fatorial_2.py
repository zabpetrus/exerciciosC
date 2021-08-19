def fatorial( n ):
    i = 1
    while(n > 1):
        i = i * n
        n-=1
    return i

def test_answer():
    assert fatorial(5) == 120

def test_fatorial0():
    assert fatorial(0) == 1

def test_fatorial1():
    assert fatorial(1) == 1

def test_fatorial4():
    assert fatorial(4) == 24

def test_fatorial10():
    assert fatorial(10) == 3628800


# n = int(input("Entre com o numero: "))
# print(fatorial(n))
    