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

    void pushBack(int numberToPushBack)
    {
        Node *newNode = new Node(numberToPushBack);
        if (isEmpty())
        {
            head = tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail->previous = tail;
            tail = newNode;
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "esta vazio" << endl;
            head = nullptr;

        }

        else
        {
            Node *temp = tail;
            tail = tail->previous;
            delete temp;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
        }
        
    }

    void pushFront(int number)
    {
        Node *newNode = new Node(number);
        if (isEmpty())
        {
            head = tail = newNode;
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

            if(head != nullptr)
            {
                head->previous = nullptr;
            }
        }
        
    }
};