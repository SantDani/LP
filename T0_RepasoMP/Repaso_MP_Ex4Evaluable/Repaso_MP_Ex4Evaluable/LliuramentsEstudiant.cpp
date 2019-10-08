#include "LliuramentsEstudiant.h"

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
		if (it->getData() == data)
		{
			fitxer = it->getFitxer();// comprobar
		}
	}

	return tramesaTrobada;
}

bool LliuramentsEstudiant::eliminaTramesa(const string& data)
{
	bool eliminarTramesa = false;
	//std::forward_list<Tramesa>::const_iterator aux = m_trameses.before_begin();
		
	std::forward_list<Tramesa>::iterator it ;
	 //string data = aux->getData();
	 //string fixer = aux->getFitxer();
	for (it = m_trameses.begin(); it != m_trameses.end(); it++)
	{
	
		string myFecha = it->getData();
		if (it->getData() == data)
		{
			Tramesa tramesa(*it);
			//m_trameses.remove(tramesa); // comprobar FIX
			eliminarTramesa = true;
			//it = m_trameses.end();
		}
	}
	return eliminarTramesa;
}
