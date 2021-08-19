
object Main{  
    
    def main( args: Array[String]){
        val linha1 = ( scala.io.StdIn.readLine() ).split(" ")
        val linha2 = ( scala.io.StdIn.readLine() ).split(" ")
        var p1 = linha1(1).toInt
        var v1 = linha1(2).toDouble
        var p2 = linha2(1).toInt
        var v2 = linha2(2).toDouble
        var resultado = (p1 * v1) + (p2 * v2)            
        printf("VALOR A PAGAR: R$ %.2f\n", resultado )   
    }
}