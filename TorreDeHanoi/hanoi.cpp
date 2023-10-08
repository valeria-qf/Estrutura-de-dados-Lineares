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
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        this->head = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
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
        return head == nullptr;
    }

    void push(int numberToPush)
    {
        Node *newNode = new Node(numberToPush);

        if (isEmpty())
        {
            setHead(newNode);
        }

        else
        {
            newNode->setNext(head);
            setHead(newNode);
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            setHead(head->getNext());
            delete temp;
        }
    }

    void move(Stack &destination)
    {
        if (!isEmpty() && (destination.isEmpty() || getHead()->getNumber() < destination.getHead()->getNumber()))
        {
            int top = getHead()->getNumber();
            destination.push(top);
            pop();
        }

        else
        {   
            cout << "Nao e possivel mover!" << endl;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Vazio" << endl;
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
    }
};

int main()
{
    Stack originalTower;
    Stack auxTower;
    Stack destinationTower;

    int numDiscs = 3;
    for (int i = numDiscs; i >= 1; i--)
    {
        originalTower.push(i);
    }

    originalTower.move(auxTower);
    auxTower.move(destinationTower);
    originalTower.move(auxTower);
    destinationTower.move(auxTower);
    originalTower.move(destinationTower);
    auxTower.move(originalTower);
    auxTower.move(destinationTower);
    originalTower.move(destinationTower);
    cout << endl;

    originalTower.print();
    auxTower.print();
    destinationTower.print();
    
    return 0;
}
