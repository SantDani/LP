#include "Llista.h"
#include "Node.h"


Llista::~Llista()
{
	Node* aux;
	
	while (m_primer != NULL)
	{
		aux = m_primer;
		m_primer = m_primer->getNext();
		delete aux;
	}
		
}


Node* Llista::insereixNext(const int& valor, Node* posicio) 
{
	//Creamos el nuevo nodo para poder add
	Node* nuevoNodo = new Node();

	nuevoNodo->setValor(valor);

	
	/*Al insertar Nodo hay dos casos,
	1- Que la lista este vacia por lo tanto hay que ponerlo el primero
	2n - Que hay elementos por lo tanto hay que add a la lista. Por ejemplo al final.
	*/
	//1r - Lista vacia, por lo tanto el primer elemento es NULL
	if (m_primer == NULL)
		m_primer->setNext(nuevoNodo)  ;
	else
	{
		nuevoNodo->setNext(m_primer->getNext());
		m_primer->setNext(nuevoNodo);
	}
			
	return nuevoNodo; // este aux lo tienen en el codigo de ejemplo que no utilizan para nada... EH NP
}

Node* Llista::eliminaNext(Node* posicio) 
{
	/*Determinar que hayan elementos en la lista
	
	Para recorrer una lista creamos dos punteros. 
		Un puntero apuntara al elemento que hay borrar.
		El segundo puntero apuntara a la posicion anterior del puntero a borrar para poder volver
		a enlazar la lista, ya que, al borrar un elemento en entre medio hay que conectar correctamente
		las direcciones de memoria*/
	Node* auxBorrar;
	Node* anterior = NULL;

	if(m_primer != NULL)
	{
		

		auxBorrar = m_primer;

		while ((auxBorrar != NULL) && (auxBorrar->getValor() != posicio->getValor()))
		{
			anterior = auxBorrar;
			auxBorrar = auxBorrar->getNext();
		}

		if (anterior == NULL)
		{
			m_primer = m_primer->getNext();
			delete m_primer;
		}
		else
		{
			anterior->setNext(auxBorrar->getNext());
			delete auxBorrar;
		}
			

	}
	
	return anterior;//este return no tiene sentido, pero en el codigo de ejemplo hacne cosas raras

}