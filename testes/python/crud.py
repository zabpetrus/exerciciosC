#crud using python 
#pip install mysql-connector-python

import mysql.connector

conn = mysql.connector.connect(
    host = "localhost",
    user = "root",
    password = "823543",
    database = "pycookies"
)

query = conn.cursor()

print("Entre com os dados a serem inseridos: ")

matricula = input("Matricula: ")
nome = input("Nome: ")
cpf = input("CPF: ")
datanasc = input("Data de Nascimento: ")

dpf = datanasc.split("/")
df = dpf[2] + "-" + dpf[1] + "-" + dpf[0]


sql = "INSERT INTO Alunos (Matricula, Nome, CPF, dataNascimento) VALUES (%s, %s, %s, %s)"
val = (matricula, nome, cpf, df)
query.execute(sql, val)
conn.commit()
print(query.rowcount, "Registro inserido com sucesso.")