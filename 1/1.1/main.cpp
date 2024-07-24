#include <iostream>
#include <math.h>

using namespace std;
// 1.1

void nhapToaDo(float &x, float &y);
float tinhKC(float x1, float y1, float x2, float y2);
float tinhChuVi(float x1, float y1, float x2, float y2, float x3, float y3);

int main(int argc, char** argv) {
	float x1, y1, x2, y2, x3, y3;
	cout << "Nhap toa do 3 diem A, B, C: \n";
	cout << "Diem A: \n";
	nhapToaDo(x1, y1);
	cout << "Diem B: \n";
	nhapToaDo(x2, y2);
	cout << "Diem C: \n";
	nhapToaDo(x3, y3);
	cout << "\nChu vi tam giac ABC bang: " << tinhChuVi(x1, y1, x2, y2, x3, y3);
	return 0;
}

void nhapToaDo(float &x, float &y) {
	cout << "Nhap hoanh do x: ";
	cin >> x;
	cout << "Nhap tung do y: ";
	cin >> y;
}

float tinhKC(float x1, float y1, float x2, float y2) {
	float d;
	d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return d;
} 

float tinhChuVi(float x1, float y1, float x2, float y2, float x3, float y3) {
	float c;
	c = tinhKC(x1, y1, x2, y2) + tinhKC(x1, y1, x3, y3) + tinhKC(x2, y2, x3, y3);
	return c;	
}
