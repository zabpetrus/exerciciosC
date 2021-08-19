(*
let a = read_float();;
let b = read_float();;

let () =
  if a > b then
    Printf.printf "%.0f eh o maior \n" a
  else
    Printf.printf "%.0f eh o maior \n" b;;*)

let () = 
  print_string ("Entre com um valor qualquer: ")
  let c = read_float();;
  c := c +. 5.;;
  Printf.printf "Voce digitou %f\n" c;;




