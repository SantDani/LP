# -*- coding: utf-8 -*-

import punt

def llegirPunts():
    punts = []
    x = input ("Coordenada x del punt: ")
    while (x != ''):
        y = input ("Coordenada y del punt: ")
        punts.append(punt.Punt(int(x), int(y)))
        x = input ("Coordenada x del punt: ")
    return punts

def mostraPunts(punts):
    print ("El poligon que s'ha llegit es aquest")
    for i in range(len(punts)):
         print (punts[i])
         
def calculaPerimetre(punts):
    perimetre = 0
    for i in range(len(punts) - 1):
        perimetre = perimetre + punts[i].distancia(punts[i+1])
    perimetre = perimetre + punts[0].distancia(punts[len(punts) - 1])
    return perimetre

def sum(llista):
    resutlado = 0
    for x in llista:
        resutlado += x
    return resutlado

def minim(llista):
    
    indexMin = 0
    valorMinim = 0
    for index, valorActual in enumerate(llista):
        if(x < valorMinim):
            valorMinim = valorActual
            indexMin = index
            
    return indexMin, valorMinim

def rectangleMinim(punts):
    Xmin = punts[0].getX()
    Ymin = punts[0].getY()
    Xmax = punts[0].getX()
    Ymax = punts[0].getY()
    
    for i in range(1, len(punts)):
        
        if(punts[i].getx() < Xmin):
            Xmin = punts[i].getx()
        elif(punts[i].getx() > xmax):
            xmax = punts[i].getx()
            
        if(punts[i].gety() < ymin):
            ymin = punts[i].gety()
        elif(punts[i].gety() > ymax):
            ymax = punts[i].gety()
            
    return [xmin, ymin, ymin, ymax]
    
    
    
               
def principal():
     punts = llegirPunts()
     opcio = input("Introdueix una opcio (1- Mostrar, 2- Perimetre, 3- Rectangle minim): ")
     if (opcio == '1'):
         mostraPunts(punts)
     elif (opcio == '2'):
         print ("El perimetre del poligon es: ", calculaPerimetre(punts))
     elif (opcio == '3'):
         print ("El rectangle minim del poligon es: ")
         print (rectangleMinim(punts))
     else: 
         print ("Opcio incorrecta")
         
    
# Lo primero que se ejecuta es la funcion principal()
if __name__ == "__main__":
    principal()