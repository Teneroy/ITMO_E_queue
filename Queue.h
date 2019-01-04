//
// Created by alexc on 1/4/2019.
//

#ifndef ITMO_E_QUEUE_QUEUE_H
#define ITMO_E_QUEUE_QUEUE_H
#define Q_SIZE 4
#define AR_SIZE 4
#define AR_EMPTY -1
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

namespace dvarqueue
{
    class Queue
    {
    public:
        Queue();
        void enqueue(elem x);
        elem dequeue();
        elem front();
        void makenull();
        void print();
    private:
        bool full();
        bool empty();
        int _begin;
        int _end;
        elem _arr[AR_SIZE];
    };
}

namespace circlelist
{

    struct cnode
    {
        elem data;
        cnode * next;
        cnode()
        {
            next = this;
        }
        cnode(elem x, cnode * n):data(x),next(n)
        {}
    };

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
        cnode * tail;
        int _size;
    };
}


#endif //ITMO_E_QUEUE_QUEUE_H
