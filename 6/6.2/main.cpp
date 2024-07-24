#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float* a, int n);
void sapxepGiam(float* a, int n);
float timMin(float* a, int n);
int timSoGiaTriMin(float* a, int n);
void nhapSoX(int &x);
void chenSo(float* a, int &n, int vt, int gt);
void chenSoX(float *a, int &n, int x);


int main(int argc, char** argv) {
	float* a;
	int n, x;
	a= new float[30];
	nhapSoPT(n);
	nhapMang(a, n);
	xuatMang(a, n);
	sapxepGiam(a, n);
	cout << "\nSo nho nhat trong day: " << timMin(a, n);
	cout << "\nSo gia tri nho nhat trong day: " << timSoGiaTriMin(a, n);
	nhapSoX(x);
	chenSoX(a, n, x);
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
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMang(float* a, int n) {
	ofstream file1("ABC2110.txt", ios::out);
	for(int i = 0; i < n; i++) {
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();
}

void sapxepGiam(float* a, int n) {
	ofstream file1("ABC2110.txt", ios::app);
	cout << "\nSap xep mang giam dan: \n";
	file1 << "\nSap xep mang giam dan: \n";
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
		file1 << "\t" << a[i];
	}
	file1.close();
}

float timMin(float* a, int n) {
	float min = a[0];
	for(int i = 0; i < n; i++)
		if(a[i] < min)
			min = a[i];
	return min;	
}

int timSoGiaTriMin(float* a, int n) {
	int dem = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == timMin(a, n))
			dem++;
	return dem;
}

void nhapSoX(int &x) {
	cout << "\nNhap so x: ";
	cin >> x;
}

void chenSo(float* a, int &n, int vt, int gt) {
	for(int i = n; i > vt; i--)
		a[i] = a[i - 1];
	a[vt] = gt;
	n++;
}

void chenSoX(float *a, int &n, int x) {
	int flag = 0;
	for(int i = 0; i < n; i++) 
		if(a[i] > x) {
			chenSo(a, n, i + 1, x);
			flag = 1;
			break;
		}
	if(flag == 0)
		cout << "Trong mang khong co phan tu nao lon hon " << x;		
	else{
		cout << "\nMang sau khi chen gia tri " << x << " vao sau PT dau tien lon hon " << x << " trong mang: \n";
		for(int i = 0; i < n; i++)
			cout << "\t" << a[i];
	}				
}











