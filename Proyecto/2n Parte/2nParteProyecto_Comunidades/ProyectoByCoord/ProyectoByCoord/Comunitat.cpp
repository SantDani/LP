#include "Comunitat.h"
#include "math.h"
Comunitat::Comunitat(MatriuSparse* pMAdj)
{
	m_primComdeltaQ = -1;
	m_Q = 0;
	m_pMAdj = pMAdj;
}

Comunitat::~Comunitat()
{
	m_pMAdj = nullptr;	
}
void Comunitat::clear()
{
	m_pMAdj = nullptr;
	m_deltaQ.clear();
	m_indexComs.clear();
	m_maxDeltaQFil.clear();
	m_primComdeltaQ=-1;
	m_vDendrograms.clear();
	m_k.clear();
	m_A.clear();
	m_hTotal.clear();
	m_Q=0;
	m_M2=0;	
}

/**calculaA(): calcula el valor A de cada nodo. El valor A de cada nodo sera necesario para calcular deltaQ*/

void Comunitat::calculaA()
{
	m_A.resize(m_k.size(), 0);

	for (int i = 0; i < m_k.size(); i++)
	{
		m_A[i] = (double)m_k[i] / (double)m_M2;
	}
}

/**creaIndexComs(): calcula la relacion entre comunidades entre comunidades activas

*/
void Comunitat::creaIndexComs()
{
	m_primComdeltaQ = 0;
	m_indexComs.resize(m_pMAdj->getNFiles());
	for (int fila = 0; fila < m_indexComs.size(); fila++)
	{
		m_indexComs[fila] = {fila+1, fila-1};
	}
}

/*creaDeltaQHeap(): funcion que calculta el deltaQ de cada nodo y el heap(guarda el valor maximo de deltaQ de cada fila).

*/
void Comunitat::creaDeltaQHeap()
{
	m_pMAdj->creaMaps(m_deltaQ);//generamos la estructura de deltaQ
	m_hTotal.resize(m_pMAdj->getNFiles());//deinir tamaño para heap, este es igual al numero de nodos existenes (son las comunidades iniciales)
	m_maxDeltaQFil.resize(m_pMAdj->getNFiles(), {-1,-2});//se le asigna una valor por defecto al m_maxDeltaQFil. En el caso que que un nodo no tenga ralacion este valor por defecto permanecera.
	ElemHeap heapMax = ElemHeap(-9999, {0,0});// se asigna una valor por defecto para que luego pueda ir guarando el maximo DeltaQ de cada fila. 

	
	for (int cont = 0; cont < m_M2; cont++)
	{
		int valorFilaActual = m_pMAdj->getValFila(cont);
		int valorColActual = m_pMAdj->getValCol(cont);
		
		double res = (1.0 / (double)m_M2) - ((double)m_k[valorFilaActual] * (double)m_k[valorColActual]) / (pow((double)m_M2, 2));
		m_deltaQ[valorFilaActual][{valorFilaActual, valorColActual}] = res;

		//determinar cuando he cambiado de fila para intrudcir el maximo
		
		if (res > heapMax.getVal())
		{
			heapMax = ElemHeap(res, { valorFilaActual, valorColActual });//actualizo el deltaQMax
		}
			
		if (cont + 1 < m_M2)//control para que al comprobar la ultima fila + 1 no salte error que se busca una posicion inexistente
		{
			int valorFilaSiguiente = m_pMAdj->getValFila(cont + 1);
			if (valorFilaActual != valorFilaSiguiente)
			{
				//me encuentro en el ultimo elemento de esta fila, por lo tanto guardo el valor deltaQ maximo en m_maxDeltaQFil
				m_maxDeltaQFil[heapMax.getPos().first] = { heapMax.getPos().second, heapMax.getVal()};
				heapMax = ElemHeap(-9999, { -1,-1 });//reiniciar valor, para valorar otro deltaQMax de la siguiente fila

			}
		}
		else
		{
			m_maxDeltaQFil[heapMax.getPos().first] = { heapMax.getPos().second, heapMax.getVal() };
			heapMax = ElemHeap(-9999, { -1,-1 });
		}
		
	}

	for (int fila = 0; fila < m_maxDeltaQFil.size(); fila++)
	{
		heapMax = ElemHeap(m_maxDeltaQFil[fila].second, { fila, m_maxDeltaQFil[fila].first });
		m_hTotal.insert(heapMax);
	}

}

void Comunitat::modificaVei(int com1, int com2, int vei, int cas)
{

}

void Comunitat::fusiona(int com1, int com2)
{

}

void Comunitat::generaDendrogram(int pos1, int pos2, double deltaQp1p2)
{
}

void Comunitat::calculaComunitats(list<Tree<double>*>& listDendrogram)
{

}

