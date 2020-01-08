//#include "MatriuSparseCSR.h"
//#include<algorithm> // for heap operations 
#include "Comunitat.h"
#include "MatriuSparse.h"
#include<fstream>
#include <iostream>

using namespace  std;
class Graph
{
public:
	Graph() {};
	Graph(string nomFitxerRels) :m_mAdjacencia(nomFitxerRels){ };
	~Graph() {};
	friend std::ostream& operator<< (std::ostream& os, const Graph& g) { os << g.m_mAdjacencia; return os; };
	void calculaComunitats(list<Tree<double>*>& listDendrogram);
	void clear() { m_mAdjacencia.clear(); }
private:
	MatriuSparse m_mAdjacencia;	
};