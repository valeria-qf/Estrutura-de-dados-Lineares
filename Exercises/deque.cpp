#include <iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;
    Node *previous;

    Node(int number)
    {
        this->next = nullptr;
        this->previous = nullptr;
        this->number = number;
    }
};

class Deque
{
    public:
    Node *head;
    Node *tail;

    Deque()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr || tail == nullptr;
    }

    void pushFront(int numberToPush)
    {
        Node *newNode = new Node(numberToPush);
        if(isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    void popFront()
    {
        if(isEmpty())
        {
            cout << "vazio" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;

            if(head != nullptr)
            {
                head->previous = nullptr;
            }

            else
            {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void pushBack(int numberToPush)
    {
        Node *newNode = new Node(numberToPush);
        if(isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "vazio" << endl;
        }

        else
        {   
            Node *temp = tail;
            tail = tail->previous;

            if(tail != nullptr)
            {
                tail->next = nullptr;
            }

            else
            {
                head = nullptr;
            }

            delete temp;
        }
        
    }
};