#include <iostream>

using namespace std;
void nhapSoNguyen(int &n, char k);
int tinhTich(int n);
int tinhS(int n);

int main(int argc, char** argv) {
	int n, m;
	nhapSoNguyen(n, 'n');
	nhapSoNguyen(m, 'm');
	cout << "Gia tri cua S(2n) + S(m) = " << tinhS(2 * n) + tinhS(m);
	return 0;
}

void nhapSoNguyen(int &n, char k) {
	do
	{
		cout << "Nhap so nguyen " << k << " lon hon 3: ";
		cin >> n;
	} while(n <= 3);
}

int tinhTich(int n) {
	if(n <= 0)
		return 1;
	else {
		int pro = 1;
		for(int i = 1; i <= n; i++)
			pro *= i;
		return pro;
	}	
}

int tinhS(int n) {
	if(n <= 0)
		return 0;
	else {
		int sum = 0;
		for(int i = 1; i <= n; i++)
			sum += tinhTich(i);
		return sum;
	}	
}
