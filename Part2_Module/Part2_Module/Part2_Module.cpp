
#include <iostream>
#include "systemc.h"

using namespace std;

// create module a no input, no output
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

// create module b no input, no output
SC_MODULE(ModuleB)
{
    void show_module_b()
    {
        cout << "Hello " << name() << endl;
    }
    SC_CTOR(ModuleB)
    {
        SC_METHOD(show_module_b);
    }
};

int sc_main(int, char* [])
{
    ModuleA mod_a("Module_A");

    ModuleB mod_b("Module_B");

    //mod_a.show_module_a();
    sc_start();

    return 0;
}