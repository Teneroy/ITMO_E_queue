//
// Created by alexc on 1/4/2019.
//

#include "Queue.h"

void atdlistaueue::Queue::enqueue(elem x)
{
    _ob.insert(_ob.endL(), x);
}

elem atdlistaueue::Queue::dequeue()
{
    elem x = _ob.retrieve(_ob.firstL());
    _ob.deleteEl(_ob.firstL());
    return x;
}

elem atdlistaueue::Queue::front()
{
    return _ob.retrieve(_ob.firstL());
}

bool atdlistaueue::Queue::full()
{
    return false;
}

bool atdlistaueue::Queue::empty()
{
    return _ob.endL() == 0;
}

void atdlistaueue::Queue::makenull()
{
    _ob.makenull();
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
    if(empty())
       _begin++;
    _end = (_end + 1) % AR_SIZE;
    _arr[_end] = x;
}

elem dvarqueue::Queue::dequeue()
{
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
    _begin = AR_EMPTY;
    _end = AR_SIZE - 1;
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

/*________________________________________CIRCLE LIST____________________________________________*/

circlelist::Queue::Queue()
{
    tail = nullptr;
}

circlelist::Queue::~Queue()
{
    makenull();
}

void circlelist::Queue::enqueue(elem x)
{
    if(empty())
    {
        tail = new cnode();
        tail -> data = x;
    } else
    {
        cnode * temp = tail -> next;
        if(temp != tail)
        {
            tail -> next = new cnode(x, temp);
            tail = tail -> next;
            tail -> next = temp;
        } else
        {
            tail -> next = new cnode(x, tail);
            tail = tail -> next;
        }
    }
}

elem circlelist::Queue::dequeue()
{
    cnode * temp = tail -> next;
    elem x = temp -> data;
    if(temp == tail)
    {
        tail = nullptr;
    } else
    {
        tail -> next = temp -> next;
        delete temp;
    }
    return x;
}

elem circlelist::Queue::front()
{
    return tail -> next -> data;
}

bool circlelist::Queue::full()
{
    return false;
}

bool circlelist::Queue::empty()
{
    return tail == nullptr;
}

void circlelist::Queue::makenull()
{
     cnode * temp1;
     cnode * temp2 = tail -> next;
     while (temp2 != tail)
     {
         temp1 = temp2;
         temp2 = temp2 -> next;
         delete temp1;
     }
     tail = nullptr;
}

void circlelist::Queue::print()
{
    if(!empty())
    {
        cnode * temp = tail -> next;
        std::cout << std::setw(25) << "<data>" << std::endl;
        while (temp != tail)
        {
            std::cout << std::setw(25) << temp -> data.name << " "  << temp -> data.adress << std::endl;
            temp = temp -> next;
        }
        std::cout << std::setw(25) << temp -> data.name << " "  << temp -> data.adress << std::endl;
    }
}