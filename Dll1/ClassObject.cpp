#include "pch.h"
#include "ClassObject.h"

#include <iostream>

using namespace std;

extern "C"  __declspec(dllexport) ClassObject *  Constructor()
{
	cout << "Class Created" << endl;
	return new ClassObject;
}

extern "C" __declspec(dllexport)  void Destructor(ClassObject * classobject)
{
	cout << "Class Destroyed" << endl;
	delete classobject;
}
ClassObject::ClassObject() {

}


void ClassObject::SayHello()
{
	cout << "HELLO TEACODE" << endl;
}	