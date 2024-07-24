#include <iostream>
#include <math.h>
using namespace std;

void nhapSoDienTieuThuVaDonGia(float &x, float &k);
float tinhSoTienDien(float x, float k);
void nhapSoNguyen(int &n);
float tinhF(float x, float k, int n);

int main(int argc, char** argv) {
	float x, k;
	int n;
	nhapSoDienTieuThuVaDonGia(x, k);
	nhapSoNguyen(n);
	cout << "\nSo tien dien phai tra: " << tinhSoTienDien(x, k);
	cout << "\nF(x, k, n) = " << tinhF(x, k, n);
	
	return 0;
}

void nhapSoDienTieuThuVaDonGia(float &x, float &k) {
	cout << "Nhap so dien tieu thu x: ";
	cin >> x;
	cout << "Nhap don gia 1 so dien k: ";
	cin >> k;
}

float tinhSoTienDien(float x, float k) {
	if(x <= 100)
		return x * k;
	else
		return 100 * k + (x - 100) * 2 * k;
}

void nhapSoNguyen(int &n) {
	cout << "Nhap so nguyen n: ";
	cin >> n;
}

float tinhF(float x, float k, int n) {
	float sum = 2020 * pow(x, n);
	for(int i = 1; i <= n; i++)
		sum += n / pow(tinhSoTienDien(x, k), i);
	return sum;
}

































