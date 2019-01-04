//
// Created by alexc on 1/4/2019.
//

#include "Queue.h"
using namespace circlelist;

int main()
{
    elem x("x", "x");
    elem y("y", "y");
    elem z("z", "z");
    elem k("k", "k");
    Queue a;
    a.enqueue(x);
    a.print();
    a.enqueue(y);
    a.print();
    a.enqueue(z);
    a.print();
    a.enqueue(k);
    a.enqueue(x);
    a.print();
    a.dequeue();
    a.print();
    std::cout << "front Result: " << a.front().name << std::endl;
    a.dequeue();
    a.print();
    a.dequeue();
    a.print();
    a.dequeue();
    a.enqueue(x);
    a.enqueue(y);
    a.print();
    a.makenull();
//    a.print();

return 0;
}