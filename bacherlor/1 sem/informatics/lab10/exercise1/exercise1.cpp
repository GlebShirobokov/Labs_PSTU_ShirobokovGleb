#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
	int n, k, n1;
	cin >> n;
	string* a = new string[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << "ввидите номер строки, от 1 до n, которую вы хотите добавить ";
	cin >> k;
	string s = a[k-1];
	n1 = n+1;
	string* a1 = new string[n1];
	for (int i = 0; i < n; ++i) a1[i] = a[i];
	delete[] a;
	a1[n1-1] = s;
	for (int i = 0; i < n1; ++i) cout << a1[i] << ' ';
	delete[] a1;
}
