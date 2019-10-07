#include "Hora.h"
using namespace std;

Hora:: Hora()
{
	m_hora = 0;
	m_minut = 0;
	m_segon = 0;
};

Hora::Hora(const Hora& hora)
{
	m_hora = hora.m_hora; 
	m_minut = hora.m_minut; 
	m_segon = hora.m_segon;
}

bool Hora::horaValida()
{
	bool valida = false;
	
	if ((getHora() >= 0 && getHora() < 24)
		&& (getMinuts() >= 0 && getMinuts() < 60)
		&& (getSegons() >= 0 && getSegons() < 60))
	{
		valida = true;
	}
	return valida;
}

float Hora::HoraToSeg(Hora hora)
{
	float segTotal = 0;
	segTotal = (hora.getHora() * 60 * 60) + (hora.getMinuts() * 60) + hora.getSegons();
	
	return segTotal;
}


Hora Hora::segToHora(float segundos)
{
	//podia poner solo variable cant
	//asi es mas entendible
	int seg = segundos;
	int dias;
	int horas;
	int min;
	
	dias = seg / DIA_TO_SEG;
	//if (dias > 0)
	seg = seg - (dias * DIA_TO_SEG);
	horas = seg / HORA_TO_SEG;
	//if (horas > 0)
	seg = seg - (horas * HORA_TO_SEG);
	min = seg / MIN_TO_SEG;
	//if (min > 0)
	seg = seg - (min * MIN_TO_SEG);
	
	Hora hora(horas, min, seg);

	return hora;
}

//Poligon& Poligon::operator=(const Poligon& p)
Hora Hora::operator+(const Hora& h2)
{
	
	float segTotal = HoraToSeg(*this) + HoraToSeg(h2);
	
	Hora hora(segToHora(segTotal));
	return ( hora);
}

Hora Hora::operator+(const float& segundos)
{

	float segTotal = HoraToSeg(*this) + segundos;

	
	Hora hora(segToHora(segTotal));
	return hora;
}

bool Hora::operator==(const Hora& h)
{
	return ((m_hora == h.m_hora) && (m_minut == h.m_minut) && (m_segon == h.m_segon));
}

bool Hora::operator<(const Hora& h)
{
	//he de tener en cuenta todas las posibilidades, si la hora es igual que pasa 
	bool horaMenor = false;
	if (m_hora <= h.m_hora) 
	{
		if (m_hora < h.m_hora)
			horaMenor = true;
		else if (m_hora == h.m_hora)
		{
			if (m_minut <= h.m_minut)
			{
				if (m_minut < h.m_minut)
				{
					horaMenor = true;
				}
				else if (m_minut == h.m_minut)
				{
					if (m_segon <= h.m_segon)
					{
						if (m_segon < h.m_segon)
							horaMenor = true;
						
					}
				}
			}
		}
			
			
	}
	
	return horaMenor;
		
	
}

Hora Hora::operator=(const Hora& hora)
{
	m_hora = hora.m_hora;
	m_minut = hora.m_minut;
	m_segon = hora.m_segon;

	return *this;
}







