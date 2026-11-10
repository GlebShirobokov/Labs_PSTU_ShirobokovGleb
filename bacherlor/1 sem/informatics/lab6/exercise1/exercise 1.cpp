#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
        string text;

        // Коэффициенты функции y = kx + b
        // k отрицательный, так как в консоли ось Y направлена вниз
        // b задает начальную высоту (отступ сверху)
        double k = -0.5, b = 15.0;
        

        cout << "enter a sentance:\n";

        // Чтение строки целиком, включая пробелы (аналог fgets)
        getline(cin, text);

        int len = text.length();

        // Определяем, сколько всего строк (высоту) нужно напечатать
        // Считаем координату Y для первого и последнего символа с округлением
        int y_start = round(k * 0 + b);
        int y_end = round(k * (len - 1) + b);

        // Находим минимальный и максимальный Y, чтобы знать диапазон печати
        int max_y = max(y_start, y_end);
        int min_y = min(y_start, y_end);

        // Печатаем экран строка за строкой (сверху вниз)
        for (int current_y = min_y; current_y <= max_y; current_y++) {

            // В каждой строке перебираем все символы предложения
            for (int x = 0; x < len; x++) {

                // Вычисляем Y для текущего символа x
                int char_y = round(k * x + b);

                // Если координата символа совпадает с текущей строкой - печатаем его
                if (char_y == current_y) {
                    cout << text[x];
                }
                else {
                    // Иначе печатаем два пробела (для сохранения пропорций)
                    cout << "  ";
                }
            }
            cout << '\n'; // Переход на новую строку
        }

        return 0;
    }