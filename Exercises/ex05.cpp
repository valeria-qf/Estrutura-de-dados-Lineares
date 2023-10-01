#include <iostream>
using namespace std;

class Node
{
    private:
    int number;
    Node *next;
    Node *previous;
    

    public:
    Node(int number)
    {
        this->number = number;
        this->next = nullptr;
        this->previous = nullptr;

    }

    // Getters e Setters
    Node *getNext()
    {
        return next;
    }

    Node *getPrevious()
    {
        return previous;
    }

    int getNumber()
    {
        return number;
    }

    void setNext(Node *newNext)
    {
        this->next = newNext;
    }

    void setPrevious(Node *newPrevious)
    {
        this->previous = newPrevious;
    }

    void setNumber(int newNumber)
    {
        this->number = newNumber;
    }
};

class Deque
{
    private:
    Node *head;
    Node *tail;
    int dequeSize;

    public:
    Deque()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->dequeSize = 0;
    }

    ~Deque()
    {
        while(!isEmpty())
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

    void pushFront(int numberToPushFront)
    {
        Node *newNode = new Node(numberToPushFront);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }

        else
        {
            newNode->setNext(head);
            head->setPrevious(newNode);
            setHead(newNode);
        }

        dequeSize++;
    }

    void popFront()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            setHead(head->getNext());
            delete temp;

            if (head != nullptr)
            {
                head->setPrevious(nullptr);
            }
            
            else
            {
                setTail(nullptr);
            }
            dequeSize--;
        }

        else
        {
            cout << "O deque está vazio!" << endl;
        }
    }

    void pushBack(int numberToPushBack)
    {
        Node *newNode = new Node(numberToPushBack);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }

        else
        {
            tail->setNext(newNode); // o proximo sera newNode
            newNode->setPrevious(tail); // o anterior ao newNode sera o antigo tail
            setTail(newNode); // tail atualizado para o ultimo elemento (newNode)
        }

        dequeSize++;
    }

    void popBack()
    {
        if (!isEmpty())
        {
            Node *temp = tail;
            tail->setPrevious(tail);
            delete temp;

            if (tail != nullptr)
            {
                tail->setNext(nullptr);
            }

            else
            {
                setHead(nullptr);
            }
            
            dequeSize--;
        }
    }

    void getSize()
    {
        cout << "Tamanho do deque: " << dequeSize << endl;
    }

    void printDeque()
    {   
        if (!isEmpty())
        {
            cout << "\nImprimindo..." << endl;
            Node *current = head;
            while(current != nullptr)
            {
                cout << current->getNumber() << " ";
                current = current->getNext();
            }
        }

        else
        {
            cout << "Deque vazio!";
        }

        cout << "\n-----------------------" << endl;
    }

    void printBackwards()
    {
        if (!isEmpty())
        {
            cout << "\nImprimindo..." << endl;
            Node *current = tail;
            while(current != nullptr)
            {
                cout << current->getNumber() << " ";
                current = current->getPrevious();
            }
        }

        else
        {
            cout << "Deque vazio!";
        }

        cout << "\n-----------------------" << endl;
    }
};

int main()
{
    Deque deque;

    deque.pushFront(10);
    deque.pushFront(20);
    deque.pushBack(40);
    deque.getSize();
    deque.popFront();
    // deque.popFront();
    // deque.popFront();
    // deque.popFront();
    deque.printDeque();
    // deque.printBackwards();

    deque.getSize();

    return 0;
}