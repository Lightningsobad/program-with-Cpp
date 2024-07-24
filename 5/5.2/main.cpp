#include <iostream>
#include <fstream>
using namespace std;

void nhapSoPT(int &n);
void nhapMang(float* a, int n);
void xuatMang(float* a, int n);
void sapxepTang(float* a, int n);
void kiemtraMang(float* a, int n);
int tinhSoPT(float* a, int n);

int main(int argc, char** argv) {
	float* a;
	int n;
	a = new float[30];
	nhapSoPT(n);
	nhapMang(a, n);
	sapxepTang(a, n);
	xuatMang(a, n);
	kiemtraMang(a, n);
	cout << "\nSo PT lay duoc it nhat: "<< tinhSoPT(a, n);
	return 0;
}

void nhapSoPT(int &n) {
	do
	{
		cout << "Nhap so PT mang: ";
		cin >> n;
	} while (n < 0 || n > 30);
	
} 

void nhapMang(float* a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}		
}

void xuatMang(float* a, int n) {
	ofstream file1("TEST.txt", ios::out);
	for(int i = 0; i < n; i++) {
		cout << "\t" << a[i];
		file1 << "\t" << a[i];
	}		
	file1.close();
}

void sapxepTang(float* a, int n) {
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j]) {
				int tg;
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
		}
}

void kiemtraMang(float* a, int n) {
	ofstream file1("TEST.txt", ios::app);
	int flag = 0;
	for(int i = 0; i < n; i++){
		sapxepTang(a, n);
		if(a[0] > 10) {
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		file1 << "\nCo";
	else
		file1 << "\nKhong";\
	file1.close();	
}

int tinhSoPT(float* a, int n) {
	float sum = 0;
	int dem = 0;
	sapxepTang(a, n);
	for(int i = n - 1; i >= 0; i--) {
		sum += a[i];
		dem++;
		if (sum > 100)
			return dem;
	}
	return 0;	
}


























