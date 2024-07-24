#include <iostream>
#include <fstream>

using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float *a, int n);
void tinhTong(float* a, int n);
void kiemtraHopLe(float* a, int n);
void nhapSoX(float &x);
void xoaPT(float* a, int &n, int vt);
void xoaPTX(float* a, int &n, int x);
int main(int argc, char** argv) {
	float* a;
	int n;
	float x;
	a = new float[30];
	nhapSoPT(n);
	nhapMang(a, n);
	xuatMang(a, n);
	tinhTong(a, n);
	kiemtraHopLe(a, n);
	nhapSoX(x);
	xoaPTX(a, n, x);
	delete[] a;
	return 0;
}

void nhapSoPT(int &n) {
	do 
	{
		cout << "Nhap so PT mang: ";
		cin >> n;
	} while(n < 0 || n > 30);
}

void nhapMang(float* a, int n) {
	for(int i = 0; i< n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMang(float *a, int n) {
	ofstream file1("BT3.txt", ios::out);
	for(int i = 0; i < n; i++) {
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();	
}

void tinhTong(float* a, int n) {
	ofstream file1("BT3.txt", ios::app);
	float sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] >= 5 && a[i] <= 10)
			sum += a[i];
	file1 << "\nTong cac phan tu thuoc [5..10] trong mang: " << sum;
	file1.close();
}

void kiemtraHopLe(float* a, int n) {
	int flag = 1;
	for(int i = 0; i < n; i++)
		if(a[i] <= 6) {
			flag = 0;
			break;	
	}
	if(flag == 1)
		cout << "\nMang hop le.";
	else	
		cout <<"\nMang khong hop le.";
}

void nhapSoX(float &x) {
	cout << "\nNhap vao mot so thuc x: ";
	cin >> x;
}

void xoaPT(float* a, int &n, int vt) {
	for(int i = vt; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}

void xoaPTX(float* a, int &n, int x) {
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			xoaPT(a, n, i);
	cout << "Xoa cac phan tu co gia tri bang " << x << " trong mang ta co:\n";
	for(int i = 0; i < n; i++)
		cout << "\t" << a[i];
}



















