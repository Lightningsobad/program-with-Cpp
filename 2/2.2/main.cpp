#include <iostream>

using namespace std;

void nhapSoPT(int &n);
void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void timChanDuong(int *a, int n);
void nhapX(int &x);
void xoaPT(int* a, int &n, int vt);
void xoaPTX(int* a, int &n, int x);
int timMax(int* a, int &n);
int timSoPTLN(int* a, int &n);
int main(int argc, char** argv) {
	int n, x;
	int* a;
	a = new int [30];
	nhapSoPT(n);
	nhapMang(a, n);
	cout << "Mang da nhap: \n";
	xuatMang(a, n);
	timChanDuong(a, n);
	nhapX(x);
	xoaPTX(a, n, x);
	cout << "\nSo PT lon nhat la: " << timSoPTLN(a, n);
	return 0;
}

void nhapSoPT(int &n) {
	do 
	{
		cout << "Nhap so PT: ";
		cin >> n;
	}	while(n < 3 || n > 30);
}

void nhapMang(int *a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMang(int *a, int n) {
	for(int i = 0; i < n; i++)
		cout << "\t" << a[i];
}

void timChanDuong(int *a, int n) {
	cout << "\nCac so chan duong trong mang: \n";
	int d = 0;
	for (int i = 0; i < n; i++)
		if(a[i] % 2 == 0 && a[i] > 0)
			cout << "\t" << a[i];					
}

void nhapX(int &x) {
	cout <<"\nNhap so nguyen x: ";
	cin >> x;
} 

void xoaPT(int* a, int &n, int vt) {
	for(int i = vt; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
}

void xoaPTX(int* a, int &n, int x) {
	cout << "Xoa phan tu co gia tri bang " << x << " ta duoc mang: \n";
	for(int i = 0; i < n; i++)
		if(a[i] == x)
		{
			xoaPT(a, n, i);
			i--;
		}
	xuatMang(a, n);
}

int timMax(int* a, int &n) {
	int max;
	max = a[0];
	for(int i = 0; i < n; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}

int timSoPTLN(int* a, int &n) {
	int dem;
	dem = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == timMax(a, n))
			dem++;
	return dem;
}
