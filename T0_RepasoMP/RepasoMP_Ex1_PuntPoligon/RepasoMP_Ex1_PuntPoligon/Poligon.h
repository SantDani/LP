
#ifndef POLIGON_H
#define POLIGON_H


#include "Punt.h"
#include "../../RepasoMP_Ex2_Nodos/RepasoMP_Ex2_Nodos/Node.h"

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
		
		/* Para trabajar con Nodos enlazados 
			1- Crear la clase nodo 
			2- 
		*/
        
        static const int MIN_COSTATS = 3;
		Node* m_vertexs;
		Node* m_ultimVertex;
        int m_nCostats;
		int m_nVertexs;
};

#endif // POLIGON_H
