#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

//Amb col·lisions sondeig quadratic:

class Hash
{
public:
	Hash(int numIni=10, const string& descripcioDefecte="Definicio no existent", int estado = LLIURE) ;
	~Hash();
	string& operator[](const string& clau);
	void insert(const string& clau, const string& descripció);	
	bool find(const string& clau, string& definicio) const;
	bool esborra(const string& clau);
	friend ostream& operator<<(ostream &out, const Hash& h);
	
private:
	int codi(string s) const;
	void insertIntern(const string& clau, const string& descripcio);
	
	std::vector<std::pair<string, string>> m_diccionari;
	
	int m_numOcupats;
	int m_maxElements;
	string m_descripcioDefecte;		

	vector<int> m_estado;

	static const int LLIURE		= 0;
	static const int OCUPAT		= 2;
	static const int ESBORRAT	= 3;
};
