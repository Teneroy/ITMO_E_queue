//
// Created by alexc on 1/4/2019.
//

#ifndef ITMO_E_QUEUE_QUEUE_H
#define ITMO_E_QUEUE_QUEUE_H
#define Q_SIZE 4
#include "../ITMO_E_listmerge/List.h"
using namespace arrlist;

namespace atdlistaueue
{
    class Queue
    {
    public:
        Queue();
        ~Queue();
        void enqueue(elem x);
        elem dequeue();
        elem front();
        void makenull();
        void print();
    private:
        bool full();
        bool empty();
        List _ob;
        int _size;
    };
}


#endif //ITMO_E_QUEUE_QUEUE_H
