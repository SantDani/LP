#include "graf.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


Graf::Graf(bool dirigit)
{
	m_numNodes = 0;
	m_numArestes = 0;
	m_dirigit = dirigit;
}

Graf::Graf(vector<string>& nodes, vector<vector<int>> parellesNodes, bool dirigit)
{
	m_nodes = nodes; 
	m_numNodes = m_nodes.size();
	m_dirigit = dirigit;
	crearMatriu(parellesNodes);
}

Graf::Graf(vector<string>& nodes, vector<vector<int>> parellesNodes, vector<int> pesos, bool dirigit)
{
	m_nodes = nodes;
	m_numNodes = m_nodes.size();
	m_dirigit = dirigit;
	crearMatriu(parellesNodes, pesos);
}


Graf::~Graf()
{
}

void Graf::crearMatriu(vector<vector<int>> parelles)
{
	m_matriuAdj.resize(m_numNodes);
	for (int i=0; i<m_numNodes;i++)
	{
		m_matriuAdj[i].resize(m_numNodes,0);
	}

	for (int i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = 1;
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = 1;
	}
}

void Graf::crearMatriu(vector<vector<int>> parelles, vector<int> pesos)
{
	m_matriuAdj.resize(m_numNodes);
	for (auto &it : m_matriuAdj)
	{
		it.resize(m_numNodes);
	}

	for (int i = 0; i < parelles.size(); i++)
	{
		m_matriuAdj[parelles[i][0]][parelles[i][1]] = pesos[i];
		if (!m_dirigit)
			m_matriuAdj[parelles[i][1]][parelles[i][0]] = pesos[i];
	}
}

void Graf::inserirAresta(int posNode1, int posNode2)
{
	m_matriuAdj[posNode1][posNode2] = 1;
	if (!m_dirigit)
		m_matriuAdj[posNode2][posNode1] = 1;
}

void Graf::inserirAresta(int posNode1, int posNode2, int pes)
{
	m_matriuAdj[posNode1][posNode2] = pes;
	if (!m_dirigit)
		m_matriuAdj[posNode2][posNode1] = pes;
}


void Graf::eliminarAresta(int posNode1, int posNode2)
{
	m_matriuAdj[posNode1][posNode2] = 0;
	if (!m_dirigit)
		m_matriuAdj[posNode2][posNode1] = 0;
}

void Graf::DFS(string nodeInicial, queue<string>& recorregut)
{
	vector<string>::iterator itNode;
	
	itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);

	if (itNode != m_nodes.end())
	{

		//int pos = distance(m_nodes.begin(), m_nodes.end(), itNode);

	}

}

void Graf::DFSRec(int pos, queue<string>& recorregut, vector<bool>visitat)
{
	visitat[pos] = true;
	recorregut.push(m_nodes[pos]);

	for(int col=0; col<m_numNodes; col++)
		if ((m_matriuAdj[pos][col]) && visitat[col]) {
			DFSRec(col, recorregut, visitat);
		}
}

void Graf::BFS(string nodeInicial, queue<string>& recorregut)
{
	vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);

	if (itNode != m_nodes.end())
	{
		vector<bool> visitat;
		visitat.resize(m_numNodes, false);
		queue<int> pendents;
		int pos = distance(m_nodes.begin(), itNode);
		pendents.push(pos);

		while (pendents.size() < m_numNodes)
		{
			int nodeActual = pendents.front();
			pendents.pop();
			recorregut.push(m_nodes[nodeActual]);
			for (int col = 0; col < m_numNodes; col++)
			{
				if ((m_matriuAdj[pos][col] != 0) && !visitat[col])
				{
					pendents.push(col);
					visitat[col] = true;
				}
			}
		
		}
	}
}

void Graf::afegirNode(string node)
{
	m_nodes.push_back(node);

	// add a row
	m_matriuAdj.push_back(std::vector<int>(m_numNodes));

	m_numNodes++;

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
		m_nodes.erase(it);

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
	vector<vector<int>> parades_cicles;
	int total_cicles = 0;

	for (int fila = 0; fila < m_numNodes; fila++)
	{
		for (int col = fila+1; col < m_numNodes; col++)
		{
			if (m_matriuAdj[fila][col] == 1)
			{
				for (int tercerVei = col+1; tercerVei < m_numNodes; tercerVei++)
				{
					if ((m_matriuAdj[fila][tercerVei] == 1) && (m_matriuAdj[col][tercerVei] == 1))
					{
						total_cicles++;
						parades_cicles.push_back({fila,col,tercerVei});
					}
				}
			}
		}
	}
	return parades_cicles;
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

int Graf::grauOutNode(string node)
{
	//IMPLEMENTAR
	return 0;
}

int Graf::grauInNode(string node)
{
	//IMPLEMENTAR
	return 0;
}

void Graf::printTotsCaminsFins(int pos1, int pos2, vector<bool> visited, list<int> paths)
{
	//IMPLEMENTAR
}


