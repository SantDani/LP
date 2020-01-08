#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "Graf.h"
#include "GrafList.h"

using namespace std;


int main()
{
	int numNodes = 11;

	vector<string> nomsNodes;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Tasca 1","Tasca 2","Tasca 3","Tasca 4","Tasca 5","Tasca 6","Tasca 7","Tasca 8","Tasca 9","Tasca 10","Tasca 11" };

	vector<vector<int>> arestes;

	arestes = { { 0,1 },{ 0,2 },{ 0,3 },{ 2,1 },{ 2,3 },{ 1,4 },{ 1,5 },{ 3,5 },{ 3,6 },{ 5,4 },{ 5,6 },{ 4,7 },{ 4,8 },{ 6,8 },{ 6,9 },{ 7,8 },
	{ 8,9 },{ 7,10 },{ 8,10 },{ 9,10 } };

	
	Graf g(nomsNodes, arestes, true);

	cout << "mostra graf dirigit no ponderat:" << endl;
	g.mostra();
	system("PAUSE");

	/*
	////////////////////DFS
	cout << "mostra graf dirigit no ponderat DFS A partir de Tasca 2" << endl;
	queue<string> recorregut;
	g.DFS("Tasca 2", recorregut);
	while (!recorregut.empty())
	{
		cout << recorregut.front() << "--> ";
		recorregut.pop();
	}
	cout << endl;
	system("PAUSE");
	*/

	/*
	////////////////////BFS
	
	cout << "mostra graf dirigit no ponderat BFS A partir de Tasca 2" << endl;
	g.BFS("Tasca 2", recorregut);
	while (!recorregut.empty())
	{
		cout << recorregut.front() << "--> ";
		recorregut.pop();
	}
	cout << endl;
	system("PAUSE");
	*/
}