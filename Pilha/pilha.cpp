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

class Stack
{
    public:
        Node *head;
        Stack()
        {
            this->head = nullptr;
        }

    void push(int value) // LIFO - o ultimo sempre é adicionado no head
    {
        Node *newNode = new Node(value);
        newNode->next = head; // o próximo elemento sera o antigo head
        head = newNode; // o novo head sera o novo nó
    }

    void pop() // desempilhar
    {
        if (isEmpty())
        {
           cout << "Pilha vazia" << endl;
        }

        else
        {
        Node *current = head;
        head = head->next;
        delete current;
        }
    }

    bool isEmpty()
    {   
        bool verify = false;
        if (head == nullptr)
        {
            verify = true;
        }
        return verify;
    }

    void showHead()
    {
        if(isEmpty())
        {
            cout << "Pilha vazia" << endl;
        }

        if (head != nullptr)
        {
            cout << "Topo: "<< head->getNumber() << endl;
        }
        
    }

     void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.showHead();
    stack.pop(); 
    stack.showHead();
    stack.pop(); 
    stack.showHead();
    stack.pop(); 
    stack.showHead();

    // if (stack.isEmpty())
    // {
    //     cout << "Pilha esta vazia" << endl;
    // }
    // else
    // {
    //     cout << "Pilha nao esta vazia " << endl;
    // }

    stack.clear(); 

    return 0;
}
