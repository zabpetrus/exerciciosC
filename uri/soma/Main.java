import java.io.IOException;
import java.util.*;
 
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
    
    private static int somasimples(int a, int b)
    {
        return a + b;
    }
 
    public static void main(String[] args) throws IOException {
 
       Scanner input = new Scanner(System.in);
        int a, b, s;
        a = input.nextInt();
        b = input.nextInt();
        s = somasimples(a, b);
        System.out.printf("SOMA = %d\n", s);
    }
 
}