#include "Poligon.h"
#include <math.h>

Poligon::Poligon() 
{
    m_nCostats = MIN_COSTATS;
	m_nVertexs = 0;
	
	m_vertexs = NULL;
	m_ultimVertex = NULL;
	

}

Poligon::Poligon(const Poligon& p)
{
	m_nCostats = p.m_nCostats;
	m_nVertexs = 0;
	m_vertexs = NULL;
	m_ultimVertex = NULL;
	Node* aux = p.m_vertexs;
	while (aux != NULL)
	{
		afegeixVertex(aux->getValor());
		aux = aux->getNext();
	}
}




Poligon::~Poligon()
{
	while (m_vertexs !=  NULL)
	{
		Node* aux;
		aux = m_vertexs;
		m_vertexs = m_vertexs->getNext();
		delete aux;
	}
}

Poligon::Poligon(int nCostats)
{
	if ((nCostats >= MIN_COSTATS)) 
		m_nCostats = nCostats;
	else
        m_nCostats = MIN_COSTATS;

	m_vertexs = NULL;
	m_ultimVertex = NULL;
	m_nVertexs = 0;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
		m_nVertexs++;
        correcte = true;
		Node* aux = new Node(v);//creo y doy valor a punto
		if (m_vertexs == NULL)
			m_vertexs = aux;
		else
			m_ultimVertex->setNext(aux);
		m_ultimVertex = aux ;
    }
    return correcte;

}






bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
		Node* aux = m_vertexs;
		for (int i = 0; i < m_nVertexs; i++)
		{
			aux = aux->getNext();
		}
		v = aux->getValor();
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
	float dx, dy;
	Node* aux = m_vertexs;
    for (int i = 0; i < m_nCostats - 1; i++)
    {
		Node* seguent = aux->getNext();
        dx = aux->getValor().getX() - seguent->getValor().getX();
		dy = aux->getValor().getY() - seguent->getValor().getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
	dx = aux->getValor().getX() - m_vertexs->getValor().getX();
	dy = aux->getValor().getY() - m_vertexs->getValor().getY();
	perimetre += sqrt(dx*dx + dy*dy);
	
	return perimetre;
}

Poligon& Poligon::operator=(const Poligon& p)
{
	if (this != &p)
	{
		m_nCostats = p.m_nCostats;
		m_nVertexs = 0;

		while (m_vertexs != NULL)
		{
			Node* aux;
			aux = m_vertexs;
			m_vertexs = m_vertexs->getNext();
			delete aux;
		}
		
		Node* aux = p.m_vertexs;
		while (aux != NULL)
		{
			afegeixVertex(aux->getValor());
			aux = aux->getNext();
		}

	}

	return *this;
}

