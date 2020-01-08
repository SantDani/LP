# -*- coding: utf-8 -*-

import math

class Punt:
    __slots__ = ['__x', '__y']
    def __init__(self, x = 0, y = 0):
        self.__x = x
        self.__y = y
        
    def getX(self):
        return self.__x
        
    def getY(self):
        return self.__y
    
    def setX(self, x):
        self.__x = x
        
    def setY(self, y):
        self.__y = y
    def distancia(self, p):
        x = p.__x - self.__x
        y = p.__y - self.__y
        return math.sqrt((x**2) + (y**2))
   
         
        
    def __add__(self, p):
        return Punt(p.__x + self.__x, p.__y + self.__y)
    
    def __sub__(self, p):
        return self.distancia(p)
        
    def __str__(self):
        return "("+str(self.__x)+","+str(self.__y)+")"
    