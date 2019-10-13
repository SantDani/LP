#include <iostream>
#include <time.h>
#include "cerca.h"
#include <utility>
#include "Persona.h"
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}


template <class T1, class T2>
void escriuValors(pair<T1,T2> valors[], int nValors)
{
	cout << "[";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << "<" << valors[i].first << "," << valors[i].second << ">" << ", ";
	}
	if (nValors > 0)
		cout << "<" << valors[nValors-1].first << "," << valors[nValors - 1].second << ">";
	cout << "]";
}

template <class T1, class T2>
void copiaVector(pair<T1, T2> valors[], T1 vector1[], T2 vector2[], int nValors)
{
	for (int i = 0; i < nValors; i++)
	{
		valors[i].first = vector1[i];
		valors[i].second = vector2[i];
	}
}


float testCerca()
{
	float reduccio = 0;

	const int N_PROVES = 6;
	const int LONGITUD_VECTOR_PERSONA = 5;

	Persona vectorPersonaTest[LONGITUD_VECTOR_PERSONA] = { { "NOM_A", 10 },{ "NOM_B", 20 },{ "NOM_C", 30 },{ "NOM_D", 40 },{ "NOM_E", 40 } };
	string vectorClauStringTest[LONGITUD_VECTOR_PERSONA] = { "NOM_A", "NOM_B","NOM_C","NOM_D","NOM_E" };
	int vectorClauIntTest[LONGITUD_VECTOR_PERSONA] = { 100, 200, 300, 400, 500 };
	string valorCercaStringTest[N_PROVES] = { "NOM_A", "NOM_C" , "NOM_E", "A", "Z", "NOM_AA" };
	int valorCercaIntTest[N_PROVES] = { 100, 300, 500, 50, 1000, 150 };
	bool resultatCerca[N_PROVES] = { true, true, true, false, false, false };
	int indexCerca[N_PROVES] = { 0, 2, 4, -1, -1, -1 };

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO CERCA a PERSONA amb clau de tipus STRING (NOM)" << endl;
	cout << "Comment :=>> ===================================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector: " << endl;
		cout << "Comment :=>> ";
		pair<string, Persona> vectorTest[LONGITUD_VECTOR_PERSONA];
		copiaVector(vectorTest, vectorClauStringTest, vectorPersonaTest, LONGITUD_VECTOR_PERSONA);
		escriuValors(vectorTest, LONGITUD_VECTOR_PERSONA);
		cout << endl;
		cout << "Comment :=>> Valor a buscar: " << valorCercaStringTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant cerca....................... " << endl;
		Persona valor;
		bool resultat = cercaBinaria(vectorTest, valorCercaStringTest[i], LONGITUD_VECTOR_PERSONA, valor);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatCerca[i]); cout << endl;
		if (resultatCerca[i])
			cout << "Comment :=>> Valor esperat: " << vectorPersonaTest[indexCerca[i]] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat)
			cout << "Comment :=>> Valor obtingut: " << valor << endl;
		if (resultat == resultatCerca[i])
		{
			if (resultat == true)
				if (valor == vectorPersonaTest[indexCerca[i]])
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{

		}
	}

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO CERCA a PERSONA amb clau de tipus STRING (NOM)" << endl;
	cout << "Comment :=>> ===================================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector: " << endl;
		cout << "Comment :=>> ";
		pair<int, Persona> vectorTest[LONGITUD_VECTOR_PERSONA];
		copiaVector(vectorTest, vectorClauIntTest, vectorPersonaTest, LONGITUD_VECTOR_PERSONA);
		escriuValors(vectorTest, LONGITUD_VECTOR_PERSONA);
		cout << endl;
		cout << "Comment :=>> Valor a buscar: " << valorCercaIntTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant cerca....................... " << endl;
		Persona valor;
		bool resultat = cercaBinaria(vectorTest, valorCercaIntTest[i], LONGITUD_VECTOR_PERSONA, valor);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatCerca[i]); cout << endl;
		if (resultatCerca[i])
			cout << "Comment :=>> Valor esperat: " << vectorPersonaTest[indexCerca[i]] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat)
			cout << "Comment :=>> Valor obtingut: " << valor << endl;
		if (resultat == resultatCerca[i])
		{
			if (resultat == true)
				if (valor == vectorPersonaTest[indexCerca[i]])
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{

		}
	}

	const float FACTOR_EFICIENCIA = 0.3;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de EFICIENCIA de la cerca binaria" << endl;
	cout << "Comment :=>> ===============================================" << endl;
	float tempsAcumulatCercaBinaria = 0;
	float tempsAcumulatNoCercaBinaria = 0;
	const int MAX_VECTOR = 10000;
	pair<int,Persona> vectorTest[MAX_VECTOR];
	int clauTest = 2000000;
	for (int i = 0; i < MAX_VECTOR; i++)
	{
		vectorTest[i].first = i * 10;
		vectorTest[i].second = vectorPersonaTest[0];
	}
		
	clock_t timeCercaBinaria;
	timeCercaBinaria = clock();
	for (int j = 0; j < 10000; j++)
	{
		Persona valor;
		bool resultat = cercaBinaria(vectorTest,  clauTest, MAX_VECTOR, valor);
	}
	timeCercaBinaria = clock() - timeCercaBinaria;
	tempsAcumulatCercaBinaria += (float)timeCercaBinaria / CLOCKS_PER_SEC;

	clock_t timeNoCercaBinaria;
	timeNoCercaBinaria = clock();
	for (int j = 0; j < 10000; j++)
	{
		bool trobat = false;
		int i = 0;
		while (!trobat && (i < MAX_VECTOR))
		{
			if (vectorTest[i].first >= clauTest)
				trobat = true;
			else
				i++;

		}
	}
	timeNoCercaBinaria = clock() - timeNoCercaBinaria;
	tempsAcumulatNoCercaBinaria += (float)timeNoCercaBinaria / CLOCKS_PER_SEC;

	cout << "Comment :=>> Temps per realitzar la cerca binaria: " << tempsAcumulatCercaBinaria << endl;
	cout << "Comment :=>> Temps per realitzar la cerca no binaria: " << tempsAcumulatNoCercaBinaria << endl;
	if (tempsAcumulatCercaBinaria < (FACTOR_EFICIENCIA * tempsAcumulatNoCercaBinaria))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		cout << "Comment :=>> S'esperava una major reduccio del temps al realitzar la cerca binaria" << endl;
		reduccio += 2.0;
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}


	return reduccio;
}


int main()
{
	float grade = 0.0;
	float reduccio;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testCerca();
	if (reduccio > 10.0)
		reduccio = 10.0;
	grade += (10.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;




	return 0;
}