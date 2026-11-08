#include <iostream> //подклчение потоковых операций

using namespace std; //использование стандартного пространства имён

const int sizen = 100; //максимальный размер массива

void del(int a[sizen][sizen], int n, int m) { //функция принимающая двумерный массив, количество строк и столбцов
	int b[sizen][sizen], r = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) { //проверка строки на чётность, все чётные строки имеют нечётные индексы
			for (int j = 0; j < m; ++j) {
				b[r][j] = a[i][j]; //перезаписываем массив
			}
			++r;
		}
	}
	n = r; //новое количество строк
	//вывод массива
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
//для функций представленных ниже принцип тот же, просто передаётся другой тип данных массива
void del(float a[sizen][sizen], int n, int m) {
	float b[sizen][sizen];
	int r = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				b[r][j] = a[i][j];
			}
			++r;
		}
	}
	n = r;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
    cout << endl;
}

void del(double a[sizen][sizen], int n, int m) {
	double b[sizen][sizen];
	int r = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				b[r][j] = a[i][j];
			}
			++r;
		}
	}
	n = r;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

}

int main(){
	setlocale(LC_ALL, ".65001");
    //объявление и инициализация массива
	int ai[sizen][sizen] = { {1, 2, 3}, 
							{4, 5, 6,} };
    //перегрузка
    cout << "Перегрузка для int\n";
	del(ai, 2, 3); //вызов функции

	//объявление и инициализация массива
	float af[sizen][sizen] = { {1.1, 2.09, 3.02},
							{4.1, 5.2, 6.7,},
							{2.5, 3.6, 9.1} };
    //перегрузка
    cout << "Перегрузка для float\n";
	del(af, 3, 3); //вызов функции

    //объявление и инициализация массива
	double ad[sizen][sizen] = {
							{1.1, 1.2, 1.3},
							{2.1, 2.2, 2.3},
							{3.1, 3.2, 3.3},
							{4.1, 4.2, 4.3} };
    //перегрузка
    cout << "Перегрузка для double\n";
	del(ad, 4, 3); //вызов функции
    return 0;
}