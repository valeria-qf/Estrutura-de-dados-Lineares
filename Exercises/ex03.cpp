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
        this->next = nullptr;
        this->number = number;
    }

    int getNumber()
    {
        return number;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *newNext)
    {
        this->next = newNext;
    }

    void setNumber(int newNumber)
    {
        this->number = newNumber;
    }
};

class Stack // LIFO
{
    private:
    Node *head;
    int stackSize;

    public:
    Stack()
    {
        this->head = nullptr;
        this->stackSize = 0;
    }

    ~ Stack()
    {
        while(!isEmpty()) // enquanto não estiver vazio(false)
        {
            popFront();
        }
    }

    int getStackSize()
    {
        return stackSize;
    }

    Node *getHead()
    {
        return head;
    }

    void setHead(Node *newHead)
    {
        this->head = newHead;
    }

    bool isEmpty()
    {
        return head == nullptr; // se o head for nulo, retorna true
    }

    void pushFront(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);

        if (isEmpty())
        {
            head = newNode;
        }

        else
        {
            newNode->setNext(head); // o newNode aponta para o antigo head
            head = newNode;
        }

        stackSize++;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "A pilha já está vazia" << endl;
        }

        else
        {
            Node *temp = head; // ponteiro temporario recebe o head antigo
            head = head->getNext();
            delete temp; // deleta o head antigo
            stackSize--;
        }  
    }

    void printStack()
    {       
        if (!isEmpty())
        {
            cout << "\nImprimindo pilha..." << endl;
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->getNumber() << " ";
                current = current->getNext();
            } 
            cout << "\n---------------------" << endl;
        }

        else
        {
            cout << "\nA pilha esta vazia" << endl;
            cout << "\n---------------------" << endl;
        }
    }

    void sizeofStack()
    {
        int size = getStackSize();
        cout << "\nTamanho da pilha: " << size << endl;
    }

    void showTop()
    {
        if (!isEmpty())
        {
            int top = head->getNumber();
            cout << "\nTopo: " << top << endl;
        }
        else
        {
            cout << "\nPilha vazia, não há topo" << endl;
        }
        
    }
};

int main()
{
    Stack stack;
    stack.pushFront(10);
    // stack.showTop();
    stack.pushFront(20);
    stack.showTop();
    // stack.popFront();
    // stack.popFront();
    stack.printStack();
    // stack.showTop();
    stack.sizeofStack();
    return 0;
}

