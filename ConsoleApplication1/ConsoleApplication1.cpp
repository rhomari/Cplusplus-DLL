// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "windows.h"

using namespace std;
class ClassObject
{
public:
    ClassObject();


    virtual void SayHello();


};
int main()
{
    HMODULE module = LoadLibraryA("Dll1.dll");
    if (module == NULL) {
        cout << "ERROR loadLibrairy" << endl;
        cout << GetLastError() << endl;
        return 1;
    }
    FARPROC myfunction = GetProcAddress(module, "Constructor");
    if (myfunction == NULL) {
        cout << "ERROR GetProcAddress" << endl;
        cout << GetLastError() << endl;
        return 1;
    }
   
    ClassObject  * classobject =(ClassObject*) myfunction();
    classobject->SayHello();

    return 0;   
   
}
