(*
ocamlmktop -o ocaml-graphics graphics.cma
ocamlc graphics.cma prof.ml -o prof.exe

ocamlopt -o progprog.exe prof.ml
ocamlopt -o progprog.exe unix.cmxa prof.ml
*)

open Graphics;;

open_graph " 640x480";;
for i = 12 downto 1 do
  let radius = i * 20 in
  set_color (if i mod 2 = 0 then red else yellow);
  fill_circle 320 240 radius
done;;
read_line ();;