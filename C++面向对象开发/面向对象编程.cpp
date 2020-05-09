#include<iostream>
#include "Shape.h"
using namespace std;

int main(int argc, char** argv)
{

	Shape s1{ 5 };
	Shape s2[3]{ {0},{1},{3} };
	cout << "hello" << s2[0].Volume(3) << endl;
	cout << "hello" << s2[1].Volume(3) << endl;
	cout << "hello" << s2[2].Volume(3) << endl;
}