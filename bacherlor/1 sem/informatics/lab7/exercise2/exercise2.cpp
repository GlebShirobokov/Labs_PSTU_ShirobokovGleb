#include <iostream>
#include<cmath>
#include<cstdarg>

using namespace std;

double storona(double& x1, double& y1, double& x2, double& y2) {
	return sqrt((x2 - x1)*(x2-x1)+ (y2 - y1)*(y2-y1));
}
double square(double& xa, double& ya, double& xb, double& yb, double& xc, double& yc) {
	double ab, ac, bc;
	ab = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
	ac = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
	bc = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
	double p = (ab + bc + ac) / 2;
	return sqrt(p * (p - ab) * (p - ac) * (p - bc));
}

double square1(int n, ...){
	double x[100], y[100];          // координаты вершин

	va_list ap;
	va_start(ap, n);
	for (int i = 0; i < n; i++) {
		x[i] = va_arg(ap, double);
		y[i] = va_arg(ap, double);
	}
	va_end(ap);

    double maxd = -1, dx, dy, d;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            // пара (i,j) — сторона, а не диагональ?
            bool side = false;
            if (j == i + 1) side = true;
            if (i == 0) {
                if (j == n - 1) side = true;
            }
            if (side) continue;

            dx = x[i] - x[j];
            dy = y[i] - y[j];
            d = dx * dx + dy * dy;
            if (d > maxd) { 
                maxd = d; 
                a = i; 
                b = j; 
            }
        }

    // 2. Наибольший треугольник с этой диагональю
    double s = 0;
    for (int k = 0; k < n; k++) {
        if (k == a) continue;
        if (k == b) continue;
        double dx1, dy1, dx2, dy2, t;
        dx1 = x[b] - x[a];
        dy1 = y[b] - y[a];
        dx2 = x[k] - x[a];
        dy2 = y[k] - y[a];
        t = fabs(dx1 * dy2 - dy1 * dx2) / 2;
        if (t > s) s = t;
    }
    return s;
}

int main(){
    setlocale(LC_ALL, ".65001");
    double x1(3), x2(0), y1(0), y2(4);
    cout << "вычисление длины стороны " << storona(x1, y1, x2, y2) << endl;
    double xa(0), xb(4), xc(0), ya(0), yb(0), yc(3);
    cout << "вычисление площади треугольника " << square(xa, ya, xb, yb, xc, yc) << endl;
    int n = 5;
    cout << "площадь треугольника, содержащего диагональ наибольшей длины выпуклого многоугольника " << square1(n, 0.0, 0.0, 4.0, 0.0, 6.0, 3.0, 3.0, 5.0, 0.0, 3.0);
}
