#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "graf.h"
#include "GrafList.h"
#include <stack>

using namespace std;


int main()
{
	int numNodes;

	vector<string> nomsNodes;
	vector<vector<int>> arestes;
	vector<int> pesos;
	queue<string> recorregut;
	stack<string> ordre;

	/**************************************/
	// GRAF DE TASQUES
	/**************************************/

	numNodes = 11;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Tasca 1","Tasca 2","Tasca 3","Tasca 4","Tasca 5","Tasca 6","Tasca 7","Tasca 8","Tasca 9","Tasca 10","Tasca 11" };

	arestes = { {0,1},{0,2},{0,3},{2,1},{2,3},{1,4},{1,5},{3,5},{3,6},{5,4},{5,6},{4,7},{4,8},{6,8},{6,9},{7,8},
	{8,9},{7,10},{8,10},{9,10} };

	pesos = { 5,5,5,7,7,10,10,4,4,6,6,3,3,9,9,1,8,2,8,4 }; //20 pesos

	Graf gTasquesDirigit(nomsNodes, arestes, true);
	Graf gTasquesNoDirigit(nomsNodes, arestes, false);
	Graf gTasquesPonderatDirigit(nomsNodes, arestes, pesos, true);
	/*
	cout << "mostra graf simetric no ponderat:" << endl;
	g.mostra();
	system("PAUSE");
	*/

	/**************************************/
	//GRAF DE METRO
	/**************************************/
	numNodes = 53;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Pl. Sants","Hostafr.","Esp.","Roc.","Urgell","Univ.","Cat.","Urq.","Triomf","Marina","Gl�ries","Clot","Navas","Sagrera",
		"Paral�lel","St. Ant.","Pg. Gr�cia","Tetuan","Monumental","S. Fam�lia","Encants","Bac Roda","Sant Mart�","La Pau",
		"Sants Est.","Tarragona","Poble Sec","Drassanes","Liceu","Diagonal",
		"Bes�s","Bes�s Mar","El Maresme","Selva Mar","Poblenou","Llacuna","Bogatell","Ciutadella","Barcelone.","Jaume I","Girona","Verdaguer","Joanic","Alfons X",
		"Guinard�","Maragall","Llucmajor","Via J�lia",
		"Enten�a","H. Cl�nic","Sant Pau","Camp Arpa","Congr�s" };

	arestes = { { 0,1 },{ 1,2 },{ 2,3 },{ 3,4 },{ 4,5 },{ 5,6 },{ 6,7 },{ 7,8 },{ 8,9 },{ 9,10 },{ 10,11 },{ 11,12 },{ 12,13 },{ 14,15 },{ 15,5 },{ 5,16 },{ 16,17 },{ 17,18 },{ 18,19 },{ 19,20 },{ 20,11 },{ 11,21 },{ 21,22 },
	{ 22,23 },{ 24,25 },{ 25,2 },{ 2,26 },{ 26,14 },{ 14,27 },{ 27,28 },{ 28,6 },{ 6,16 },{ 16,29 },{ 23,30 },{ 30,31 },{ 31,32 },{ 32,33 },{ 33,34 },{ 34,35 },{ 35,36 },{ 36,37 },{ 37,38 },{ 38,39 },{ 39,7 },{ 7,16 },{ 16,40 },{ 40,41 },
	{ 41,42 },{ 42,43 },{ 43,44 },{ 44,45 },{ 45,46 },{ 46,47 },{ 0,24 },{ 24,48 },{ 48,49 },{ 49,29 },{ 29,41 },{ 41,19 },{ 19,50 },{ 50,51 },{ 51,13 },{ 13,52 },{ 52,45 } };

	pesos.resize(numNodes);
	pesos = { 511,995,425,2271,1782,787,375,1603,493,960,1212,499,1181,647,494,124,1794,1607,536,1781,311,708,186,882,1796,1132,1090,1145,2393,1730,620,442,1654,706,292,305,1204,
		617,20,1242,184,655,2034,1170,281,979,1569,990,461,1702,1024,986,647,113,1585,520,962,1339,662,851,1695,1337,622,1290 }; //64 pesos


	Graf gMetroNoDirigit(nomsNodes, arestes, false);
	Graf gMetroNoDirigitPonderat(nomsNodes, arestes, pesos, false);
	Graf gMetroDirigit(nomsNodes, arestes, true);

	GrafList gLMetro(nomsNodes, arestes, false);

	/**************************************/
	//GRAF DE CONNEXIONS
	/**************************************/
	numNodes = 13;
	nomsNodes.resize(numNodes);
	nomsNodes = { "Tu", "Marta", "Maria", "Jordi", "Berta", "Aritz", "Nikita", "Joshua", "Marc", "Mar", "Umair", "Neus", "LA persona" };

	arestes = { { 0,2 },{ 0,3 },{0,8}, { 1,2 },{2,3},{2,5},{ 3,4 },{ 4,6 },{4,7},{ 5,6 },{ 7,12 },{ 8,9 },{ 8,10 },{ 10,11 },{ 10,12 },{ 11,12 } };
	Graf gConnexionsNoDirigit(nomsNodes, arestes, false);

	/**************************************/
	//GRAF PROVA DIJKSTRA
	/**************************************/
	numNodes = 6;
	nomsNodes.resize(numNodes);
	nomsNodes = { "x", "b", "d", "g", "e", "z" };

	arestes = { { 0,1 },{ 0,2 }, { 1,2 },{ 1,3 },{2,3},{2,4},{ 3,4 },{ 3,5 },{4,5} };
	pesos = { 4,2,1,5,8,10,2,6,2 };
	Graf gDijkstraPonderat(nomsNodes, arestes, pesos, false);

	/************************************/
	// CRIDES A M�TODES
	/************************************/

	//DFS
	cout << "mostra graf simetric no ponderat DFS A partir de Tasca 1" << endl;

	gTasquesDirigit.DFS("Tasca 1", recorregut);
	while (!recorregut.empty())
	{
		cout << recorregut.front() << "--> ";
		recorregut.pop();
	}
	cout << endl;
	system("PAUSE");

	//BFS
	cout << "mostra graf simetric no ponderat BFS A partir de Tasca 1" << endl;
	gConnexionsNoDirigit.BFS("Tu", recorregut);
	while (!recorregut.empty())
	{
		cout << recorregut.front() << "--> ";
		recorregut.pop();
	}
	cout << endl;
	system("PAUSE");

	// Dijkstra
	cout << "mostra les distancies amb DIJKSTRA en un graf simetric no ponderat:" << endl;
	vector<int> vDist;
	gDijkstraPonderat.dijkstra(0, vDist);
	for (int i = 0; i < vDist.size(); i++)
	{
		cout << "::" << vDist[i];
	}
	cout << endl;
	system("PAUSE");

	// Dijkstra amb anterior
	cout << "algorisme de DIJKSTRA en un graf simetric no ponderat:" << endl;
	cout << "mostra les distancies finals:" << endl;
	vector<int> vDist;
	vector<int> anterior;

	gMetroNoDirigit.dijkstra(24, vDist, anterior);
	for (int i = 0; i < vDist.size(); i++)
	{
		cout << "::" << vDist[i];
	}
	cout << endl;
	cout << "mostra els nodes anteriors:" << endl;
	for (int i = 0; i < anterior.size(); i++)
	{
		cout << "::" << anterior[i];
	}
	system("PAUSE");

	// Cam� m�s curt
	cout << "mostra el cami minim amb DIJKSTRA en un graf simetric no ponderat:" << endl;
	stack<string> cami;

	gMetroNoDirigit.camiMesCurt("Sants Est.", "Diagonal", cami);

	while (!cami.empty())
	{
		cout << cami.top() << "--> ";
		cami.pop();
	}
	system("PAUSE");

	return 0;
}