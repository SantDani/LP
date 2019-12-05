#pragma once
#include <vector>
#include <list>
#include <string>
#include <cstdio>
using namespace std;

class Graf
{
public:
	Graf(bool dirigit);
	Graf(vector<string>& nodes, vector<vector<int>> parellesNodes, bool dirigit);
	Graf(vector<string>& nodes, vector<vector<int>> parellesNodes, vector<int> pesos, bool dirigit);
	~Graf();

	int getNumNodes() { return m_numNodes; }

	void inserirAresta(int posNode1, int posNode2);
	void inserirAresta(int posNode1, int posNode2, int pes);
	void eliminarAresta(int posNode1, int posNode2);

	void afegirNode(string node);
	void eliminarNode(string node);

	vector<vector<int>> cicles();
	void mostra();
	int grauOutNode(string node);
	int grauInNode(string node);
	void camins(string node1, string node2);

private:
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	int m_numNodes;
	int m_numArestes;
	bool m_dirigit;

	void crearMatriu(vector<vector<int>> parelles);
	void crearMatriu(vector<vector<int>> parelles, vector<int> pesos);
	void printTotsCaminsFins(int pos1, int pos2, vector<bool> visited, list<int> paths);

};

