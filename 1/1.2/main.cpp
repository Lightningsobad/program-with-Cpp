#include <iostream>

using namespace std;
//1.2

void nhapSoPT(int &n);
void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void timChan(int* a, int n);
void nhapX(int &x);
void timUocDuong(int* a, int n, int x);
int timPTNN(int* a, int n);
void kiemtraSoNT(int x);
int main(int argc, char** argv) {
	int n, x;
	int* a;
	a = new int[30];
	nhapSoPT(n);
	nhapMang(a, n);
	cout <<"\nMang da nhap: \n";
	xuatMang(a, n);
	timChan(a, n);
	nhapX(x);
	timUocDuong(a, n, x);
	cout << "\nPhan tu nho nhat trong mang la: " << timPTNN(a, n);
	kiemtraSoNT(timPTNN(a, n));
	return 0;
}

void nhapSoPT(int &n) {
	do
	{
		cout << "\nNhap so PT: ";
		cin >> n;
	} while(n < 1 || n > 30);
}

void nhapMang(int* a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i <<"] = ";
		cin >> a[i];
	}
}

void xuatMang(int* a, int n) {
	for(int i = 0; i < n; i++) 
		cout << "\t" << a[i];
}

void timChan(int* a, int n) {
	cout << "\nCac so chan trong mang: \n";
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0)
			cout << "\t" << a[i];
	}		
}

void nhapX(int &x) {
	cout <<"\nNhap mot so nguyen x: ";
	cin >> x;
}

void timUocDuong(int* a, int n, int x) {
	cout << "Cac so duong la uoc cua " << x << " trong mang:\n";
	for(int i = 0; i < n; i++) {
		if(x % a[i] == 0 && a[i] > 0)
			cout << "\t" << a[i];
	}
}

int timPTNN(int* a, int n) {	//tim phan tu nho nhat trong mang
	int min = a[0];
	for (int i = 0; i < n; i++)
		if(a[i] < min)
			min = a[i];
	return min;
}

void kiemtraSoNT(int x) {
	if(x < 0)
		cout << "\nSo " << x << " khong la so nguyen to. ";
	else {
		int d = 0; // bien dem nghiem
		for(int i = 1; i <= x; i++)	
			if(x % i == 0)
				d++;
		if(d == 2)
			cout << "\nSo " << x << " la so nguyen to.";
		else
			cout << "\nSo " << x << " khong la so nguyen to.";	
	}
	
}

