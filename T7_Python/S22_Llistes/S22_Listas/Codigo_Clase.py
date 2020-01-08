# -*- coding: utf-8 -*-
"""
Created on Tue Dec 17 15:23:12 2019

@author: Santi
"""

linies = []
fitxer = open("comandes.txt", "rt")
for linia in fitxer:
    print(linia)
    linies.append(linia)
    
paraules = linies[0].split()

""
def llegirFitxer(nomFitxer):
    comanda = []
    fitxer = open("comandes.txt", "rt")
    for linia in fitxer:
        paraules = linia.split()
        print(paraules)
        comanda.append([paraules[0], paraules[1:]])
    
    return comanda

"Lo primero que se nos ocurre es hacer un for que add el primer elemento que es el nombre, para tener la lista con los nombres de los cilentes"

"Pero para python hay mas maneras de hacer listas"

def nomsComandes(comandes):
    noms =[c[0] for c in comandes]
    return noms

def modificaClient(comandes, nomClient, novesComandes):
    noms = nomsComandes(comanades)
    if nomClient in noms: #buscamos si existe el cliente
        #necesitamos saber la posicion en la que se encuentra el cliente
        posicio = noms.index(nomClient)
        comandes[posicio][1] = comandes[posicio][1] + novesComandes
    else:
        comandes.append([nomClient, novesComandes])

"Queremos eliminar comandas"
def eliminaComanda(comandes, nomClient, codiComanda):
    noms = nomsComandes(comanades)
    if nomClient in noms: #buscamos si existe el cliente
        posicio = noms.index(nomClient)
        if codiComanda in comandes[posicio][1]:
        #necesitamos saber la posicion en la que se encuentra el cliente
        
        comandes[posicio][1].remove(codiComanda)
    else:
        print("Cliente no existe, por lo tanto no tiene comanda")

" 1 - Queremos crear una lista con el nombre del cliente y la cantidad de comandas que tiene"
def nComandes(comandes):
    nComandesClient = [[C[0], len(c[1]) for c in comandes]
    return nComandes

"2 - Dada una lista de omandas queremos saber el numero total de comandas realizadas"
def nTotalComandes(nComandes):
    totalComandas = sum([c[1] for c in  nComandes])