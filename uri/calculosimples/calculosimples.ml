let calcular npecasA valorA npecasB valorB  = 
   (float_of_int npecasA *. valorA) +. (float_of_int npecasB *. valorB);;

let (codeA, npecasA, valorA) = 
   Scanf.scanf "%d  %d  %f\n" (fun codeA  npecasA  valorA -> (codeA, npecasA, valorA));;

let (codeB, npecasB, valorB) = 
   Scanf.scanf "%d  %d  %f\n" (fun codeB  npecasB  valorB -> (codeB, npecasB, valorB));;

let resultado = calcular npecasA valorA npecasB valorB;;

Printf.printf "VALOR A PAGAR: R$ %.2f\n" resultado;;