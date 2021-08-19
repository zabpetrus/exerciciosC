program foo;

uses 
    sysutils;

var
    codeA, codeB : integer;
    npecasA, npecasB : integer;
    valorA, valorB, resultado : double;

begin
    Readln (codeA, npecasA, valorA);
    Readln (codeB, npecasB, valorB );
    resultado := (npecasA * valorA ) + (npecasB * valorB);
    writeln ('VALOR A PAGAR: R$ ',Format('%.2f', [resultado]) );
end.
