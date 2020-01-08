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
               
def principal():
     punts = llegirPunts()
     opcio = input("Introdueix una opcio (1- Mostrar, 2- Perimetre, 3- Rectangle minim): ")
     if (opcio == '1'):
         mostraPunts(punts)
     elif (opcio == '2'):
         print ("El perimetre del poligon es: ", calculaPerimetre(punts))
 #    elif (opcio == '3'):
 #        print ("El rectangle minim del poligon es: ")
 #        print (rectangleMinim(punts))
     else: 
         print ("Opcio incorrecta")
           
if __name__ == "__main__":
    principal()