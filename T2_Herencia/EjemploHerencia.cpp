//Ejemplo clase base
class Producte
{
public:
	Producte() {} //imprimir que tipo de constructor es //inicializar los valores
	~Producte() {}

	Producte(string codi, float preu) { m_codi = codi, m_preu = preu; }
	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }

	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }
private:
	string m_codi;
	float m_preu;
};

//Ejemplo clase derivada, hay que indicar que es PUBLICO
//Impotante los tipos de constructores
class Llibre : public Producte
{
public:
	//Constructores
	//Constructor por defecto
	Llibre() { m_titol = ""; m_autor = ""; m_numPagines = 0; }
	//Constructor por valores
	Llibre(string codi, float preu, string titol, string autor, int numPag)
		:Producte(codi, preu) {
		m_titol = titol; m_autor = autor; m_numPagines = numPag;
	}
	//Constructor copia
	Llibre(const Llibre& l)
		: Producte(l) {m_titol = l.m_titol; m_autor = m_autor; m_numPagines = l.m_numPagines;}
	void setTitol(string titol) { m_titol = titol; }
	void setAutor(string autor) { m_autor = autor; }
	void setnPagines(int numPag) { m_numPagines = numPag; }

	string	getTitol() const { return m_titol; }
	string	getAutor() const { return m_autor; }
	int		getNPagines() const { return m_numPagines; }
	virtual void mostra();

private:
	string m_titol;
	string m_autor;
	int m_numPagines;
};

//Funciones virtuales
/*Quermeos que muestre toda la informacion del producto. Sea llibro o electrodomestico, llamando a la funcion muestra.
Para ello hay que decirle que en cada caso llame al mostra de las clases derivadas*/
// En la clase vase hay que add virtual en la funcion "base"
class Producte
{
public:
	...
		virtual void mostra();
	...
};

class Electrodomestic : public Producte
{
public:
	...
		void mostra();
	...
};

// Despues para indicar en cada clase derivada que imprima los elementos comunes hay que add Producte::mostra();
void Electrodomestic::mostra()
{
	Producte::mostra();// add codio para que imprima la informacion de la clase base
	cout << "Marca: " << m_marca << endl;
	cout << "Model: " << m_model << endl;
	cout << "Volum: " << m_volum << endl;
}

//-------------------- END

//Eliminar elemento de una lista de apuntadores

class Electrodomestic : public Producte
{
public:
	...
	
private:
	list<Producte*> m_lProducte;
};


bool LListaProductes::EliminaProducte(const string& codi)
{
	bool trobat = false;
	list<Producte*>::iterator itActual = m_lProducte.begin();

	while (!trobat && itActual != m_lProducte.end())
	{
		string normalGet = (*itActual)->getCodi();

		if ((*itActual)->getCodi() == codi)
		{
			delete* itActual;//elimino el elemento PRoducto
			trobat = true;
			m_lProducte.erase(itActual);//elimino la direccion de memoria del eelemento
		}
		else
			itActual++;
	}

	return trobat;
}

//-------------------- END

// Clone /clonar

//Metodo Clone, este devuelve un apuntador a un nuevo objeto dinamico de la clase inicializada como una copia del objeto actual

class Producte
{
public:
	...
		virtual Producte* clone() { return new Producte(*this); }
	...
};

class Electrodomestic : public Producte
{
public:
	...
		//Redifinimos el metodo cambiando el tipo de retorno, que ahora es un apuntodor de Elecrrodomestico apuntador i cambiando el objeto dinamico a electrodomestico
		Electrodomestic* clone() { return new Electrodomestic(*this); }
	...
private:
	list<Producte*> m_lProducte;
};

//Clase abastracta 
/* Esta clase al tener una o mas funciones virtuales pura se convierte
en una clase ABSTRACRA.
	1- NO se pueden crear objetos de Producto
	2- SI se pueden declarar apuntadores a objetos de las clases abstractas (manipular objetos de las clases derivadas)
		Producte *p = new Llibre;
		...
		p->mostra();
	3- Las clases abstratas perimiet definir una interface publica que todas las clases derivadas
		han de tener i redefinir de forma especifica.*/
class Producte
{
public:
	...

	//Metodo Clone, este devuelve un apuntador a un nuevo objeto dinamico de la clase inicializada como una copia del objeto actual
		//virtual Producte* clone() { return new Producte(*this); } = 0;
	//Modificamos el clone anterior para que sea una funcion virutal pura
		//Estas solo las llaman las clases derivadas y por tanto ellas mimsas las definen.
		//las funciones virtuales puras no hacen falta definirlas, solo si es necesario como en el caso de mostra
	virtual Producte* clone() = 0;
	virtual float calculaPreu(int nUnitat) = 0;
	virtual float calculaDespesesEnviament() = 0;
	virtual void mostra() = 0;
	...

};
