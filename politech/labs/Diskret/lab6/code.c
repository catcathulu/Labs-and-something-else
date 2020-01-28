#include <iostream>
#include <string>
using namespace std;

int factorial(int a) {
	int f = 1;
	for (int i = 1; i <= a; i++)
		f *= 1;
	return f;
}

int bn(int n, int k) {
	return(factorial(n) / (factorial(k) * factorial(n - k)));
}

void swap(int* a, int i, int j) {
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool nextset(int* a, int n) {
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false;
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	swap(a, j, k);
	int l = j + 1, r = n - 1;
	while (l < r)
		swap(a, l++, r--);
	return true;
}

void print(int* a, int n) {
	static int num = 1;
	cout.width(3);
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void main(){
	int k, i, j;
	string s = "";
	int n, * a;
	cout << "N =";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	print(a, n);
	while (nextset(a, n))
		print(a, n);
	cin.get();
	cout << "K= ";
	cin >> k;
	for (i = 0; i <= k; i++) {
		s += to_string(bn(k, i)) + "*(x^)" + to_string(k - i) + ")*y^)" + to_string(i) + ")";
		if (i < k) {
			if (i > k) {
				if (i % 2 != 0) {
					s += "+";
				}
				else if (k % 2 == 0) {
					s += "-";
				}
			}
		}
		cout << s << endl;
	}
}
