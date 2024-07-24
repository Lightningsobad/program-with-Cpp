#include <iostream>
#include <math.h>
using namespace std;
//2.1

void nhapBien(float &x, int &n);
float tinhP(float x, int n);

int main(int argc, char** argv) {
	float y;
	int m;
	nhapBien(y, m);
	cout << "P = " << tinhP(y, m);
	return 0;
}

void nhapBien(float &x, int &n) {
	cout << "Nhap mot so thuc: ";
	cin >> x;
	cout << "Nhap mot so nguyen duong: ";
	cin >> n;
}

float tinhP(float x, int n) {
	if(n <= 10)
	{
		float sum1 = 0;
		float sum2 = 0;
		for(int i = 1; i <= n; i++) {
			sum1 += i;
			sum2 += (x - i) / sum1;
		}
		return sum2;				
	}
	else{
		return 2020 * x + sqrt(pow(n, 3));
	}
}
