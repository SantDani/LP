#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
class TreeRB {
public:

	TreeRB() { m_left = NULL; m_right = NULL; m_father = NULL; m_data = NULL;  m_color = RED; };
	TreeRB(string nomFitxer);
	TreeRB(const TreeRB<T>& t);
	void setVal(const T& val) {m_data = val; };
	~TreeRB();
	bool isLeave() const { return ((m_left == NULL) && (m_right == NULL)); }
	bool isEmpty() const { return (m_data == NULL);}
	TreeRB<T>* getRight(){return m_right;}
	TreeRB<T>* getLeft() { return m_left; }
	T& getData() { return (*m_data); }
	bool cerca(const T& val, TreeRB<T>*& valTrobat);
	//los tres siguientes los implementamos
	TreeRB<T>* oncle();
	bool esFillDret();
	bool esFillEsq();
	friend std::ostream& operator<<(std::ostream& out, const TreeRB<T>& t)
	{
		t.coutArbreRec(0, out);
		return out;
	};
	
	void insert(T& val);

private:
	enum COLOR { RED, BLACK };//add para trabajar con colores. Black-Red
	COLOR m_color;//add para trabajar con colores. Black-Red

	TreeRB<T>* m_left;
	TreeRB<T>* m_right;
	TreeRB<T>* m_father;
	T* m_data;
	

	void arreglaREDRED(TreeRB<T>* nouNode);
	void TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father);
	std::ostream& coutArbreRec(int n, std::ostream& out) const;
	void rota(TreeRB<T>* nouNode, TreeRB<T>* pPare, TreeRB<T>* pAvi);
	void swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2);
	void rotaEsq(TreeRB<T>* pNode);
	void rotaDreta(TreeRB<T>* pNode);
	void swapRootContents( TreeRB<T>* &pOldRoot, TreeRB<T>* &pNewRoot);
};


template<class T>

template<class T>
TreeRB<T>::TreeRB(const TreeRB<T>& t)
{
	m_color = t.m_color;

	if (t.m_left != NULL)
	{
		m_left = new(TreeRB<T>);
		m_left = t.m_left;
	}
	else
	{
		m_left = NULL;
	}

	if (t.m_right != NULL)
	{
		m_right = new(TreeRB<T>);
		m_right = t.m_right;
	}
	else
	{
		m_right = NULL;
	}
	//m_father: here m_father must be NULL
	//we are creating a TreeRB, if it has to be connected with another one you will use setRight o r left.
	m_father = NULL;

	if (t.m_data != NULL)
	{
		m_data = new(T);
		m_data = t.m_data;
	}
	else
	{
		m_data = NULL;
	}
}

template<class T>
bool TreeRB<T>::esFillDret()
{
	//FER CODI
	if (m_father == NULL)
		return false;
	else
		return (this == m_father->m_right);//comparacion devuelvo true o false dependiendo si la condicion se cumple
}

template<class T>
bool TreeRB<T>::esFillEsq()
{
	//FER CODI
	if (m_father == NULL)
		return false;
	else
		if (m_father->m_left)
			return true;
		else
			return false;
		//return (this == m_father->m_left);

}

template<class T>
TreeRB<T>* TreeRB<T>::oncle()
{
	//FER CODI
	if (m_father == NULL)
		return NULL;
	else
		if (m_father->m_father == NULL)
			return NULL;
		else
			if (m_father->esFillDret())
				return m_father->m_father->m_right;
			else
				return m_father->m_father->m_lef;
}

template<class T>
void TreeRB<T>::swapColor(TreeRB<T>* pNod1, TreeRB<T>* pNod2)
{
	//FER CODI
	COLOR aux = pNod1->m_color;
	pNod1->m_color = pNod2->m_color;
	pNod2->m_color = aux;
}

template<class T>
void TreeRB<T>::swapRootContents( TreeRB<T>* &pOldRoot, TreeRB<T>* &pNewRoot){
	//FER CODI
}


template<class T>
void TreeRB<T>::rotaDreta(TreeRB<T>* pNodAct)
{
	//El pNodAct es avi o pare que pasara a ser fill dret del seu fillesquerre
	//El fill esquerre de pNodAct passara a ser pare
	//El fill dret del fill esquerre de pNodAct (si no es NULL) passara a ser el fill esquerre de l'avi (pNodAct)

	//Com avi pot ser l'arrel no movem node de lloc
	//intercanviem node pNodAct amb pFE i modifiquem els seus fills i pares de la seguent manera

	//FER CODI

	// el nodo enviado es el yayo es el 15

	//Codigo solucion
	TreeRB<T> pVesavi = pNodAct->m_father->m_father;
	TreeRB<T> pFE = pNodAct->m_left;


	if (pBesavi != NULL)
	{
		if (pNodAct->esFillDret())
		{
			pBesavi->m_right = pFE;
		}
		else
		{
			pBesavi->m_left = pFE;
		}
		pFE->m_father = pBesavi;

		//Fem que el fill dret de l0avi apunto a T1
		pNodAct->m_right = pFD->m_left;
		if (pFD->m_left)
		{
			pFD->m_left->m_father = pNodoAct;

		}
		pNodAct->m_father = pFD;
		pFD->m_left = pNodAct;
	}
	else
	{
		this->swapRootContents(pNodAct, pFE);
	}
}

template<class T>
void TreeRB<T>::rotaEsq(TreeRB<T>* pNodAct)
{
	//El pNode es avi que pasara a ser fill esquerre del seu filldret
	//El fill dret passara a ser el pare
	//El fill esquerre del fill dret passara a ser el fill dret de l'avi (pNode)

	//Com avi pot ser l'arrel no movem node de lloc
	//FER CODI

	TreeRB<T> *pVesavi = pNodAct->m_father;
	TreeRB<T> *pFD = pNodAct->m_right;


	if (pBesavi != NULL)
	{
		if (pNodAct->esFillDret())
		{
			pBesavi->m_right = pFD;
		}
		else
		{
			pBesavi->m_left = pFD;
		}
		pFD->m_father = pBesavi;
	}
	else
	{
		this->swapRootContents(pNodAct, pFD);
	}


}


template<class T>
void TreeRB<T>::rota(TreeRB<T>* nouNode, TreeRB<T>* pPare, TreeRB<T>* pAvi)
{
	//FER CODI

	// si el padre y el nuevo hijo es esquerra swap color
	//	si el hijo es derecha rota dreta

	if (pPare->esFillEsq())
	{
		if (nouNode->esFillEsq())
		{
			//Esquerre-esquerre
			
		}
	}

}

template<class T>
void TreeRB<T>::arreglaREDRED(TreeRB<T>* nouNode)
{
	//FER CODI
	//primero hay que hacer oncle, esFillDret, esFillEsq

	if (nouNode->m_father == NULL)
		// no tenemos padre, por lo tanto es la raiz
		nouNode->m_color = BLACK;
	else
	{
		
		if(nouNode->m_father->m_color != BLACK)
			//Sie el padre es black ya hemo acabat
			if(nouNode->m_father->m_color != BLACK)
				if (oncle() != NULL) // Oncle NULL es com NEGRE
				{
					if (nouNode->oncle()->m_color == RED)
					{
						nouNode->m_father->m_color = BLACK;
						nouNode->oncle()->m_color = BLACK;
						nouNode->m_father->m_father->m_color = RED;
						arreglaREDRED(pAvi);
					}
					else if (nouNode->oncle->m_color == BLACK)
					{
						//rota
						
					}
				}
				else //if(oncle() == NULL)
				{
					//rota{}
				}
	}
		
}

template<class T>
void TreeRB<T>::insert(T& val)
{
	if (m_data == NULL)
	{//Arbre buit
		m_data = new T;
		(*m_data) = val;
		m_color = BLACK;
	}
	else
	{
		TreeRB<T>* ptAux=nullptr;
		bool trobat = cerca(val, ptAux);
		if (!trobat)
		{//Si trobem valor no fem res; si no el trobem

			//Creem un node RED amb valor val fill de ptAux
			TreeRB<T>* nouNode = new TreeRB<T>;
			nouNode->m_data = new T;
			(*nouNode->m_data) = val;
			nouNode->m_father = ptAux;

			if (val < (*ptAux->m_data))
			{//El nou valor sera fillEsq de ptAux
				ptAux->m_left= nouNode;
			}
			else
			{//El nou valor sera fillDret de ptAux
				ptAux->m_right= nouNode;
			}

			arreglaREDRED(nouNode);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// TreeRB(nomFitxer):                                                        //
//                 constructor que obre fitxer i crida a metode privat     //
// TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)              //
//            metode privat que llegeix arbre de forma recursiva           //
//Lectura d'un fitxer a on tindrem                                         //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en preordre Preordre(FillEsq) Arrel Preordre(FillDret)                //
/////////////////////////////////////////////////////////////////////////////
template<class T>
TreeRB<T>::TreeRB(string nomFitxer)
{
	ifstream fitxerNodes;

	fitxerNodes.open(nomFitxer.c_str());
	if (fitxerNodes.is_open())
	{
		//Llegim alçada arbre binari
		int h;
		fitxerNodes >> h;
		if (!fitxerNodes.eof())
		{
			int estat;
			fitxerNodes >> estat;
			if (estat == 1)
			{
				if (fitxerNodes.is_open())	TreeRBRec(fitxerNodes, h, NULL);
			}
		}
		fitxerNodes.close();
	}
}

template<class T>
void TreeRB<T>::TreeRBRec(ifstream& fitxerNodes, int h, TreeRB<T>* father)
{
	m_father = father;
	m_data = new(T);
	fitxerNodes >> (*m_data);
	if (h > 0)
	{
		int estat;
		if (!fitxerNodes.eof())
		{			
			fitxerNodes >> estat;
			if (!fitxerNodes.eof())
			{
				if (estat == 1)
				{
					m_left = new(TreeRB<T>);
					m_left->TreeRBRec(fitxerNodes, h - 1, this);
				}
			}
		}
		if (!fitxerNodes.eof())
		{
			fitxerNodes >> estat;
			if (!fitxerNodes.eof())
			{
				if (estat == 1)
				{
					m_right = new(TreeRB<T>);
					m_right->TreeRBRec(fitxerNodes, h - 1, this);
				}
			}
		}
	}
}


template<class T>
TreeRB<T>::~TreeRB()
{
	if (m_right != NULL)
	{
		delete m_right;
	}

	if (m_left != NULL)
	{
		delete m_left;
	}

	if (m_data != NULL)
	{
		delete m_data;
	}

	m_father = NULL;
}

//Suposem l'arbre ordenat amb valors menors a arrel a esquerra i valors majors a dreta
template<class T>
bool TreeRB<T>::cerca(const T& val, TreeRB<T>*& valTrobat)
{
	if (m_data != NULL)
	{
		if (val == (*m_data))
		{
			valTrobat = this;
			return true;
		}
		else
			if (val < (*m_data))
			{
				if (m_left != NULL)
				{
					return m_left->cerca(val, valTrobat);
				}
				else
					valTrobat = this;//para que devuelva el ultimo nodo visitado
			}
			else
			{
				if (m_right != NULL)
				{
					return (m_right->cerca(val, valTrobat));
				}
				else
					valTrobat = this;//para que devuelva el ultimo nodo visitado
			}		
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////////
// coutArbreRec():                                                         //
//         Metode privat cridat per operator<<                             //
//                       que escriu arbre per pantalla de forma recursiva  //
// |--arrel                                                                //
// |---->FillDret1                                                         //
// |------>FillDret2                                                       //
// |------>FillEsquerre2                                                   //
// |---->FillEsquerre1                                                     //
//alcada                                                                   //
//estat: 0 o 1 segons sigui buit o amb informacio al costat dada           //
//Esta en inordre Inordre(FillEsq) Arrel Inordre(FillDret)                 //
/////////////////////////////////////////////////////////////////////////////
template<class T>
std::ostream& TreeRB<T>::coutArbreRec(int n, std::ostream& out) const
{
	if (isEmpty())
	{//Pintem arbre buit
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "-->BUIT" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			out << "|--";
		}
		out << "|-->";
		if (m_color == RED)
			out << "RED,";
		else
			out << "BLACK,"; 
		out << (*m_data) << endl;
		if (!isLeave())
		{
			if (m_left != NULL)
			{
				m_left->coutArbreRec(n + 1,out);
			}
			else
			{
				for (int i = 0; i < n + 1; i++)
				{
					out << "|--";
				}
				out << "|-->BUIT" << endl;
			}
			if (m_right != NULL)
			{
				m_right->coutArbreRec(n + 1,out);
			}
			else
			{
				for (int i = 0; i < n + 1; i++)
				{
					out << "|--";
				}
				out << "|-->BUIT" << endl;
			}
		}
	}
	return out;
}
