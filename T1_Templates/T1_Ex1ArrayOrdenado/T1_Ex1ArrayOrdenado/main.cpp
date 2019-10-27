#include <iostream>
#include <time.h>
#include "cerca_ordenacio.h"
#include "Persona.h"
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}


template <class T>
bool comparaVectors(T vector1[], T vector2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while ((i < longitud) && iguals)
	{
		if (!(vector1[i] == vector2[i]))
			iguals = false;
		else
			i++;
	}
	return iguals;
}

template <class T>
void escriuValors(T valors[], int nValors)
{
	cout << "[";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << valors[i] << ",";
	}
	if (nValors > 0)
		cout << valors[nValors - 1];
	cout << "]";
}

template <class T>
void copiaVector(T vector1[], T vector2[], int nValors)
{
	for (int i = 0; i < nValors; i++)
	{
		vector2[i] = vector1[i];
	}
}

float testOrdenacio()
{
	float reduccio = 0;

	const int N_PROVES = 3;
	const int LONGITUD_VECTOR_INT = 20;
	const int LONGITUD_VECTOR_PERSONA = 5;

	int vectorEnterTest[N_PROVES][LONGITUD_VECTOR_INT] = {
		{ 9, 8, 7, 6, 5, 15, 17, 16, 19, 18, 0, 1, 2, 3, 4, 14, 13, 12, 11, 10 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 },
		{ 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
	};
	int vectorEnterResultat[LONGITUD_VECTOR_INT] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

	Persona vectorPersonaTest[N_PROVES][LONGITUD_VECTOR_PERSONA] = {
		{ { "NOM_D", 40 } ,{ "NOM_E", 40 }, { "NOM_B", 20 }, { "NOM_C", 30 }, { "NOM_A", 10 } },
		{{"NOM_A", 10}, { "NOM_B", 20 }, { "NOM_C", 30 }, { "NOM_D", 40 }, { "NOM_E", 40 } },
		{ { "NOM_E", 40 },{ "NOM_D", 40 },{ "NOM_C", 30 },{ "NOM_B", 20 },  { "NOM_A", 10 } }
	};

	Persona vectorPersonaResultat[LONGITUD_VECTOR_PERSONA] = { { "NOM_A", 10 },{ "NOM_B", 20 },{ "NOM_C", 30 },{ "NOM_D", 40 },{ "NOM_E", 40 } };

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO ORDENA amb valors de tipus int" << endl;
	cout << "Comment :=>> ===================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector abans ordenar: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorEnterTest[i], LONGITUD_VECTOR_INT);
		cout << endl;
		int vectorEnter[LONGITUD_VECTOR_INT];
		copiaVector(vectorEnterTest[i], vectorEnter, LONGITUD_VECTOR_INT);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant ordenacio....................... " << endl;
		ordena(vectorEnter, LONGITUD_VECTOR_INT);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valors del vector despres ordenar: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorEnter, LONGITUD_VECTOR_INT);
		cout << endl;

		bool correcte = comparaVectors(vectorEnter, vectorEnterResultat, LONGITUD_VECTOR_INT);
		if (correcte)
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO ORDENA amb valors de tipus Persona" << endl;
	cout << "Comment :=>> =======================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector abans ordenar: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorPersonaTest[i], LONGITUD_VECTOR_PERSONA);
		cout << endl;
		Persona vectorPersona[LONGITUD_VECTOR_PERSONA];
		copiaVector(vectorPersonaTest[i], vectorPersona, LONGITUD_VECTOR_PERSONA);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant ordenacio....................... " << endl;
		ordena(vectorPersona, LONGITUD_VECTOR_PERSONA);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valors del vector despres ordenar: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorPersona, LONGITUD_VECTOR_PERSONA);
		cout << endl;

		bool correcte = comparaVectors(vectorPersona, vectorPersonaResultat, LONGITUD_VECTOR_PERSONA);
		if (correcte)
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}


	return reduccio;
}


float testCerca()
{
	float reduccio = 0;

	const int N_PROVES = 6;
	const int LONGITUD_VECTOR_INT = 20;
	const int LONGITUD_VECTOR_PERSONA = 5;

	int vectorEnterTest[LONGITUD_VECTOR_INT] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190 };
	int valorCercaEnterTest[N_PROVES] = { 0, 190, 70, 25, 200, -10 };
	bool resultatCercaEnter[N_PROVES] = { true, true, true, false, false, false };

	Persona vectorPersonaTest[LONGITUD_VECTOR_PERSONA] = { { "NOM_A", 10 },{ "NOM_B", 20 },{ "NOM_C", 30 },{ "NOM_D", 40 },{ "NOM_E", 40 } };
	Persona valorCercaPersonaTest[N_PROVES] = { { "NOM_A", 10 },{ "NOM_C", 30 },{ "NOM_E", 40 }, { "NOM_A", 20 },{ "NOM_E", 50 },{ "NOM_A", 5 } };
	bool resultatCercaPersona[N_PROVES] = { true, true, true, false, false, false };

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO CERCA amb valors de tipus int" << endl;
	cout << "Comment :=>> ==================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorEnterTest, LONGITUD_VECTOR_INT);
		cout << endl;
		cout << "Comment :=>> Valor a buscar: " << valorCercaEnterTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant cerca....................... " << endl;
		bool resultat = cercaBinaria(vectorEnterTest, valorCercaEnterTest[i], LONGITUD_VECTOR_INT);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatCercaEnter[i]); cout << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;

		if (resultat == resultatCercaEnter[i])
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	cout << endl;
	cout << "Comment :=>> Iniciant test FUNCIO ORDENA amb valors de tipus Persona" << endl;
	cout << "Comment :=>> =======================================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Valors del vector: " << endl;
		cout << "Comment :=>> ";
		escriuValors(vectorPersonaTest, LONGITUD_VECTOR_PERSONA);
		cout << endl;
		cout << "Comment :=>> Valor a buscar: " << valorCercaPersonaTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Realitzant cerca....................... " << endl;
		bool resultat = cercaBinaria(vectorPersonaTest, valorCercaPersonaTest[i], LONGITUD_VECTOR_PERSONA);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatCercaPersona[i]); cout << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;

		if (resultat == resultatCercaPersona[i])
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}


	const float FACTOR_EFICIENCIA = 0.1;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de EFICIENCIA de la cerca binaria" << endl;
	cout << "Comment :=>> ===============================================" << endl;
	float tempsAcumulatCercaBinaria = 0;
	float tempsAcumulatNoCercaBinaria = 0;
	const int MAX_VECTOR = 100000;
	int vectorTest[MAX_VECTOR];
	int valorTest = 2000000;
	for (int i = 0; i < MAX_VECTOR; i++)
		vectorTest[i] = i * 10;
	clock_t timeCercaBinaria;
	timeCercaBinaria = clock();
	for (int j = 0; j < 10000; j++)
	{
			bool resultat = cercaBinaria(vectorTest, valorTest, MAX_VECTOR);
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
			if (vectorTest[i] >= valorTest)
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

	reduccio = testOrdenacio();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade += (5.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testCerca();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade += (5.0 - reduccio);
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