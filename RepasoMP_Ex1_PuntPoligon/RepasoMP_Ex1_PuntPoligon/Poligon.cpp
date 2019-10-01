#include "Poligon.h"
#include <math.h>

Poligon::Poligon() 
{
    m_nCostats = MIN_COSTATS;
	m_vertexs = new Punt[m_nCostats];
	m_nVertexs = 0;

}

Poligon::Poligon(const Poligon& p)
{
	m_nCostats = p.m_nCostats;
	m_nVertexs = p.m_nVertexs;

	m_vertexs = new Punt[p.m_nCostats];

	for (int i = 0; i < m_nCostats; i++)
		m_vertexs[i] = p.m_vertexs[i];

}


Poligon::~Poligon()
{
	delete[] m_vertexs;
}

Poligon::Poligon(int nCostats)
{
	if ((nCostats >= MIN_COSTATS)) 
		m_nCostats = nCostats;
	else
        m_nCostats = MIN_COSTATS;

	m_vertexs = new Punt[nCostats];
	m_nVertexs = 0;
}

bool Poligon::afegeixVertex(const Punt &v)
{
    bool correcte = false;
    if (m_nVertexs < m_nCostats)
    {
        m_vertexs[m_nVertexs] = v;
		m_nVertexs++;
        correcte = true;
    }
    return correcte;
}

bool Poligon::getVertex(int nVertex, Punt &v) const
{
    bool correcte = false;
    if ((nVertex > 0) && (nVertex <= m_nCostats))
    {
        v = m_vertexs[nVertex - 1];
        correcte = true;
    }
    return correcte;
}

float Poligon::calculaPerimetre() const
{
    float perimetre = 0;
	float dx, dy;
    for (int i = 0; i < m_nCostats - 1; i++)
    {
        dx = m_vertexs[i].getX() - m_vertexs[i+1].getX();
        dy = m_vertexs[i].getY() - m_vertexs[i+1].getY();
        perimetre += sqrt(dx*dx + dy*dy);
    }
	dx = m_vertexs[m_nCostats - 1].getX() - m_vertexs[0].getX();
	dy = m_vertexs[m_nCostats - 1].getY() - m_vertexs[0].getY();
	perimetre += sqrt(dx*dx + dy*dy);
	
	return perimetre;
}

Poligon& Poligon::operator=(const Poligon &p)
{
	if (this != &p) 
	{
		m_nCostats = p.m_nCostats;
		m_nVertexs = p.m_nVertexs;

		if (m_vertexs == NULL)
			delete[] m_vertexs;

		m_vertexs = new Punt[p.m_nCostats];
		for (int i = 0; i < m_nCostats; i++)
			m_vertexs[i] = p.m_vertexs[i];

	}
	
	return *this;
}



