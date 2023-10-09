#include <iostream>
using namespace std;

class Node
{
    private:
    Node *next;

    public:
    int number;
    Node(int number)
    {
        this->next = nullptr;
        this->number = number;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *newNext) 
    {
        this->next = newNext;
    }
};

class Queue
{
    private:
    Node *head;
    Node *tail;

    public:
    int size;
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~Queue()
    {
        while(!isEmpty())
        {
            popFront();
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void pushBack(int numberToPush)
    {
        Node *newNode = new Node(numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
           tail->setNext(newNode);
           tail = newNode;
        }
        size++;
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
            head = head->getNext();
            delete temp;
            
            if(head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    void print()
    {
        if (!isEmpty())
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->number << " ";
                current = current->getNext();
            }
            cout << endl;
        }
    }

    void printReverse()
    {
        Node *current = head;
        revert(current);
        cout << endl;
    }

    void revert(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }

        revert(current->getNext());
        cout << current->number << " ";
    }

    void splitQueue()
{
    if (isEmpty())
    {
        cout << "A fila está vazia." << endl;
        return;
    }

    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < size / 2; i++)
    {
        previous = current;
        current = current->getNext();
    }

    Queue firstQueue, secondQueue;

    secondQueue.head = current;
    secondQueue.size = size - size / 2;

    if (previous != nullptr)
    {
        previous->setNext(nullptr);
    }

    firstQueue.head = head;
    firstQueue.size = size / 2;

    head = nullptr;
    size = 0;

    cout << "Primeira fila:" << endl;
    firstQueue.print();
    cout << "Segunda fila:" << endl;
    secondQueue.print();
}

};

int main()
{
    Queue queue;


    queue.pushBack(10);
    queue.pushBack(20);
    // queue.print();
    // queue.printReverse();
    // queue.popFront();
    // queue.print();
    queue.splitQueue();
    return 0;
}