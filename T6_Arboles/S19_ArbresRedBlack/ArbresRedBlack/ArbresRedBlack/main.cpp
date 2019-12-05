#include "TreeRB.hpp"
#include <vector>

int main()
{
	cout << "==============================" << endl;
	cout << "=== CREANT ARBRE RED BLACK ===" << endl;
	cout << "==============================" << endl;
	TreeRB<int> tRB;
	cout <<tRB;
	int MAXVALS = 3;
	vector<int> valors = { 35,15,80 };

	for (int i = 0; i < MAXVALS; i++)
	{
		tRB.insert(valors[i]);
	}
	
	cout << "==============================" << endl;
	cout << "=== ESCRIU ARBRE RED BLACK ===" << endl;
	cout << "==============================" << endl;
	cout << tRB;
/*
	MAXVALS = 4;
	valors = { 92, 10, 45, 105};
	for (int i = 0; i < MAXVALS; i++)
	{
		tRB.insert(valors[i]);
	}

	cout << "==============================" << endl;
	cout << "=== ESCRIU ARBRE RED BLACK ===" << endl;
	cout << "==============================" << endl;
	cout << tRB;

	cout << "=================================" << endl;
	cout << "=== Insert 9 esquerre-esquerre===" << endl;
	cout << "=================================" << endl;

	MAXVALS = 1;
	valors = { 9 };
	for (int i = 0; i < MAXVALS; i++)
	{
		tRB.insert(valors[i]);
	}

	cout << "==============================" << endl;
	cout << "=== ESCRIU ARBRE RED BLACK ===" << endl;
	cout << "==============================" << endl;
	cout << tRB;

	cout << "===============================" << endl;
	cout << "=== Insert 100 dret-esquerre==" << endl;
	cout << "===============================" << endl;

	MAXVALS = 1;
	valors = { 100 };
	for (int i = 0; i < MAXVALS; i++)
	{
		tRB.insert(valors[i]);
	}

	cout << "==============================" << endl;
	cout << "=== ESCRIU ARBRE RED BLACK ===" << endl;
	cout << "==============================" << endl;
	cout << tRB;

	cout << endl;
	*/

	return 0;
}