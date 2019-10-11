#include "Exercici.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Exercici::Exercici(const Exercici& e)
{
	m_descripcio = e.m_descripcio;
	m_dataLimit = e.m_dataLimit;
	m_nEstudiants = e.m_nEstudiants;

	m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
	for (int i = 0; i < m_nEstudiants; i++)
	{
		m_lliuraments[i] = e.m_lliuraments[i];
	}

}

Exercici::~Exercici()
{
	delete[] m_lliuraments;
}

Exercici& Exercici::operator=(const Exercici& e)
{
	if (this != &e) 
	{
		m_descripcio = e.m_descripcio;
		m_dataLimit = e.m_dataLimit;
		m_nEstudiants = e.m_nEstudiants;
		delete[] m_lliuraments;
		m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		for (int i = 0; i < m_nEstudiants ; i++)
		{
			m_lliuraments[i] = e.m_lliuraments[i];
		}
	}
	
	return *this;
}

void Exercici::inicialitzaEstudiants(const string& fitxerEstudiants)
{
	ifstream fichero(fitxerEstudiants);
	string textoLinea;
	
	int cont = 0;

	if (fichero.fail())
	{
		cout << "Error al abrir achivo" << fitxerEstudiants << endl;
		exit(1);
	}
	
	//Mientras no sea el final del fichero
	while (!fichero.eof())
	{
		getline(fichero, textoLinea);
		if (cont == 0)
		{
			//creamos el array dinamico
			std::istringstream numEstudiants(textoLinea);
			numEstudiants >> m_nEstudiants;
			m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		}
		else
		{
			m_lliuraments[cont-1].setNiu(textoLinea);
			//string niu =  m_lliuraments[cont - 1].getNiu();
		}
		cont++;
	}
}

void Exercici::addEstudiant(const string& niu, const string& fitxer, const string& data)
{
	m_nEstudiants = m_nEstudiants + 1;
	LliuramentsEstudiant* auxLliuramentsEstudiant;
	auxLliuramentsEstudiant = new LliuramentsEstudiant[m_nEstudiants];
	//copiar contenido
	for (int i = 0; i < m_nEstudiants - 2; i++)
	{
		auxLliuramentsEstudiant[i] = m_lliuraments[i];
		//copiar Tramesas
		std::forward_list<Tramesa>::iterator it;
		for (it = m_lliuraments[i].getTrameses().begin(); it != m_lliuraments[i].getTrameses().end(); it++)
		{
			auxLliuramentsEstudiant[i].afegeixTramesa( it->getFitxer(), it->getData());
		}
	}
	delete[] m_lliuraments;
	
	m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
	m_lliuraments[0].setNiu(niu);
	m_lliuraments[0].afegeixTramesa(fitxer, data);
	for (int i = 1; i < m_nEstudiants - 1; i++) 
	{
		m_lliuraments[i] = auxLliuramentsEstudiant[i];
		//copiar Tramesas
		std::forward_list<Tramesa>::iterator it;
		for (it = auxLliuramentsEstudiant[i].getTrameses().begin(); it != auxLliuramentsEstudiant[i].getTrameses().end(); it++)
		{
			m_lliuraments[i].afegeixTramesa(it->getFitxer(), it->getData());
		}
	}
		


}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	
	bool existeEstudiante = false;
	//Buscamos esutadiante en m_lliuramentes
	for (int i = 0; i < m_nEstudiants; i++)
	{
		string const muyNiu = m_lliuraments[i].getNiu();
		if (m_lliuraments[i].getNiu() == niu)
		{
			existeEstudiante = true;
			m_lliuraments[i].afegeixTramesa(fitxer, data);
			i = m_nEstudiants;
		}
		
	}
	if (!existeEstudiante)
	{
		//addEstudiant(niu, fitxer, data);
	}
	return existeEstudiante;
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	bool existeTramesa = false;

	for (int i = 0; i < m_nEstudiants ; i++)
	{
		string myNiu = m_lliuraments[i].getNiu();
		if (myNiu == niu) {
			if (m_lliuraments[i].consultaTramesa(data, fitxer))
			{
				existeTramesa = true;
				//i = m_nEstudiants;
			}
		}
		
	}

	return existeTramesa;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	bool existeEstudiante = false;
	bool eliminar = false;

	for (int i = 0; i < m_nEstudiants ; i++)
	{
		string myNiu = m_lliuraments[i].getNiu();
		//cout << m_lliuraments[i].getNiu() <<  " esperado " << niu <<endl;
		if ( myNiu == niu)
		{
			
			cout << "----------------------------- Niu encontrado procedemos a eliminar tramesa" << endl;
			existeEstudiante = true;
		 eliminar = m_lliuraments->eliminaTramesa(data);
			i = m_nEstudiants;
		}
		
	}

	if (existeEstudiante && eliminar)
		return true;
	else
		return false;
	
	

	
}
