#criar crud completo

from __future__ import print_function

import mysql.connector
from mysql.connector import errorcode

if __name__ == '__main__':
    
    nhost = "localhost"
    nuser = "root"
    npassword = "823543"
    nddatabase = "pycookies"

    str_tabela = {}

    str_tabela['funcionarios'] = (
        "CREATE TABLE funcionarios ("
        "   func_id int(11) NOT NULL AUTO_INCREMENT,"
        "   func_nome varchar(100) NOT NULL,"
        "   func_email varchar(100) NOT NULL,"
        "   func_datanasc date NOT NULL,"
        "   PRIMARY KEY( func_id )"
        ") ENGINE=InnoDB"
    )

    str_tabela['funcoes'] = (
        "CREATE TABLE cargos ("
        "   car_id int(11) NOT NULL AUTO_INCREMENT,"
        "   car_nome varchar(100) NOT NULL,"
        "   PRIMARY KEY( car_id )"
        ") ENGINE=InnoDB"
    )


    conn = mysql.connector.connect( user = nuser, password = npassword, host = nhost, database = nddatabase)
    query = conn.cursor()

    try:
        query.execute("USE " + nddatabase)
    except mysql.connector .Error  as err:
        print("Erro: {}" . format(err))

    for table in str_tabela:

        tabela = str_tabela[table]
        try:
            print("Criando tabela {}: " . format(table))
            query.execute(tabela)
        except mysql.connector .Error as err:
            if err.errno == errorcode.ER_TABLE_EXISTS_ERROR:
                print ("Ja existe")
            else:
                print(err.msg)
        else:
            print("OK")

    query.close()
    conn.close()



