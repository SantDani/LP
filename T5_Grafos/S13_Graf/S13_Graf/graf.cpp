#include "graf.h"
#include <iostream>
#include <iomanip>

using namespace std;


Graf::Graf()
{
	m_numNodes = 0;
	m_numArestes = 0;
}

Graf::Graf(vector<string>& nodes, vector<vector<int>> parelles_nodes)
{
	m_nodes = nodes; 
	m_numNodes = m_nodes.size();	
	m_numArestes = parelles_nodes.size();
	crearMatriu(parelles_nodes);
}

Graf::~Graf()
{
}

void Graf::crearMatriu(vector<vector<int>> parelles)
{
	// IMPLEMENTAR
	m_matriuAdj.resize(m_numNodes);//creamos el vecor que contendra el resto de vectores
	/*Inicializamos dimeniones de matriz de adj*/
	for (int i = 0; i < m_numNodes; i++)
	{
		//creamos la matriz de dos dimensiones
		m_matriuAdj[i].resize(m_numNodes, 0);
	}
	/*ahora hay que indiar en la matriz las relaciones*/

	for (int i = 0; i < m_numNodes; i++)
	{
		for (int j = 0; j < parelles[i].size(); j++)
		{
			m_matriuAdj[parelles[i][0]] [parelles[i][1]] = 1;
			m_matriuAdj[parelles[i][1]] [parelles[i][0]] = 1;
		}
	}
	


}

void Graf::inserirAresta(int posNode1, int posNode2)
{
	if (m_matriuAdj[posNode1][posNode2] == 0)
	{
		m_matriuAdj[posNode1][posNode2] = 1;
		m_matriuAdj[posNode2][posNode1] = 1;
		m_numArestes++;
	}
}

void Graf::eliminarAresta(int posNode1, int posNode2)
{
	if (m_matriuAdj[posNode1][posNode2] != 0)
	{
		m_matriuAdj[posNode1][posNode2] = 0;
		m_matriuAdj[posNode2][posNode1] = 0;
		m_numArestes--;
	}
}

void Graf::afegirNode(string node)
{
	//m_nodes.resize(m_numNodes);
	m_nodes.push_back(node);

	// add a row
	m_matriuAdj.push_back(std::vector<int>(m_numNodes));

	m_numNodes++;

	//m_matriuAdj.resize(m_numNodes);
	for (int i = 0; i < m_numNodes; i++) m_matriuAdj[i].push_back(0);
}

void Graf::eliminarNode(string node)
{
	//busquem la posició del node a esborrar
	vector<string>::iterator it;
	
	it = find(m_nodes.begin(), m_nodes.end(), node);

	//eliminem el node del vector de nodes i de la matriu d'adjacencia
	if (it != m_nodes.end())
	{
		int pos = distance(m_nodes.begin(), it);
		// eliminem el node del vector de nodes
		m_nodes.erase(m_nodes.begin() + pos);

		// eliminem la fila i la columna de la matriu d'adjacencia corresponents a aquest node
		m_matriuAdj.erase(m_matriuAdj.begin() + pos);

		for (int i = 0; i < m_numNodes; i++)
		{			
			m_matriuAdj[i].erase(m_matriuAdj[i].begin() + pos);
		}
		m_numNodes--;
	}
}

vector<vector<int>> Graf::cicles()
{
	for (int fila = 0; fila < m_numNodes; fila++)
	{
		for (int col = 0; col < m_numNodes ; fila++)
		{
			if(m_matriuAdj[fila][col] == 1)
				for (int vecino = col; vecino < m_numNodes; vecino++)
				{
					
				}
		}
	}
	return vector<vector<int>>();
}

void Graf::mostra()
{
	int mida_c = 4;
	// imprimim el nom dels vèrtexs
	cout << setw(mida_c) << " ";
	for (int j = 0; j < m_numNodes; j++)
	{

		cout << setw(mida_c) << m_nodes[j] << " ";
	}
	cout << endl;

	for (int i = 0; i < m_numNodes; i++)
	{
		cout << setw(10) << m_nodes[i] << " ";
		for (int j = 0; j < m_numNodes; j++)
		{			
			cout << setw(mida_c) << m_matriuAdj[i][j] << " ";
		}
		cout << endl;
	}	
}

