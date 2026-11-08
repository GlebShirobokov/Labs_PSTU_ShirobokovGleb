#include <iostream>
using namespace std;

// Максимальные размеры матрицы.
const int sizen = 100;


void restore(int b[], int n, int m, int a[sizen][sizen]) {
    //  блоки строк.
    
    int rows[sizen][sizen];
    //  блоки столбцов
    int cols[sizen][sizen];

    
    

    // Первые n*m элементов массива b — это строки.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rows[i][j] = b[i * m + j];
        }
    }

    // Следующие m*n элементов массива b — это столбцы.
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            cols[j][i] = b[n*m + j * n + i];
        }
    }

    // массив для порядка строк.
    int order[sizen];

    
    for (int i = 0; i < n; ++i) {
        // x — это элемент, который должен стоять в i-й строке.
        int x = cols[0][i];
        for (int r = 0; r < n; ++r) {
            bool found = false;

            // Проверяю все элементы r-й строки.
            for (int c = 0; c < m; ++c) {
                if (rows[r][c] == x) {
                    found = true; // нашел число x
                    c = m;        // дальше эту строку можно не проверять
                }
            }

            // Если нашел x в строке r, то запоминаю,
            // что для i-й строки результата нужна rows[r].
            if (found) {
                order[i] = r;
                r = n; // переход к следующему i
            }
        }
    }

    
   
    //восстановление двумерного массива
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rows[order[i]][j];
        }
    }
}

int main() {

    int n, m, b[sizen],a[sizen][sizen];
    cin >> n >> m;     

    for (int i = 0; i < 2 * n*m; ++i) {
        cin >> b[i];
    }

    //вызов функции для восстановления матрицы
    restore(b, n, m, a);

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0; 
}