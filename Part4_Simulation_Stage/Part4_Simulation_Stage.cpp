#include <iostream>
#include "systemc.h"

using namespace std;

SC_MODULE(Stage)
{
    SC_CTOR(Stage)
    {
        cout << "@" << sc_time_stamp() << " : Elabotation: constructor\n";
        SC_THREAD(thread);
    }
    ~Stage()
    {
        cout << sc_time_stamp() << " : Cleanup desctructor\n";
    }

    void thread()
    {
        cout << sc_time_stamp() << " : Excution.initialization\n";
        int i = 0;
        while (true)
        {
            wait(1, SC_SEC);
            cout << sc_time_stamp() << " : Execution.simulation\n";
            if (++i >= 2)
                sc_stop();
        }
    }
    void before_end_of_elaboration() {
        std::cout << "before end of elaboration" << std::endl;
    }
    void end_of_elaboration() {
        std::cout << "end of elaboration" << std::endl;
    }
    void start_of_simulation() {
        std::cout << "start of simulation" << std::endl;
    }
    void end_of_simulation() {
        std::cout << "end of simulation" << std::endl;
    }
};

int sc_main(int, char* [])
{
    Stage stage("Stage");

    sc_start();

    return 0;
}