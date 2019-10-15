#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

//Amb col·lisions sondeig quadratic:

class Hash
{
public:
	Hash(int numIni=10, const string& descripcioDefecte="Definicio no existent") ;
	//Hash(int sizeInicial = 15);
	~Hash();
	string& operator[](const string& clau);
	void insert(const string& clau, const string& descripció);	
	bool find(const string& clau, string& definicio) const;
	bool esborra(const string& clau);
	friend ostream& operator<<(ostream &out, const Hash& h);
	
	
private:
	int getIndiceCodigo(string s) const;
	std::vector<std::pair<string, string>> m_diccionari;
	int m_numElements;	
	string m_descripcioDefecte;
};
