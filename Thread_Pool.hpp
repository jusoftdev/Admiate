#include <iostream>
#include <vector>
#include <thread>

using namespace std;


class Thread_Pool {
public:
    vector<thread> Pool;

    int wait_for_pool() {
        for (thread& t : Pool) {
            t.join();
        }
        return 0;
    }

    int start_pool(int number, int (*target)(int), int arg) {
        for (int i{ 0 }; i < number; i++) {
            loop:
            try {
                Pool.emplace_back(target, arg);
            }
            catch (...) {
                for (int w{ 0 }; w < 700000;w++);
                goto loop;
            }
        }
        return 0;
    }

    int start_thread(int Network_Scan::*target, string sarg) {
        start:
        try {
            Pool.emplace_back(target, sarg);
        }
        catch (...){
            for (int w{ 0 }; w < 700000;w++);
            goto start;
        }
        return 0;
    }
};