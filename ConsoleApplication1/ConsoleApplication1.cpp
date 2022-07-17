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
    typedef void   (*Destroyer) (ClassObject*);
    
    HMODULE module = LoadLibraryA("Dlltest.dll");
    if (module == NULL) {
        cout << "ERROR loadLibrairy" << endl;
        cout << GetLastError() << endl;
        return 1;
    }
    FARPROC Constructor = GetProcAddress(module, "Constructor");
    Destroyer  Destructor = (Destroyer)GetProcAddress(module, "Destructor");
    if (Constructor == NULL) {
        cout << "ERROR GetProcAddress" << endl;
        cout << GetLastError() << endl;
        return 1;
    }
   
    ClassObject  * classobject =(ClassObject*)Constructor();
    classobject->SayHello();
    Destructor(classobject);
    

    return 0;   
   
}
