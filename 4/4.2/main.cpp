#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float* a, int n);
void sapxepGiam(float* a, int n);
void tinhTongPTA(float* a, int n);
int chonPT(float* a, int n);

int main(int argc, char** argv) {
	int n;
	float* a;
	a = new float[100];
	nhapSoPT(n);
	nhapMang(a, n);
	cout << "\nSap xep mang giam dan: \n";
	sapxepGiam(a, n);
	xuatMang(a, n);
	tinhTongPTA(a, n);
	cout << "\nSo PT lay duoc nhieu nhat de tong < 20: " << chonPT(a, n);
	
	return 0;
}

void nhapSoPT(int &n) {
	do
	{
		cout << "Nhap so PT: ";
		cin >> n;
	} while(n < 1 || n > 100);
}

void nhapMang(float* a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}		
}

void xuatMang(float* a, int n) {
	ofstream file1("TEST.txt", ios::out);
	for(int i = 0; i < n; i++){
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}
	file1.close();	
}

void sapxepGiam(float* a, int n) {
	int tg;
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] < a[j]) {
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;	
		}			
}

void tinhTongPTA(float* a, int n) {
	ofstream file1("TEST.txt", ios::app);
	int sum = 0;
	for(int i = 0; i < n; i++)
		if(a[i] < 0)
			sum += a[i];
	file1 << "\nTong cac phan tu am: " << sum;
	file1.close();
}

int chonPT(float* a, int n) {
	int dem, sum;
	dem = 0;
	sum = 0;
	for(int i = n - 1; i >= 0; i--){	//bai 4.2 mang dc sap xep giam dan nen viet theo chieu nguoc
		if(sum + a[i] < 20){			// duyet nguoc tu cuoi len dau mang
			sum += a[i];
			dem++;
		}
		else
			break;
	}
	return dem;			
}

