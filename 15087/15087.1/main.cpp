#include <iostream>
#include <math.h>
using namespace std;

float tinhP(float x);
void hoandoi2SoNguyen(int &n, int &m);
float tinhS(float x, int n);

int main(int argc, char** argv) {
	float a;
	int b, c;
	cout << "Nhap vao mot so thuc a: ";
	cin >> a;
	cout << "Nhap vao mot so nguyen b: ";
	cin >> b;
	cout << "Nhap vao mot so nguyen c: ";
	cin >> c;
	cout << "\nP(a) = " << tinhP(a);
	if(c < b){
		hoandoi2SoNguyen(b, c);
		cout << "\nGia tri b, c sau khi hoan doi: b = " << b << ", c = " << c;
	}	
	cout << "\nGia tri cua S(a, c) - S(a, b) = " << tinhS(a, c) - tinhS(a, b);
	return 0;
}

float tinhP(float x) {
	return exp(fabs(x)) + pow(x, 5) + sqrt(x * x + 1);
}

void hoandoi2SoNguyen(int &n, int &m) {
	int tg;
	tg = n;
	n = m;
	m = tg;
}

float tinhS(float x, int n) {
	float sum = 100;
	if(x < 0)
		return 1;
	for(int i = 1; i <= n; i++)
		sum += (sqrt(pow(x, i)) / (n + i));
	return sum;	
}
