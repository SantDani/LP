

Python VS C++



con ":" indicamos un inicio de bloque de código, también hay que identar el código hacia la derecha para indicar que [line]() pertenecen a este bloque de código.

Veamos la [definition]() de la clase

```python
import math #Comentario 0: para importar librerias o clases que hemos picado

class Punt:
    __slots__ = ['__x', '__y'] #Comentario 1
    def __init__(self, x = 0, y = 0):#Comentario 2: __init__
        self.__x = x #Comentario 3: __[nombre Variable]
        self.__y = y
    def getY(self):#Comentario 4: Self
        return self.__y
    
    def setX(self, x):
        self.__x = x
        
    def setY(self, y):
        self.__y = y
    
    def __add__(self, p):#Comentario 5: Sobrecarga Operadores
        return Punt(p.__x + self.__x, p.__y + self.__y)
    
    def __sub__(self, p):
        return math.sqrt((p.__x - self.__x)**2 + (p.__y - self.__y)**2)
        
    def __str__(self): #Comentario 6: sobrecara operador str (string)
        return "("+str(self.__x)+","+str(self.__y)+")"
    
```

```python
 #Comentario 0: para importar librerias o clases que hemos picado
```

```python
#Comentario 1
```

Especificar los atributos de las clases es opcional, ya que, no declara ni crea los atributos, solamente es para especificarlos (queda claro cuales son los atributos).

```python
#Comentario 2: __init__ es el constructor
```

En este caso el constructor tiene dos parámetros : [X]() y [Y]() con un valor por defecto igual a cero.



```python
#Comentario 3: __[nombre Variable]
```

Convención para indicar que es una variable privada de la clase

```python
#Comentario 4: Self equivalente this en C++
```

Self: hace referencia a el objeto que crida el método( es equivalente a [this]() en C++). Esto significa que referenciar cualquier atributo dentro de la clase se ha de hacer mediante el self.[atributo/variable].

```python
#Comentario 5: Sobrecarga Operadores

p1 = Punt(1,2)
p2 = Punt(2,2)
p1 + p2 ------> __add__(self, p) donde self = p1 y p = p2. El resultado es la suma de los dos puntos que es otro objeto punto.


```

#### [Python magic methods or special functions for operator overloading](https://www.geeksforgeeks.org/operator-overloading-in-python/)

#### [Binary Operators](https://www.geeksforgeeks.org/basic-operators-python/):

| OPERATOR |       MAGIC METHOD        |
| :------: | :-----------------------: |
|  **+**   |   __add__(self, other)    |
|  **–**   |   __sub__(self, other)    |
|  *****   |   __mul__(self, other)    |
|  **/**   | __truediv__(self, other)  |
|  **//**  | __floordiv__(self, other) |
|  **%**   |   __mod__(self, other)    |
| ***\***  |   __pow__(self, other)    |

#### Comparison Operators :

| OPERATOR |    MAGIC METHOD     |
| :------: | :-----------------: |
|  **<**   | __lt__(self, other) |
|  **>**   | __gt__(self, other) |
|  **<=**  | __le__(self, other) |
|  **>=**  | __ge__(self, other) |
|  **==**  | __eq__(self, other) |
|  **!=**  | __ne__(self, other) |

#### Assignment Operators :

| OPERATOR |        MAGIC METHOD        |
| :------: | :------------------------: |
|  **-=**  |   __isub__(self, other)    |
|  **+=**  |   __iadd__(self, other)    |
|  ***=**  |   __imul__(self, other)    |
|  **/=**  |   __idiv__(self, other)    |
| **//=**  | __ifloordiv__(self, other) |
|  **%=**  |   __imod__(self, other)    |
| ***\*=** |   __ipow__(self, other)    |

```python
#Comentario 6: sobrecara operador str (string)
```

Convertimos Punt a string para poder mostrarlo por pantalla con la funcion print()

```python
Ejemplo:
    p = Punt(1,1)
    print(p)
    #Mostrara 
    (1,1)
```

