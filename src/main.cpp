#include <iostream>
#include <vector>

#include "virtual_worker.h"
#include "worker.h"
#include "undefined.h"

int main() {
    //using namespace Workers;
    using namespace VirtualWorkers;

    Waiter waiter("Vassily Popkine", 123L, 4);
    Singer singer("Ivan Piotr", 666L, 3);
    Waiter w_temp;
    Singer s_temp;
    Worker* pw[4] = { &waiter, &singer, &w_temp, &s_temp };
    int i{};
    for (i = 2; i < 4; i++) pw[i]->set();
    for (i = 0; i < 4; i++) {
        pw[i]->show();
        std::cout << std::endl;
    }

    SingingWaiter sw;
    sw.set();
    sw.show();

    F f;
    f.f1();
    f.f2();

    return 0;
}
