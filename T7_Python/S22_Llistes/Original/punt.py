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
        
    def __add__(self, p):
        return Punt(p.__x + self.__x, p.__y + self.__y)
    
    def __sub__(self, p):
        return math.sqrt((p.__x - self.__x)**2 + (p.__y - self.__y)**2)
        
    def __str__(self):
        return "("+str(self.__x)+","+str(self.__y)+")"
    