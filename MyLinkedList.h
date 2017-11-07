

#ifndef CINEMA_MYLINKEDLIST_H
#define CINEMA_MYLINKEDLIST_H

#include<iostream>
using namespace std;


template <class T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *prev;
public:
    Node(const T & data);
    T getData() const;
    Node<T>* getPrev() { return prev;};
    Node<T>* getNext() {return next;};
    void setPrev(Node<T>* node) {prev = node;};
    void setNext(Node<T>* node) {next = node;};

};

/*
T should have:
    operator <<   --> for printing with cout
    operator ==   --> for comparing
    default c'tor --> for creating the array
*/

template<class T>
class MyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    MyLinkedList();
    ~MyLinkedList();
    void pushBack(const T& data);
    void remove(const T& data);
    T getAt(int index) const;
    int getSize() const;

    friend ostream& operator<<(ostream& os, const MyLinkedList&  myLinkedList)
    {
        Node<T>* nextNode = myLinkedList.head->getNext();

        for (int i = 0; i < myLinkedList.size; i++)
        {
            os << *nextNode->getData() << ",";
            nextNode = nextNode->getNext();
        }
        os << "\b ";
        return os;
    }
};


template<class T>
Node<T>::Node(const T & data) :data(data)
{
    this->prev = this->next = nullptr;
}

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
MyLinkedList<T>::MyLinkedList()
{
    tail = head = nullptr;
    size = 0;
}

template<class T>
MyLinkedList<T>::~MyLinkedList()
{
    Node<T>* nextNode = head;

    while(head != tail)
    {
        nextNode = nextNode->getNext();
        delete head;
        head = nextNode;
    }
    delete tail;
}

template<class T>
void MyLinkedList<T>::remove(const T& data)
{
    Node<T>* nextNode = head;
    while (nextNode != nullptr)
    {
        if (nextNode->getData() == data)
        {
            if (nextNode == head)
            {
                head = head->getNext();
                if(head == nullptr) //in case there is only one node
                {
                    tail = nullptr;
                }
                else
                {
                    head->getPrev() = nullptr;

                }
                delete nextNode;
            }
            else if (nextNode == tail)
            {
                tail = tail->getPrev();
                delete nextNode;
                tail->getNext() = nullptr;
            }
            else
            {
                Node<T>* rightNode = nextNode->getNext();
                Node<T>* leftNode = nextNode->getPrev();
                delete nextNode;
                leftNode->nextNode = rightNode;
                rightNode->prevNode = leftNode;
            }
            --size;
            return;
        }
        nextNode = nextNode->getNext();
    }
}

template<class T>
T MyLinkedList<T>::getAt(int index) const
{
    Node<T>* nextNode = head;
    for (int i = 0; i < index; i++)
    {
        nextNode = nextNode->getNext();
    }
    return nextNode->getData();
}

template<class T>
int MyLinkedList<T>::getSize() const
{
    return size;
}

template<class T>
void MyLinkedList<T>::pushBack(const T& data)
{

    Node<T>* newNode = new Node<T>(data);
    size++;
    if(head == nullptr)
    {
        tail = head = newNode;
    }
    else if(tail == head)
    {
        tail = newNode;
        tail->setPrev(head);
        head->setNext(tail);
    }
    else
    {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
}

#endif


