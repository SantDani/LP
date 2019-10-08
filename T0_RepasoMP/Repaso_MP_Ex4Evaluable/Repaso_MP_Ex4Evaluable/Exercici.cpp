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
		for (int i = 0; i < m_nEstudiants; i++)
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
			std::istringstream iss(textoLinea);
			iss >> m_nEstudiants;
			m_lliuraments = new LliuramentsEstudiant[m_nEstudiants];
		}
		else
		{
			m_lliuraments[cont-1].setNiu(textoLinea);
			string niu =  m_lliuraments[cont - 1].getNiu();
		}
		cont++;
	}
}

bool Exercici::afegeixTramesa(const string& niu, const string& fitxer, const string& data)
{
	//KHE ???
	/*Nos pide que busquemos si exsite el estudiante
	de esta manera determinamos si podemos add la tramesa,
	en caso que no exista devolvemos FALSE.
	
	Pero si si es la perimera que hace el estudiante se ha de add 
	un nuevo objeto LliuramentEstudiant, esto no tiene sentido ya que, 
	dice que los esudiantes que no existen se ha de volver FALSO,
	 en todo caso seria add el Objeto Tramesa al ForwardList
	 
	 Se puede hacer, pero siempre devolveremos TRUE,
	 ya que, al crear un nuevo LLiuramentEstudiant siempre podemos add la tramesa
	 exista , auqnue, no exista*********************************/
	bool existeEstudiante = false;
	int posEstudiante = 0;
	//Buscamos esutadiante en m_lliuramentes
	for (int i = 0; i < m_nEstudiants - 1 ; i++)
	{
		string const muyNiu = m_lliuraments[i].getNiu();

		if (muyNiu == niu)
		{
			existeEstudiante = true;
			m_lliuraments[i].afegeixTramesa(fitxer, data);
			//i = m_nEstudiants;
		}
		posEstudiante++;
		
	}

	//PRIMERA TRAMESA
	//Si es la primera add un nuevo objeto de tipo LLiuramentEstudiant i afegeixTramesa
	// SI anteriormente ya habia hecho tramesas, recuperar el objete LLiuramenteEstudiant del estudiante y add tramesa
	//Si exsite add nueva tamesa pasando como parametro fixer i date, i deevolver TRUE
	if (existeEstudiante)
	{
		//m_lliuraments[posEstudiante].afegeixTramesa(fitxer, data);
	}
	// SI NO EXISTE estudiante devolver falso

	
	return existeEstudiante;
}

bool Exercici::consultaTramesa(const string& niu, const string& data, string& fitxer)
{
	bool existeTramesa = false;

	for (int i = 0; i < m_nEstudiants -1; i++)
	{
		if (m_lliuraments[i].consultaTramesa(data, fitxer))
		{
			existeTramesa = true;
			i = m_nEstudiants;
		}
	}

	return existeTramesa;
}

bool Exercici::eliminaTramesa(const string& niu, const string& data)
{
	bool existeEstudiante = false;
	bool eliminar = false;

	for (int i = 0; i < m_nEstudiants -1 ; i++)
	{
		if (m_lliuraments[i].getNiu() == niu)
		{
			existeEstudiante = true;
			eliminar = m_lliuraments->eliminaTramesa(data);
			i = m_nEstudiants;
		}
		
	}
	
	if (existeEstudiante && eliminar)
		return true;

	return existeEstudiante;
}
