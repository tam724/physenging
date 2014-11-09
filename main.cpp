#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

class Point  {
public:
	double x1;
	double x2;
	double x3;

	Point(){
		this->x1 = 0;
		this->x2 = 0;
		this->x3 = 0;
	}
	Point(double a, double b, double c){
		this->x1 = a;
		this->x2 = b;
		this->x3 = c;
	}
	void print(){
		cout << "(" << x1 << "|" << x2 << "|" << x3 << ")" << endl;
	}
	double distance(Point& B){
		return sqrt(pow((B.x1 - this->x1), 2) + pow((B.x2 - this->x2), 2) + pow((B.x3 - this->x3), 2));
	}
};
class Vector {
public:
	Point End;
	double length;

	Vector(){
		End = Point(0, 0, 0);
		length = 0;
	}
	Vector(Point End){
		Point N = Point(0, 0, 0);
		this->End = Point(End);
		length = N.distance(End);
	}
	Vector(float length, float a1, float a2, float a3){		//Nur 2D --- 3 Koordinate immer 0
		this->End.x1 = length * sin((a1/180)*M_PI);
		this->End.x2 = length * sin((a2/180)*M_PI);
		this->End.x3 = length * sin((a3/180)*M_PI);
		this->End.print();
	}
	Vector add(Vector& B){
		return Vector(Point((this->End.x1 + B.End.x1), (this->End.x2 + B.End.x2), (this->End.x3 + B.End.x3)));
	}
	Vector xproduct(Vector& B){
		return Vector(Point((this->End.x2*B.End.x3 - this->End.x3*B.End.x2), (this->End.x3*B.End.x1 - this->End.x1*B.End.x3), (this->End.x1*B.End.x2 - this->End.x2*B.End.x1)));
	}
	double sproduct(Vector& B){
		return (this->End.x1*B.End.x1 + this->End.x2*B.End.x2 + this->End.x3*B.End.x3);
	}
	void print(){
		cout << "[" << this->End.x1 << ";" << this->End.x2 << ";" << this->End.x3 << "]" << endl;
	}
};
class fixedVector {
public:
	Point poa;
	Vector vector;

	fixedVector(){
		poa = Point(0, 0, 0);
		vector = Vector(Point(0, 0, 0));
	}
	fixedVector(Point poa, Vector vector){
		this->poa = Point(poa);
		this->vector = Vector(vector);
	}
};
class cfs {				//concurrent force system
public:
	int numberofforces;
	Point poa;
	Vector Result;

	cfs() {
		numberofforces = 0;
		poa = Point(0, 0, 0);
		Result = Vector(Vector(Point(0, 0, 0)));
	}
	cfs(int numberofforces, Point poa, Vector forces[]){
		this->numberofforces = numberofforces;
		this->poa = Point(poa);
		Result = Vector();
		for (int i = 0; i < numberofforces; i++){
			Vector X = Vector(forces[i]);
			Result = Result.add(X);
		}
	}
};
int main(){
	//// Test of Vector and Point
	Point A = Point(1, 0, 0);
	Point(B) = Point(1, 1, 0);
	Vector VA = Vector(A);
	Vector VB = Vector(B);
	Vector C = VA.xproduct(VB);
	double b = VA.sproduct(VB);
	cout << b;
	C.print();
	///// Test of cfs
	Point poa = Point(0, 0, 0);
	cout << "Wie viele Kräfte?" << endl;
	int nof;
	cin >> nof;
	Vector *forces = new Vector[nof];
	///*
// Input Kräfte
	ofstream F("Forces", ios::out);
	for (int i = 0; i < nof; i++){
		cout << "Kraft " << i << ": " << endl;
		float length, a1, a2;
		cin >> length >> a1 >> a2;
		F <<setw(15) << length << " " << a1 << " " << a2 << endl;
	}
	F.close();
//Ende Input */

	ifstream D("Forces", ios::in);
	for (int i = 0; i < nof; i++){
		float x1, x2, x3;
		D >> x1 >> x2 >> x3;
		forces[i] = Vector(x1, x2, x3, 0);
	}
	cfs System = cfs(nof, poa, forces);
	System.Result.print();
	return 0;
}
