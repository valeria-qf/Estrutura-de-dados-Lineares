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
        return this->number;
    }
};

class Queue
{
    public:
    Node *head;
    Node *tail;
    int sizeofQueue;

    Queue()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->sizeofQueue = 0;
    }

    void push(int value) // entra no final
    {
        Node *newNode = new Node(value);
        if (isEmpty()) // se estiver vazio, o head e o tail ira apontar para o elemento adicionado
        {
            head = newNode;
            tail = newNode;
        }
        
        else
        {
            tail->next = newNode; // o newNode é inserido após o tail antigo
            tail = newNode;   // o novo tail agora sera o newNode
        }
        sizeofQueue++;
    }

    bool isEmpty()
    {
        return head == nullptr; // se o head for nulo retorna true
    }


    void pop()
    {
        if (isEmpty())
        {
            cout << "A fila já está vazia!" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr)
            {
                tail == nullptr;
            }
            sizeofQueue--;
        }
    }

    void printHead()
    {
        if (isEmpty())
        {
            cout << "fila vazia" << endl;
        }
        else
        {
            cout << "Topo: " << head->getNumber() << endl;
        }
    }

    void printTail()
        {
            if (isEmpty())
            {
                cout << "fila vazia" << endl;
            }
            else
            {
                cout << "Ultimo: " << tail->getNumber() << endl;
            }
        }

    void destroyQueue()
    {
        while(!isEmpty())
        {
            pop();
        }
    }

    void size()
    {
        cout << "Tamanho da fila: " << sizeofQueue << endl;
    }
};

int main()
{
    Queue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    queue.printHead();
    queue.printTail();
    queue.size();
    queue.pop();
    queue.printHead();
    queue.size();
    queue.destroyQueue();
    queue.size();

    return 0;
}