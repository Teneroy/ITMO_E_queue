//
// Created by alexc on 1/4/2019.
//

#ifndef ITMO_E_QUEUE_QUEUE_H
#define ITMO_E_QUEUE_QUEUE_H
#include "../ITMO_E_listmerge/List.h"
using namespace arrlist;

namespace atdlistaueue
{
    class Queue
    {
    public:
        void enqueue(const elem &x);
        elem dequeue();
        elem front() const;
        void makenull();
        void print() const;
        bool full() const;
        bool empty() const;
    private:
        List _ob;
    };
}

namespace dvarqueue
{
    enum {AR_SIZE = 4}; //Константы для реализации кольцевого массива
                                       //AR_SIZE размер массива

    class Queue
    {
    public:
        Queue();
        void enqueue(const elem &x);
        elem dequeue();
        elem front() const;
        void makenull();
        void print() const;
        bool full() const;
        bool empty() const;
    private:
        int _begin; //Начало массива
        int _end; //Конец массива
        elem _arr[AR_SIZE];
        int step(int p) const;
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
        void enqueue(const elem &x);
        elem dequeue();
        elem front() const;
        void makenull();
        void print() const;
        bool full() const;
        bool empty() const;
    private:
        cnode * tail;
    };
}


#endif //ITMO_E_QUEUE_QUEUE_H
