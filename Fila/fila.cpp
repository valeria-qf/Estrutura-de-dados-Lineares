#include <iostream>
using namespace std;

class Node
{
    private:
    int number;

    public:
    Node *next;
    Node(int number)
    {
        this->number = number;
        this->next = nullptr;
    }

    int getNumber()
    {
        return number;
    }
};

class Queue // FIFO 
{
    public:
    Node *head;
    Node *tail;
    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void pushBack(int numberToPush) // insere no fim
    {
        Node *newNode = new Node(numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode; // adiciona o newNode
            tail = newNode; // atualiza o final da fila(tail)
        }
    }

    void popFront() // remove no começo
    {
        if (isEmpty())
        {
            cout << "Fila vazia\n" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr)
            {
                tail = nullptr;
            }  
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void printHead()
    {
        (isEmpty()) ? (cout << "Fila vazia\n" << endl) : (cout << "Topo: " << head->getNumber() << "\n" << endl);
    }

    void printTail()
    {
        (isEmpty()) ? (cout << "Fila vazia\n" << endl) : (cout << "Ultimo: " << tail->getNumber() << "\n");
    }

    void clearQueue()
    {
        while(!isEmpty())
        {
            popFront();
        }

        cout << "A fila foi limpa com sucesso!" << endl;
    }
};

int main()
{
    Queue fila;

    fila.pushBack(3);
    fila.pushBack(2);
    fila.pushBack(1);

    fila.printHead();
    fila.printTail();
    cout << "------------" << endl;
    fila.popFront();
    fila.printHead();
    fila.printTail();
    cout << "------------" << endl;

    fila.popFront();
    fila.printHead();
    fila.printTail();
    cout << "------------" << endl;

    fila.popFront();
    fila.printHead();
    fila.printTail();
    cout << "------------" << endl;
    fila.clearQueue();
    return 0;
}