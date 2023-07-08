#include <iostream>
#include <systemc>

using namespace std;

//Hello_SystemC is module name
SC_MODULE(hello_systemc)
{
    SC_CTOR(hello_systemc)
    {
        // constructor
    }
    void Say_Hello()
    {
        // print "Hello SystemC" to the console
        cout << "Hello SystemC!!!";
    }
};

// sc_main in top level fuction like in C++ main
int sc_main(int argc, char* argv[])
{
    hello_systemc hello("hello");
    
    // Print the hello systemc
    hello.Say_Hello();
    return 0;
}

