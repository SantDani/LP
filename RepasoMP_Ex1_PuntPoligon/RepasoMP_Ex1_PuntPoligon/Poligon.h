#ifndef POLIGON_H
#define POLIGON_H

#include "Punt.h"

class Poligon
{
    public:
		Poligon() ;
        ~Poligon();
        Poligon(int nCostats);
		//Constructor copia
		Poligon(const Poligon& p) ;
		//Operador de asignacion
		Poligon& operator=(const Poligon& p);
        int getNCostats() const { return m_nCostats; };
        bool afegeixVertex(const Punt &v);
        bool getVertex(int nVertex, Punt &v) const;
        float calculaPerimetre() const;
		
		
    private:
		/* Para hacer un array dinamico
			1- Subtituir el vector por un apuntador
			2- Eliminar la longitud maxima del array, ya que, esta sera diferente cada vez que se instancie
		*/

        //static const int MAX_COSTATS = 30; eliminamos
        static const int MIN_COSTATS = 3;
        //Punt m_vertexs[MAX_COSTATS]; // cambiamos este vector por un apuntador
		Punt * m_vertexs;// nos permitira crear tantos vertices como nos interese. (Elementos dinamicos)
        int m_nCostats;
		int m_nVertexs;
};

#endif // POLIGON_H
