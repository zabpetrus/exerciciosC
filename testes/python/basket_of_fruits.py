
class Basket:
    
    def __init__ (self, orderlist ):
        
        self.orderlist = orderlist

    def buyLotsOfFruit(self):

        totalCost = 0.0
        fruitPrices = {'apples': 2.00, 'oranges': 1.50, 'pears': 1.75, 'limes': 0.75, 'strawberries': 1.00 }
        
        print(fruitPrices['apples'])

        for x in orderlist:
            
            totalCost += (fruitPrices[x[0]] * x[1])
        
        return totalCost


if __name__ == '__main__':
    
    orderlist = [('apples', 2.0), ('pears', 3.0), ('limes', 4.0)]
    p = Basket(orderlist)

    print( 'Cost of', orderlist, 'is', p.buyLotsOfFruit() )
    