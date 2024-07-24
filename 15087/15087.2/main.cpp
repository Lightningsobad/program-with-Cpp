#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float* a, int n);
void sapxepGiam(float* a, int n);
float tinhTong(float* a, int n);
void nhapSoThuc(float &x);
void chenMang(float* a, int &n, float x);

int main(int argc, char** argv) {
	float* a;
	int n;
	float x;
	a = new float[30];
	nhapSoPT(n);
	nhapMang(a, n);
	xuatMang(a, n);
	sapxepGiam(a, n);
	cout << "\nTong cac so thuoc doan [3..8] trong mang: " << tinhTong(a, n);
	nhapSoThuc(x);
	chenMang(a, n, x);
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
	for(int i = 0; i < n ; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMang(float* a, int n) {
	ofstream file1("ABC2105.DAT", ios::out);
	for(int i = 0; i < n; i++){
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();
}

void sapxepGiam(float* a, int n) {
	fstream file2("XYZ2105.txt", ios::out);
	cout << "\nSap xep mang giam dan: \n";
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j]) {
				float tg;
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
	for(int i = 0; i < n; i++) {
		cout << "\t" << a[i];
		file2 << "\t" << a[i];
	}
	file2.close();	
}

float tinhTong(float* a, int n) {
	float sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] >= 3 && a[i] <= 8)
			sum += a[i];
	return sum;
}

void nhapSoThuc(float &x) {
	cout << "\nNhap mot so thuc: ";
	cin >> x;
}

void chenMang(float* a, int &n, float x) {
	cout << "Chen " << x << " vao sau phan tu dau tien cua mang ta dc: ";
	for(int i = n; i > 1; i--)
		a[i] = a[i - 1];
	a[1] = x;
	n++;
	for(int i = 0; i < n; i++)
		cout << "\t" << a[i];	 	
}
