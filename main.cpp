//
// Created by alexc on 1/4/2019.
//

#include "Queue.h"
using namespace dvarqueue;

int main()
{
    elem x("x", "x");
    elem y("y", "y");
    elem z("z", "z");
    elem k("k", "k");
    Queue a;
    std::cout << "empty: " << a.empty() << std::endl;
    a.print();
    a.enqueue(x);
    a.print();
    a.enqueue(y);
    a.print();
    a.enqueue(z);
    a.print();
//    a.enqueue(k);
//    a.print();
    std::cout << "full: " << a.full() << std::endl;
    a.print();
    a.dequeue();
    a.print();
    std::cout << "front Result: " << a.front().name << std::endl;
    a.dequeue();
    a.print();
    std::cout << "empty: " << a.empty() << std::endl;
    a.print();
    std::cout << "empty: " << a.empty() << std::endl;
    a.enqueue(z);
    a.print();
    a.makenull();
    std::cout << "empty: " << a.empty() << std::endl;
    //a.print();

return 0;
}