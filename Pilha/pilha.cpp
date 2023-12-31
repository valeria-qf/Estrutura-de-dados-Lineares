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

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void pop()
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
        return head == nullptr;  // se o head for nulo vai retornar true
    }

    void showHead()
    {
        if (isEmpty())
        {
            cout << "Pilha vazia" << endl;
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

    stack.clear();

    return 0;
}
