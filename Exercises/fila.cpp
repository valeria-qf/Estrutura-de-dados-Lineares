#include <iostream>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;

    Node(int number)
    {
        this->number = number;
        this->next = nullptr;
    }
};

class Queue
{
    public:
    Node *head;
    Node *tail;

    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr || tail == nullptr;
    }
        
    void pushBack(int number)
    {
        Node *newNode = new Node(number);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;

        }
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "vazio" << endl;
            tail = nullptr;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        
    }
};

