#include <iostream>
#include <math.h>
using namespace std;

void nhapSo(float &x, int &n, int &m);
float tinhL(int n, int m);
float tinhP(float x, int n);

int main(int argc, char** argv) {
	float x;
	int n, m;
	nhapSo(x, n, m);
	cout << "\nL(n,2m) = " << tinhL(n, 2 * m);
	cout << "\nP(x,n) = " << tinhP(x, n);
	return 0;
}

void nhapSo(float &x, int &n, int &m) {
	cout << "Nhap mot so thuc: ";
	cin >> x;
	cout << "Nhap so nguyen thu nhat: ";
	cin >> n;
	cout << "Nhap so nguyen thu hai: ";
	cin >> m;
}

float tinhL(int n, int m) {
	if(1.0 / (n + m) + n < 0)
		return -1;
	else
		return sqrt(1.0 / (n + m) + n);
}

float tinhP(float x, int n) {
	float sum;
	sum = 9 * exp(n * x);
	for(int i = 1; i <= n; i++)
		sum += (pow(2, i) * 1.0) / (2 * i + 1);
	return sum;
}
