#include <iostream>
#include <cmath>
using namespace std;

class Point  {
private:
	double x1;
	double x2;
	double x3;
public:
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
		cout << "(" << x1 << ";" << x2 << ";" << x3 << ")";
	}
	double distance(Point& B){
		return sqrt(pow((B.x1 - this->x1), 2) + pow((B.x2 - this->x2), 2) + pow((B.x3 - this->x3), 2));
	}
};
class Vector {
private:
	Point Start;
	Point End;
	double length;
public:
	Vector(){
		Start = Point(0, 0, 0);
		End = Point(0, 0, 0);
		length = Start.distance(End);
	}
	Vector(Point Start,Point End){
		this->Start = Point(Start);
		this->End = Point(End);
		length = Start.distance(End);
	}
	Vector(Point End){
		Start = Point(0, 0, 0);
		this->End = Point(End);
		length = Start.distance(End);
	}
	Vector add(Vector& B){
		return Vector(this->Start, Point(B.End));
	}
	void print(){
		cout << "[";
		Start.print();
		cout << ";";
		End.print();
		cout << "]" << endl;
	}
	double getLength(){
		return length;
	}
};
int main(){
	Point A = Point();
	Point B = Point(3,5,6);
	Point C = Point(B);
	A.print();
	B.print();
	C.print();
	Vector D = Vector(A, B);
	Vector E = Vector(B, A);
	D.print();
	E.print();
	Vector F = D.add(E);
	F.print();
	cout << D.getLength();
	return 0;
}
