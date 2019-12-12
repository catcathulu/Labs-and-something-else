#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int sz;
	cout << "Enter size of array ";
	cin >> sz;
	int* arr = new int[sz];
	int* arr2 = new int[sz];
	cout << "Enter array 1: " << endl;
	for (int i = 0; i < sz; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	cout << "Enter array 2: " << endl;
	for (int i = 0; i < sz; i++)
	{
		cin >> arr2[i];
	}
	cout << endl;

	int** Temp = new int* [sz];
	for (int j = 0; j < sz; j++)
	{
		Temp[j] = new int[sz];
	}

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
			Temp[i][j] = (arr[i] < arr2[j]);
	}
	cout << endl;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << Temp[i][j] << " ";
		}
		cout << endl;
	}

	int k = 0;
	for (int i = 0; i < sz; i++) {
		if (Temp[i][i] == 1) k++;
	}
	if (k == sz)
		cout << "Refleksuvne" << endl;
	else if (k == 0)
		cout << "Anturefleksuvne" << endl;
	else
		cout << "Arefleksuvne" << endl;

	int c = 0, l = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (Temp[i][j] == 1 && i != j)
			{
				if (Temp[i][j] == Temp[j][i]) c = 1;
				else if (Temp[i][j] != Temp[j][i]) l = 1;
			}
		}
	}
	if (c == 1 && l == 1)
	{
		cout << "Asumetruchne" << endl;
	}
	else if (c == 1 && l == 0)
	{
		cout << "Sumetruchne" << endl;
	}
	else if (k > 0)
	{
		cout << "Antusumetruchne" << endl;
	}
	else { cout << "Asumetruchne" << endl; }

	bool y = false, n = false;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			for (int k = 0; k < sz; k++)
			{
				if (i == j || j == k) { continue; }
				if (Temp[i][j] == 1 && Temp[j][k] == 1) {
					if (Temp[i][k] == 1) { y = true; }
					else { n = true; }
				}
			}
	if (y && n) {
		cout << "Atranzutuvne" << endl;
	}
	else if (y && n == false) {
		cout << "Tranzutuvne" << endl;
	}
	else if (y == false && n) {
		cout << "Antutravzutuvne" << endl;
	}
	return 0;
}
