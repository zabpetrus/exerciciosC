(*
ocamlmktop -o ocaml-graphics graphics.cma
ocamlc graphics.cma mellorine.ml -o mellorine.exe
*)
(*
open Graphics;;
open_graph " 640x480";;

let maiordedois x y =
  if x > y then x else y;;

let maiordetres x y z =
  let p1 = maiordedois x y in
  maiordedois p1 z;;    

let(a, b, c) = Scanf.scanf "%d %d %d" (fun a b c ->(a, b, c));;
let maior = maiordetres a b c;;
Printf.printf "%d eh o maior" maior;;

read_line();;
*)

