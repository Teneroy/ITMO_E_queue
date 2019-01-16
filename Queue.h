//
// Created by alexc on 1/4/2019.
//

#ifndef ITMO_E_QUEUE_QUEUE_H
#define ITMO_E_QUEUE_QUEUE_H
//#define AR_SIZE 4
//#define AR_EMPTY -1
#include "../ITMO_E_listmerge/List.h"
using namespace arrlist;

namespace atdlistaueue
{
    class Queue
    {
    public:
        void enqueue(data_type x);
        data_type dequeue();
        data_type front();
        void makenull();
        void print();
        bool full();
        bool empty();
    private:
        List _ob;
    };
}

namespace dvarqueue
{
    enum {AR_SIZE = 4, AR_EMPTY = -1};

    class Queue
    {
    public:
        Queue();
        void enqueue(data_type x);
        data_type dequeue();
        data_type front();
        void makenull();
        void print();
        bool full();
        bool empty();
    private:
        int _begin;
        int _end;
        data_type _arr[AR_SIZE];
    };
}

namespace circlelist
{

    struct cnode
    {
        data_type data;
        cnode * next;
        cnode()
        {
            next = this;
        }
        cnode(data_type x, cnode * n):data(x),next(n)
        {}
    };

    class Queue
    {
    public:
        Queue();
        ~Queue();
        void enqueue(data_type x);
        data_type dequeue();
        data_type front();
        void makenull();
        void print();
        bool full();
        bool empty();
    private:
        cnode * tail;
    };
}


#endif //ITMO_E_QUEUE_QUEUE_H
