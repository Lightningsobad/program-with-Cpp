#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float* a, int n);
void sapxepGiam(float* a, int n);
float tinhP(float* a, int n);	// tong cac phan tu duong trong day
float tinhQ(float* a, int n);	// trung binh cong cac phan tu
void timSoPT(float* a, int n);

int main(int argc, char** argv) {
	float* a;
	int n;
	a = new float[30];
	nhapSoPT(n);
	nhapMang(a, n);
	xuatMang(a, n);
	sapxepGiam(a, n);	
	cout << "\nGia tri cua k = P / Q = " << tinhP(a, n) / tinhQ(a, n);
	timSoPT(a, n);
	delete[] a;
	return 0;
}

void nhapSoPT(int &n) {
	do
	{
		cout << "Nhap so PT: ";
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
	ofstream file1("ABC2022.txt", ios::out);
	for(int i = 0; i < n; i++) {
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();
}

void sapxepGiam(float* a, int n) {
	ofstream file1("ABC2022.txt", ios::app);
	cout << "\nDay so sau khi sap xep: \n";
	file1 << "\nDay so sau khi sap xep: \n";
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
}

float tinhP(float* a, int n) {
	float sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] > 0)
			sum += a[i];
	return sum;
	
}

float tinhQ(float* a, int n) {
	float sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	return sum * 1.0 / n;
}

void timSoPT(float* a, int n) {
	float sum = 0;
	int dem = 0;
	sapxepGiam(a, n);
	for(int i = n - 1; i >= 0; i--) {
		if(sum + a[i] <= 30) {
			sum += a[i];
			dem++;
		}
		else
			break;
	}
	cout << "\nSo PT lay dc nhieu nhat de tong khong vuot qua 30: " << dem << " phan tu.";		 
}	














