#include <iostream>
using namespace std;

class Node
{
    private:
    int number;

    public:
    Node *previous;
    Node *next;
    Node(int number)
    {
        this->number = number;
        this->previous = nullptr;
        this->next = nullptr;
    }
    int getNumber()
    {
        return this->number;
    }
};

class Deque
{
    public:
    Node *head;
    Node *tail;
    int size;
    Deque()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void pushFront(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            newNode->next = head; // o proximo no será o antigo head
            head->previous = newNode; // o nó anterior ao antigo head agora será o novo nó
            head = newNode; // o head agora aponta para novo nó
        }

        size++;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Deque vazio!\n" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            if (head != nullptr)
            {
                head->previous = nullptr;
            }

            if (head == nullptr)
            {
                tail = nullptr;
            }

            size--;
        }
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
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }

        size++;   
    }

    void popBack()
    {
        if (isEmpty())
        {
            cout << "Deque vazio\n" << endl;
        }

        else
        {
            Node *temp = tail;
            tail = tail->previous;
            delete temp;

            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            
            if (tail == nullptr)
            {
               head = nullptr;
            }
            
            size--;
        }
        
    }

    int dequeSize()
    {   
        return size;
    }

    int firstElement()
    {
        if(isEmpty())
        {
            cout << "O deque está vazio";
            return -1;
        }

        else
        {
            return head->getNumber();
        }
    }

    int lastElement()
    {
        if(isEmpty())
        {
            cout << "O deque está vazio";
            return -1;
        }

        else
        {
            return tail->getNumber();
        }
    }

    void printDeque()
    {   
        if (isEmpty())
        {
            cout << "\nDeque vazio" << endl;
        }

        else
        {
            Node *current = head;

            while(current != nullptr)
            {   
                cout << current->getNumber() << " ";
                current = current->next;
            }

            cout << endl;
        }
    }

    void clearDeque()
    {
        while(!isEmpty())
        {
            popFront();
        }
    }
};

int main()
{
    Deque deque;

    deque.pushFront(10);
    int first = deque.firstElement();
    deque.pushBack(4);
    cout << "\nPrimeiro elemento: " << first << endl;

    deque.pushBack(1);
    deque.popBack();

    int last = deque.lastElement();
    cout << "Ultimo elemento: " << last << endl;

    deque.pushFront(5);

    int dequeSize = deque.dequeSize();
    cout << "\nTamanho do deque: " << dequeSize << endl;

    deque.popFront();
    
   

    cout << "\n----------------------------" << endl;
    deque.printDeque();
    deque.clearDeque();
    deque.printDeque();

    return 0;
}