#include <iostream>
using namespace std;

class Node
{
    private:
    int number;
    Node *next;

    public:
    Node(int number)
    {
        this->number = number;
        this->next = nullptr;
    }

    int getNumber()
    {
        return number;
    }

    Node *getNext()
    {
        return next;
    }

    void setNumber(int newNumber)
    {
        this->number = newNumber;
    }

    void setNext(Node *newNext)
    {
        this->next = newNext;
    }

};

class Queue // FIFO - entra no fim, sai no começo
{
    private:
    Node *head;
    Node *tail;
    int queueSize;

    public:
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->queueSize = 0;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            popFront();
        }
    }

    // Getters e Setters
    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getQueueSize()
    {
        return queueSize;
    }

    void setHead(Node *newHead)
    {
        this->head = newHead;
    }

    void setTail(Node *newTail)
    {
        this->tail = newTail;
    }

    // Metodos

    bool isEmpty()
    {
        return head == nullptr;
    }

    void pushBack(int numberToPush)
    {
        Node *newNode = new Node (numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->setNext(newNode); // o proximo agora sera o newnode
            setTail(newNode);
        }
        queueSize++;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "\nA fila está vazia!" << endl;
        }

        else
        {
            Node *temp = head;
            setHead(head->getNext());
            queueSize--;

            if (head == nullptr)
            {
                tail = nullptr;
            }      
        }     
    }

    void printQueue()
    {
        cout << "\nImprimindo fila..." << endl;
        if (isEmpty())
        {
            cout << "Fila vazia" << endl;
        }

        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->getNumber() << " ";
                current = current->getNext();
            }
            cout << endl;
        }
        cout << "------------------------" << endl;   
    }

    void showHead()
    {
        if(isEmpty())
        {
            cout << "Fila vazia!" << endl;
        }

        else
        {
            cout << "Topo: " << head->getNumber() << endl;
        }
    }

    void showTail()
    {
        if(isEmpty())
        {
            cout << "Fila vazia!" << endl;
        }

        else
        {
            cout << "Final: " << tail->getNumber() << endl;
        }
    }

    void getSize()
    {
        cout << "\nTamanho da fila: " << getQueueSize() << endl;
    }
};

int main()
{
    Queue queue;

    queue.pushBack(10);
    queue.pushBack(20);
    queue.showHead();
    queue.showTail();
    queue.printQueue();
    queue.getSize();
    queue.popFront();
    // queue.showHead();
    // queue.showTail();
    queue.printQueue();
    queue.popFront();
    // queue.getSize();
    // queue.showHead();
    // queue.showTail();
}