#include <iostream>
using namespace std;

class Node
{
    private:
    int number;

    public:
    Node *previous;
    Node *next;
    Node(int number)
    {
        this->number = number;
        this->previous = nullptr;
        this->next = nullptr;
    }
    int getNumber()
    {
        return this->number;
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
        return head == nullptr;
    }

    void pushFront(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            newNode->next = head; // o proximo no será o antigo head
            head->previous = newNode; // o nó anterior ao antigo head agora será o novo nó
            head = newNode; // o head agora aponta para novo nó
        }
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Deque vazio!\n" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if (head != nullptr)
            {
                head->previous = nullptr;
            }

            if (head == nullptr)
            {
                tail = nullptr;
            }
        
        }
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "Deque vazio\n" << endl;
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
            
            if (tail == nullptr)
            {
               head = nullptr;
            }
            
        }
        
    }

    void pushBack(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode
        }

        else
        {   
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        
    }

    void printDeque()
    {
        Node *current = head;

        while(current != nullptr)
        {   
            cout << current->getNumber() << endl;
            current = current->next;
        }

        cout << endl;
    }

    void clearDeque()
    {
        while(!isEmpty())
        {
            popFront();
        }
    }
};