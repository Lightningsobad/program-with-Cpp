#include <iostream>
#include <fstream>

using namespace std;

void nhapSoPT(int &n);
void nhapMang(int* a, int n);
void xuatMang(int* a, int n);
void sapxepTang(int* a, int n);
void tinhTongAm(int* a, int n);
float tinhK(int* a, int n);
void chonPT(int* a, int n);
int main(int argc, char** argv) {
	int* a;
	int n;
	nhapSoPT(n);
	a = new int[n];
	nhapMang(a, n);
	sapxepTang(a, n);
	cout << "\nSap xep tang dan:\n";
	xuatMang(a, n);
	tinhTongAm(a, n);
	cout << "\nK = " << tinhK(a, n);
	chonPT(a, n);
	return 0;
}

void nhapSoPT(int &n) {
	cout << "Nhap so PT mang: ";
	cin >> n;
}

void nhapMang(int* a, int n) {
	for(int i = 0; i < n; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}	
}

void xuatMang(int* a, int n) {
	ofstream file1("TEST.txt", ios::out);
	for(int i = 0; i< n; i++){
		file1 << "\t" << a[i];
		cout << "\t" << a[i];
	}	
	file1.close();	 
}

void sapxepTang(int* a, int n) {
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

void tinhTongAm(int* a, int n) {
	ofstream file1("TEST.txt", ios::app);
	int sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] < 0)
			sum += a[i];
	file1 << "\nTong cac gia tri am: " << sum;
}

float tinhK(int* a, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	return sum * 1.0 / n;
}

void chonPT(int* a, int n) {
	int dem = 0;
	int sum = 0;
	sapxepTang(a, n);
	for(int i = 0; i < n; i++){					//Bai 3.2 mang dc sap xep tang dan nen duyet tu dau mang
		if(sum + a[i] <= 2 * tinhK(a, n)) {
			sum += a[i];
			dem++;
		}
		else
			break;
	}
	cout << "\nSo phan tu lay dc nhieu nhat: " << dem;
}


