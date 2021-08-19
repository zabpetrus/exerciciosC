#create Database.py
#crud using python 
#pip install mysql-connector-python

#Esse script cria um bd

import mysql.connector

conn = mysql.connector.connect(
    host = "localhost",
    user = "root",
    password = "823543"
)

query = conn.cursor()

pre = "DROP DATABASE pycookies"
query.execute(pre)

dbnome = input("Entre com o nome do banco de dados: ")
sql = "CREATE DATABASE " + dbnome

query.execute(sql)

sql2 = "CREATE TABLE " + dbnome + ".Alunos ( Matricula VARCHAR(6) PRIMARY KEY, Nome VARCHAR(100) NOT NULL, CPF VARCHAR(11) NOT NULL, DataNascimento DATE NOT NULL )"
query.execute(sql2)