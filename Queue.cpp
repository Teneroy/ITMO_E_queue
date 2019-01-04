//
// Created by alexc on 1/4/2019.
//

#include "Queue.h"

node fake_l;

atdlistaueue::Queue::Queue()
{
    _size = 0;
}

atdlistaueue::Queue::~Queue()
{
    _ob.makenull();
}

void atdlistaueue::Queue::enqueue(elem x)
{
    if(full())
    {
        std::cout << "QUEUE is full" << std::endl;
    } else
    {
        _ob.insert(_ob.endL(), x);
        _size++;
    }
}

elem atdlistaueue::Queue::dequeue()
{
    if(empty())
    {
        std::cout << "QUEUE is empty" << std::endl;
        return fake_l.data;
    }
    elem x = _ob.retrieve(_ob.firstL());
    _ob.deleteEl(_ob.firstL());
    _size--;
    return x;
}

elem atdlistaueue::Queue::front()
{
    if(empty())
    {
        std::cout << "QUEUE is empty" << std::endl;
        return fake_l.data;
    }
    return _ob.retrieve(_ob.firstL());
}

bool atdlistaueue::Queue::full()
{
    return _size == Q_SIZE;
}

bool atdlistaueue::Queue::empty()
{
    return _size == 0;
}

void atdlistaueue::Queue::makenull()
{
    if(!empty())
    {
        _size = 0;
        _ob.makenull();
    }
}

void atdlistaueue::Queue::print()
{
    _ob.printList();
}