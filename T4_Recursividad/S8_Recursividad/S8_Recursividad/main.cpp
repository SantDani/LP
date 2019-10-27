#include <iostream>
#include <vector>

using namespace std;
float potencia(float base, float exponente);
int QueFa(int v[], int n);



int main()
{
	float base, exponente ;
	cout << "base? exponente?" << endl;
	//float resultado = potencia(base, exponente);


	////////////////////// QUE FA
	int n = 5, resultado = 0;
	int vec[] = {3,5,7,4,6};
	
	for (int i = 0; i < n; i++)
	{
		//resultado = vec[n-1]* +vec[n - i;
	}

	

}

float potencia(float base, float exponente)
{
	float res;
	if (exponente == 0)
	{
		return 1;
	}
	else if (exponente > 0)
	{
		res = (base * potencia(base, exponente - 1));
	}
	else
	{
		res = (1 / base) * potencia(base, exponente + 1);
	}

	return res;
}

int QueFa(int v[], int n)
{
	return 0;
}

float invertirNumero(float numero)
{
	float iteracion = 0;
	return  invertirInternoRecursivo(numero, iteracion);
}

float invertirInternoRecursivo(int numero, int& iteracion)
{
	int resultat = 0;
	if (numero < 10)
		return numero;
	else 
	{
		resultat = resultat + invertirInternoRecursivo(numero / 10, iteracion);
		p = p * 10;
		resultat = resultat + p * (numero % 10);
	}
	return 0;
}
