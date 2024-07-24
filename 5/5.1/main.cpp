#include <iostream>
#include <math.h>
using namespace std;

void nhapSoThuc(float &x);
void nhapSoNguyen(int &n);
float tinhP(int a, int b);
float tinhQ(float x, int n);

int main(int argc, char** argv) {
	float x;
	int n, m;
	nhapSoThuc(x);
	nhapSoNguyen(n);
	nhapSoNguyen(m);
	cout << "\nP(n, m) = " << tinhP(n, m);
	cout << "\nQ(x, n) = " << tinhQ(x, n);
	return 0;
}

void nhapSoThuc(float &x) {
	cout << "Nhap mot so thuc: ";
	cin >> x;
}

void nhapSoNguyen(int &n) {
	cout << "Nhap mot so nguyen: ";
	cin >> n;
}

float tinhP(int a, int b) {
	if(pow(a - b, 2) + pow(a * 1.0 / b , 2) < 0)
		return 0;
	else
		return sqrt(pow(a - b, 2) + pow(a * 1.0 / b , 2));
}

float tinhQ(float x, int n) {
	float sum;
	sum = exp(fabs(x + 1));
	for(int i = 1; i <= n; i++)
		sum += (pow(x, i) / (2 * i + 1));
	return sum;
		
}
