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

/*_______________________________DVAR implementation___________________________________*/

dvarqueue::Queue::Queue()
{
    _begin = AR_EMPTY;
    _end = AR_SIZE - 1;
}

void dvarqueue::Queue::enqueue(elem x)
{
    if(full())
    {
        std::cout << "QUEUE is full" << std::endl;
    } else
    {
        if(empty())
            _begin++;
        _end = (_end + 1) % AR_SIZE;
        _arr[_end] = x;
    }
}

elem dvarqueue::Queue::dequeue()
{
    if(empty())
    {
        std::cout << "QUEUE is empty" << std::endl;
        return fake_l.data;
    }
    elem x = _arr[_begin];
    //_arr[_begin] = elem("", "");
    if (_begin == _end)
    {
        _begin = AR_EMPTY;
    } else if (_begin == AR_SIZE - 1)
    {
        _begin = 0;
    } else
    {
        _begin++;
    }

}

elem dvarqueue::Queue::front()
{
    if(empty())
    {
        std::cout << "QUEUE is empty" << std::endl;
        return fake_l.data;
    }
    return _arr[_begin];
}

bool dvarqueue::Queue::full()
{
    return ((_end + 1) % AR_SIZE) == _begin;
}

bool dvarqueue::Queue::empty()
{
    return _begin == AR_EMPTY;
}

void dvarqueue::Queue::makenull()
{
    if(!empty())
    {
        _begin = AR_EMPTY;
        _end = AR_SIZE - 1;
    }
}

void dvarqueue::Queue::print()
{
    std::cout << std::setw(25) << "<BEGIN: -> " << _begin << ">";
    std::cout << std::setw(25) << "<END: -> " << _end << ">" << std::endl;
    std::cout << std::setw(25) << "<index>";
    std::cout << std::setw(25) << "<data>" << std::endl;
    for(int i = 0; i < AR_SIZE; i++)
    {
        std::cout << std::setw(25) << i;
        std::cout << std::setw(25) << _arr[i].name << " " << _arr[i].adress << std::endl;
    }
}