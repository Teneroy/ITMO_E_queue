//
// Created by alexc on 1/4/2019.
//

#include "Queue.h"
#include <fstream>
using namespace atdlistaueue;

void readFile(Queue &q, const char * fname)
{
    std::ifstream myReadFile;
    myReadFile.open(fname);
    char name[20], address[20];
    if (myReadFile.is_open())
    {
        while ((!q.full()) && (!myReadFile.eof()))
        {
            myReadFile >> name;
            myReadFile >> address;
            q.enqueue(elem(name, address));
        }
        myReadFile.close();
    }
}

int main()
{
    Queue q;
    char fname[256];
    std::cout << "File name: ";
    std::cin >> fname;
    readFile(q, fname);
    std::cout << "-------------------------------------------------------DATA FROM FILE:-----------------------------------------------" << std::endl;
    q.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------DEQUEUE:------------------------------------------------------" << std::endl;
    q.dequeue();
    q.print();
    std::cout << "EMPTY: " << q.empty() << std::endl;
    std::cout << "FULL: " << q.full() << std::endl;
    std::cout << "FRONT: " << q.front() << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------DEQUEUE:------------------------------------------------------" << std::endl;
    q.dequeue();
    q.print();
    std::cout << "EMPTY: " << q.empty() << std::endl;
    std::cout << "FULL: " << q.full() << std::endl;
    std::cout << "FRONT: " << q.front() << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------DEQUEUE:------------------------------------------------------" << std::endl;
    q.dequeue();
    q.print();
    std::cout << "EMPTY: " << q.empty() << std::endl;
    std::cout << "FULL: " << q.full() << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;

    readFile(q, fname);
    std::cout << "-------------------------------------------------------DATA FROM FILE:-----------------------------------------------" << std::endl;
    q.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------MAKENULL:-----------------------------------------------------" << std::endl;
    q.makenull();
    q.print();
    std::cout << "EMPTY: " << q.empty() << std::endl;
    std::cout << "FULL: " << q.full() << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;


    return 0;
}