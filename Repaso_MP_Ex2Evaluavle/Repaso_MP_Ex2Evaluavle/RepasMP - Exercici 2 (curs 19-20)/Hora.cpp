#include "Hora.h"

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

bool Hora::validarHora(Hora hora)
{
	bool valida = false;
	
	if ((hora.getHora() >= 0 && hora.getHora() < 24)
		&& (hora.getMinut() >= 0 && hora.getMinut() < 60)
		&& (hora.getSegon() >= 0 && hora.getSegon() < 60))
	{
		valida = true;
	}
	return valida;
}

int Hora::HoraToSeg(Hora hora)
{
	int segTotal = 0;
	segTotal = (hora.getHora() * 60 * 60) + (hora.getMinut() * 60) + hora.getSegon();
	
	return segTotal;
}

Hora Hora::segToHora(int segundos)
{
	Hora hora ;

	int horas;
	horas = segundos / (60 * 60);
	if (horas > 0) 
	{
		hora.setHora(horas);
	}
		
	

}



