#pragma once
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
	Graf();
	Graf(vector<string>& nodes, vector<vector<int>> parelles_nodes);
	~Graf();

	int getNumNodes() { return m_numNodes; }
	
	void inserirAresta(int posNode1, int posNode2);
	void eliminarAresta(int posNode1, int posNode2);

	void afegirNode(string node);
	void eliminarNode(string node);

	vector<vector<int>> cicles();
	void mostra();

private:
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	int m_numNodes;
	int m_numArestes;

	void crearMatriu(vector<vector<int>> parelles);
	
};
