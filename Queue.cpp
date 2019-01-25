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
    _begin = 0;
    _end = AR_SIZE - 1;//Задаю концу списка позицию, чтобы тот при первом добавлении, писал в ноль
}

void dvarqueue::Queue::enqueue(elem x)
{
    _end = step(_end);
    _arr[_end] = x;
}

elem dvarqueue::Queue::dequeue()
{
    _begin = step(_begin);
}

elem dvarqueue::Queue::front()
{
    return _arr[_begin]; //Возвращаем первый элемент
}

bool dvarqueue::Queue::empty()
{
    return step(_end) == _begin; //Если позиция после последней равна началу, то массив заполнен
}

bool dvarqueue::Queue::full()
{
    std::cout << "STEP: " << step(step(_end)) << std::endl;
    return step(step(_end)) == _begin; //Если начало равно обозначению пустого массива, то массив пуст
}

void dvarqueue::Queue::makenull() //Зануляем
{
    _begin = 0;
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

int dvarqueue::Queue::step(int p)
{
    return ((p + 1) % AR_SIZE);
}

/*________________________________________CIRCLE LIST____________________________________________*/

circlelist::Queue::Queue()
{
    tail = nullptr;
}

circlelist::Queue::~Queue()
{
    if(tail != nullptr)
    {
        makenull();
    }
}

void circlelist::Queue::enqueue(elem x)
{
    if(tail == nullptr)
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
        delete temp;
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