#pragma once
#include "MatriuSparse.h"
#include <list>
#include "Heap.h"

class Comunitat
{
public:
	//Constructores
	Comunitat(MatriuSparse* pMAdj);
	~Comunitat() ;

	//Funciones
	/** calculaM2(): calcula m_M2
		m_M2 = aristas * 2
		Al tratarse de una matriz simetrica, significa que cada valor que exista en la matriz se repetia, es decir
		cada valor en la matriz simetrica aparecen dos veces. Ademas hay un valor en la matriz por cada arista, signfiica
		que los valoresMatrizSimetrica = aristas * 2
	*/
	void calculaM2() { m_M2 = m_pMAdj->getNValues(); }
	void calculaK() { m_pMAdj->calculaGrau(m_k); };
	void calculaA();
	void creaDeltaQHeap();
	void creaIndexComs();
	void InicialitzaDendrograms(){ m_pMAdj->calculaDendograms(m_vDendrograms); }
	void calculaComunitats(list<Tree<double>*>& listDendrogram);
	void fusiona(int com1, int com2);
	void modificaVei(int com1, int com2, int vei, int cas);
	void generaDendrogram(int pos1, int pos2, double deltaQp1p2);

	//Get
	int getM2() { return m_M2; }
	vector<int> getK() { return m_k; }
	vector<double> getA() { return m_A; }
	vector<map<pair<int, int>, double>> getdeltaQ() {return m_deltaQ;}
	Heap gethTotal() {return m_hTotal;}
	vector<pair<int, int>> getIndexComs() { return m_indexComs; }

	//Clear
	void clear();

	


private:
	//vector de maps per cada fila de deltaQij
	vector<map<pair<int, int>, double>> m_deltaQ;
	//vector que mante llista de comunitats actives amb un parell que indica anterior i seguent activa.
	//la primera te com anterior -1 i la ultima com a seguent la mida del vector
	vector<pair<int, int>> m_indexComs;
	//vector que mante el maxim de deltaQij d'una fila, per no recalcular innecesariament
	vector<pair<int, double>> m_maxDeltaQFil;
	//index que indica quina es la primera comunitat activa
	int m_primComdeltaQ;
	//Vector d'arbres que va creant el dendograma. Inicialment es un vector amb un arbre per cada node del graf.
	//Cada node fulla te el index del node, cada node intern i l'arrel te el deltaQij que l'ha fet unir-se. Si es negatiu vol dir que no hauriem de fer aquesta unio
	vector<Tree<double>*> m_vDendrograms;
	//Vector de graus dels nodes
	vector<int> m_k;
	//Vector de index aij de cada aresta
	vector<double> m_A;
	//Heap dels maxims deltaQ de cada fila, tindra nfiles elements a l'inici i despres tants com comunitats hi hagi actives
	Heap m_hTotal; // (_mAdjacencia.getNFiles());
	//Modularitat Q de la particio en comunitats calculada
	double m_Q;
	int m_M2;
	MatriuSparse* m_pMAdj;

};