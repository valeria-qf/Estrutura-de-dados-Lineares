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
        this->next = next;
        this->number = number;
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

    void push(int number)
    {
        Node *newNode = new Node(number); // cria novo no
        newNode->next = head; // o proximo no sera o valor de head
        head = newNode; // o novo nó agora é head atual
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "A lista já está vazia!" << endl;
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
        return head == nullptr;
    }

    void printHead()
    {
        if (isEmpty())
        {
            cout << "A lista já está vazia!" << endl;
        }

        else
        {
            cout << "Topo: " << head->getNumber() << endl; 
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
    stack.push(7);
    stack.printHead();
    stack.push(9);
    stack.printHead();
    stack.pop();
    stack.printHead();
    stack.clear();
    
    return 0;
}