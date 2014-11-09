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

	Vector(){
		End = Point(0, 0, 0);
	}
	Vector(Point End){
		this->End = Point(End);
	}
	Vector(Point Start, Point End){
		this->End = Point(End.x1 - Start.x1, End.x2 - Start.x2, End.x3 - Start.x3);
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
	float sproduct(Vector& B){
		return (this->End.x1*B.End.x1 + this->End.x2*B.End.x2 + this->End.x3*B.End.x3);
	}
	float getLength(){
		return sqrt(pow(this->End.x1, 2) + pow(this->End.x2, 2) + pow(this->End.x3, 2));
	}
	void print(){
		cout << "[" << this->End.x1 << ";" << this->End.x2 << ";" << this->End.x3 << "]" << endl;
	}
};
class Axis{
public:
	Point Start;
	Vector Direction;

	Axis() {			//not an axis, because no vector.
		this->Start = Point();
		this->Direction = Vector();
	}
	Axis(Vector Direction){
		this->Start = Point();
		this->Direction = Vector(Direction);
	}
	Axis(Point Start, Vector Direction){
		this->Start = Point(Start);
		this->Direction = Vector(Direction);
	}
	bool isOnAxis(Point P){
		if (this->Direction.End.x1 == 0){
			if (P.x1 != 0 )
			{
				return false;
			}
		}
		else if (this->Direction.End.x2 == 0){
			if (P.x2 != 0)
			{
				return false;
			}
		}
		else if (this->Direction.End.x3 == 0){
			if (P.x3 != 0)
			{
				return false;
			}
		}
		else {
			float h1 = (P.x1 - this->Start.x1) / this->Direction.End.x1;
			float h2 = (P.x2 - this->Start.x2) / this->Direction.End.x2;
			float h3 = (P.x3 - this->Start.x3) / this->Direction.End.x3;
			if (h1 == h2 && h2 == h3) {
				return true;
			}
		}
	}
};
class Plane{
public:
	Point point;
	Vector v1;
	Vector v2;
	
	Plane(){			//not a Plane, but nothing was defined
		this->point = Point();
		this->v1 = Vector();
		this->v2 = Vector();
	}
	Plane(Vector v1, Vector v2){
		this->point = Point();
		this->v1 = Vector(v1);
		this->v2 = Vector(v2);
	}
	Plane(Point point, Vector v1, Vector v2){
		this->point = Point(point);
		this->v1 = Vector(v1);
		this->v2 = Vector(v2);
	}
	bool isOnPlane(Point P){

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
class slidingVector{
public:
	Axis axis;
	Vector vector;

	slidingVector(){
		this->axis = Axis();
		this->vector = Vector();
	}
	slidingVector(Axis axis, Vector vector){
		this->axis = Axis(axis);
		this->vector = Vector(vector);
	}
};
class MaaP{			//Moment about a Point
public:
	fixedVector Moment;
	Point point;

	MaaP(){
		Moment = fixedVector();
		point = Point();
	}
	MaaP(Point point, fixedVector force){
		this->point = Point(point);
		this->Moment = fixedVector(point, Vector(point, force.poa).xproduct(force.vector));
	}
};
class MaaA{			//Moment about an Axis
	slidingVector sV;

	MaaA(){
		this->sV = slidingVector();
	}
	MaaA(slidingVector sV){
		this->sV = slidingVector(sV);
	}
	MaaA(Axis a, fixedVector fV){
		
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
