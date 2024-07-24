#include <iostream>
#include <math.h>
using namespace std;

void nhapToaDo(float &x, float &y, char k);
float tinhKC(float x1, float y1, float x2, float y2);
void nhapSoNguyen(int &n);
float tinhF(float x1, float y1, float x2, float y2, int n);

int main(int argc, char** argv) {
	float x1, y1, x2, y2;
	int n;
	nhapToaDo(x1, y1, 'A');
	nhapToaDo(x2, y2, 'B');
	nhapSoNguyen(n);
	cout << "Khoang cach Manhattan giua A va B: " << tinhKC(x1, y1, x2, y2);
	cout << "\nF(x1, y1, x2, y2, n) = " << tinhF(x1, y1, x2, y2, n);
	return 0;
}

void nhapToaDo(float &x, float &y, char k) {
	cout << "Nhap vao toa do cua diem " << k << ":\n";
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
}

float tinhKC(float x1, float y1, float x2, float y2) {
	return fabs(x2 - x1) + fabs(y2 - y1);
}

void nhapSoNguyen(int &n) {
	cout << "Nhap vao so nguyen n: ";
	cin >> n;
}

float tinhF(float x1, float y1, float x2, float y2, int n) {
	float sum;
	sum = 2020 * n;
	for(int i = 1; i <= n; i++)
		sum += pow(tinhKC(x1, y1, x2, y2), i) / (2 * i + 1);
	return sum;
}


