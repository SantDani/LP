#include "Biblioteca.h"
#include "Llibre.h"
#include "Revista.h"
#include <fstream>
#include <iostream>
#include<vector>


using namespace std;




void Biblioteca::afegirLlibre(const Llibre& l)
{
	Llibre* llibre = new Llibre(l);
	m_lPublicacio.push_back(new Llibre(l));
}

void Biblioteca::afegirRevista(const Revista& r)
{
	Revista *revista = new Revista(r);
	m_lPublicacio.push_back(revista);
}

void Biblioteca::llegirPublicacions(const string& nomFitxer)
{
	ifstream fitxer;
	string codi;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		cout << codi;
		while (!fitxer.eof())
		{
			
			fitxer >> codi;
			cout << codi;
			if (codi == LLIBRE)
			{
				string  titol, autor;
				int nCopies, nDiasPrestec;
				fitxer >> codi >> titol >> autor >> nCopies >> nDiasPrestec;
				Llibre llibre(codi, titol, autor,  nCopies, nDiasPrestec);
				afegirLlibre(llibre);
			}
			else if (codi == REVISTA)
			{
				string  titol, periodicitat;
				int nExemplars, exemplar;
				vector<int> lExemplars;
				fitxer >> codi >> titol >> periodicitat >> nExemplars;
				for (int i = 0; i < nExemplars; i++)
				{
					fitxer >> exemplar;
					lExemplars.push_back( (exemplar));
				}
				Revista revista(codi, titol, periodicitat, nExemplars, lExemplars);
				afegirRevista(revista);

			}
		}
		fitxer.close();
	}
	else
	{
		cout << "error al leer el fichero" << endl;
	}


}

bool Biblioteca::prestar(const string& idUsuari, const string& codi, 
	const Data& dataPrestec, Data& dataRetorn, int nExemplar)
{
	bool prestat = false;
	bool trobat = false;
	//buscar si existe la publicacion
	list<Publicacio*>::iterator it = m_lPublicacio.begin();

	while (!trobat && it != m_lPublicacio.end())
	{
		if ((*it)->getCodi() == codi)//encontrado
		{
			trobat = true;
			if ( (*it)->getTipoClase() == LLIBRE)
			{
				int diasPrestamo = (*it)->getNumDiasPrestec();
				if ((*it)->prestar(1))
				{
					dataRetorn = dataPrestec + (*it)->getNumDiasPrestec();
					prestat = true;
					return true;
				}
				else
				{
					dataRetorn = dataPrestec;
					return false;
				}
				
			}
			else if (((*it))->getTipoClase() == REVISTA)
			{
				
				if ((*it)->prestar(nExemplar))
				{
					dataRetorn = dataPrestec + 30;
					prestat = true;
					return true;
				}
				else
				{
					dataRetorn = dataPrestec;
					return false;
				}
			}
		}
		else
			it++;
	}
	return trobat;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExmplar)
{
	bool prestat = false;
	bool trobat = false;
	list<Publicacio*>::iterator it = m_lPublicacio.begin();

	while (!trobat && it != m_lPublicacio.end())
	{
		if ((*it)->getCodi() == codi)//encontrado
		{
			trobat = true;
			if (((*it))->getTipoClase() == LLIBRE)
			{
				
				if (data <=  )
				{
					
					prestat = true;
					return true;
				}
				else
				{
					dataRetorn = dataPrestec;
					return false;
				}

			}
			else if (((*it))->getTipoClase() == REVISTA)
			{

				if ((*it)->prestar(nExemplar))
				{
					dataRetorn = dataPrestec + 30;
					prestat = true;
					return true;
				}
				else
				{
					dataRetorn = dataPrestec;
					return false;
				}
			}
		}
		else
			it++;
	}
}
