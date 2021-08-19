def fizzbuzz( n ):
    
    if((n % 3 == 0) or (n % 5 == 0)):
        
        if((n % 3 == 0) and (n % 5 == 0)):
            return "FizzBuzz"
        else:
            if(n % 3 == 0):
                return "Fizz"
            else:
                return "Buzz"
    return n

"""
print (fizzbuzz(3))
#"Fizz"
print (fizzbuzz(5))
#"Buzz"
print (fizzbuzz(15))
#"FizzBuzz"
print (fizzbuzz(4))
#4

"""