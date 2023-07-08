
#include <iostream>
#include "systemc.h"

using namespace std;

// create 1 

SC_MODULE(ModuleA)
{
    void show_module_a()
    {
        cout << "Hello " << name();
    }
    SC_CTOR(ModuleA)
    {
        SC_METHOD(show_module_a);
    }
};

int sc_main(int, char* [])
{
    ModuleA mod_a("Module_A");

    //mod_a.show_module_a();
    sc_start();

    return 0;
}