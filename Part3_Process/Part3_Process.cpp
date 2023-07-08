#include <iostream>
#include "systemc.h"

using namespace std;

SC_MODULE(Process)
{
    sc_clock clk;
    SC_CTOR(Process) : clk("clk", 1, SC_SEC)
    {
        cout << "Module name " << name() << endl;
        SC_METHOD(method);
        SC_THREAD(thread);
        SC_CTHREAD(cthread, clk); // wait() se dc delay theo clk
    }
    void method()
    {
        cout << "@" << sc_time_stamp() << "::method\n";
        next_trigger(sc_time(2, SC_SEC));
        //wait(1, SC_SEC);
    }
    void thread()
    {
        while (true)
        {
            cout << "@" << sc_time_stamp() << "::thread\n";
            wait(2, SC_SEC);
            //next_trigger(sc_time(1, SC_SEC)); // Not use
        }
    }
    void cthread()
    {
        while (true)
        {
            cout << "@" << sc_time_stamp() << "::cthread\n";
            wait();
            //next_trigger(sc_time(1, SC_SEC)); // Note use
        }
    }
};
int sc_main(int, char *[])
{
    Process process("Process");
    cout << "Excution phase begins @ " << sc_time_stamp() << endl;

    sc_start(5, SC_SEC);

    cout << "Excution phase ends @ " << sc_time_stamp() << endl;
    return 0;
}