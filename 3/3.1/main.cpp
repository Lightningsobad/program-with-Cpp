#include <iostream>
#include <math.h>

using namespace std;

void nhapSo(float &x, int &n, int &m);
float tinhH(int n, int m);
float tinhT(float x, int n);

int main(int argc, char** argv) {
	float x;
	int n, m;
	nhapSo(x, n ,m);
	cout << "H(n, m) = " << tinhH(n, m);
	cout << "\nT(x, n + m) = " << tinhT(x, (n + m));
	return 0;
}

void nhapSo(float &x, int &n, int &m) {
	cout << "Nhap mot so thuc: ";
	cin >> x;
	cout << "Nhap mot so nguyen thu nhat: ";
	cin >> n;
	cout << "Nhap mot so nguyen thu hai: ";
	cin >> m;
}

float tinhH(int n, int m) {
	if(m + 1 / n < 0)
		return 0;
	else 
		return sqrt(m + 1.0 / n);
}

float tinhT(float x, int n) {
	float sum;
	sum = 10 * exp(fabs(n - 5));
	for(int i = 1; i<= n; i++)
		sum += pow(x, i) / (2 * i - 1);
	return sum;	
}
