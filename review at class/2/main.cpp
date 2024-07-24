#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void timGiaTriLonThuHai(int* a, int n);
void sxGiam(int* a, int n);
void sapxepGiam(int* a, int n);
void nhapSoK(int &k);
void chenSo(int* a, int &n, int vt, int gt);
void chenSoK(int* a, int &n, int k);

int main(int argc, char** argv) {
	int* a;
	int n, k;
	a = new int[30];
	nhapSoPT(n);
	nhapMang(a, n);
	xuatMang(a, n);
	timGiaTriLonThuHai(a, n);
	sapxepGiam(a, n);
	nhapSoK(k);
	chenSoK(a, n, k);
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

void nhapMang(int* a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}	
}

void xuatMang(int* a, int n) {
	ofstream file1("BT2.txt", ios::out);
	for(int i = 0; i < n; i++){
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();	
}

void sxGiam(int* a, int n) {
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j]) {
				int tg;
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
}

void sapxepGiam(int* a, int n) {
	ofstream file1("BT2.txt", ios::app);
	cout <<"\nDay sau khi sap xep giam: \n";
	file1 <<"\nDay sau khi sap xep giam: \n";
	sxGiam(a, n);
	for(int i = 0; i < n; i++) {
		file1 << "\t" << a[i];	
		cout << "\t" << a[i];
	}	
}

void timGiaTriLonThuHai(int* a, int n) {
	ofstream file1("BT2.txt", ios::app);
	sxGiam(a, n);
	int x = 0;
	while(a[x] == a[0])
		x++;
	cout << "\nGia tri lon thu hai trong mang: " << a[x] << endl;
	file1 << "\nGia tri lon thu hai trong mang: " << a[x];
	file1.close();
}

void nhapSoK(int &k) {
	cout << "\nNhap mot so nguyen k: ";
	cin >> k;
}

void chenSo(int* a, int &n, int vt, int gt) {
	for(int i = n; i > vt; i--)
		a[i] = a[i - 1];
	a[vt] = gt;
	n--;
}

void chenSoK(int* a, int &n, int k) {
	for(int i = 0; i < n; i++)
		if(a[i] % 2 != 0) {
			chenSo(a, n, i + 1, k);
			break;
		}
	cout << "\nMang sau khi chen gia tri " << k << " vao sau phan tu le dau tien co trong mang:\n";
	for(int i = 0; i < n; i++)
		cout << "\t" << a[i];
}

