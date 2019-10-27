#include "LliuramentsEstudiant.h"
#include <iostream>

using namespace std;

void LliuramentsEstudiant::afegeixTramesa(const string& fitxer, const string& data)
{
	Tramesa tramesa(fitxer, data);
	m_trameses.push_front(tramesa);
}

bool LliuramentsEstudiant::consultaTramesa(const string& data, string& fitxer)
{
	bool tramesaTrobada = false;
	
	std::forward_list<Tramesa>::iterator it;
	for (it = m_trameses.begin(); it != m_trameses.end(); it++)
	{
		//cout << "fecha actual: " << it->getData()<< " Buscando fecha: " << data << endl;
		if (it->getData() == data)
		{
			tramesaTrobada = true;
			//cout << "-------------------------------------------------------encontrado" << endl; 
			fitxer = it->getFitxer();// comprobar
			break;
		}
	}

	return tramesaTrobada;
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	bool eliminarTramesa = false;
	std::forward_list<Tramesa>::iterator itAnterior = m_trameses.before_begin();
	std::forward_list<Tramesa>::iterator itActual = m_trameses.begin();
	

	while (!eliminarTramesa && (itActual != m_trameses.end()))
	{
		//cout << itActual->getData() << " esperando " << data << endl;
		if (itActual->getData() == data ) 
		{
			//cout << itActual->getData() << " ENCONTRADO Y ELIMINADO ------- " << data << endl;
			eliminarTramesa = true;
			itActual = m_trameses.erase_after(itAnterior);
		}
		else 
		{
			itAnterior = itActual;
			itActual++;
		}

	}
	return eliminarTramesa;
}
