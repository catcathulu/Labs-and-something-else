#include <iostream>

using namespace std;

void Check(int v, int AM[][11], int Values[], int Lines[]);

int main()
{ //матриця 
	int AM[11][11] =
	{ {12,7,3,2,12,12,12,12,12,12,12},
		{7,12,12,12,7,12,1,12,12,12,12},
		{3,12,12,12,7,4,12,12,12,12,12},
		{2,12,12,12,12,5,5,12,12,12,12},
		{12,7,7,12,12,12,12,2,4,12,12},
		{12,12,4,5,12,12,12,4,12,2,12},
		{12,1,12,5,12,12,12,12,3,4,12},
		{12,12,12,12,2,4,12,12,12,12,3},
		{12,12,12,12,4,12,3,12,12,12,1},
		{12,12,12,12,12,2,4,12,12,12,6},
		{12,12,12,12,12,12,12,3,1,6,12}
	};

	// ребер
	int Values[] = { 1,2,3,4,5,6,7 }; // "v"
	int value = (sizeof(Values)) / 4;

	//масив  ребер
	int Lines[11];
	//занулити
	for (int i = 0; i < value; i++)
	{
		Lines[i] = 0;
	}
	//виклик функції
	cout << "\n Line\t|  Weight" << endl;
	cout << "--------|---------" << endl;

	for (int weight = 0; weight < value; weight++)
	{
		Check(weight, AM, Values, Lines);
	}

	return 0;
}
void Check(int v, int AM[][11], int Values[], int Lines[])
{
	int counter1 = 0;
	int counter2 = 0;
	bool flag1, flag2;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (AM[i][j] == Values[v])
			{
				for (int x = 0; x < 11; x++)
				{
					if (Lines[x] != i)    //якщо нема ще такого ребра
					{
						counter1++;
					}
					if (Lines[x] != j)    //якщо нема ще такого ребра
					{
						counter2++;
					}
				}
				if (counter1 == 11)
				{
					Lines[i] = i;
					flag1 = true;
				}
				if (counter2 == 11)
				{
					Lines[j] = j;
					flag2 = true;
				}
				if ((flag1 == false) && (flag2 == false))
				{
					// flags are false
				}
				else {
					cout << "{" << Lines[i] + 1 << ";" << Lines[j] + 1 << "}\t|    ";
					cout << v + 1 << endl;;
				}

			}
			counter1 = 0;
			counter2 = 0;
			flag1 = false;
			flag2 = false;
		}
	}
}
