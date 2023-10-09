// Implemente uma função que divida uma lista encadeada em duas listas igualmente balanceadas, mesmo que a lista original tenha um número ímpar de elementos. Por exemplo, se a lista for 1 -> 2 -> 3 -> 4 -> 5, a função deve dividir em duas listas 1 -> 2 -> 3 e 4 -> 5.

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

    void setNext(Node *newNext)
    {
        this->next = newNext;
    }
};

class List
{
    private:
    Node *head;

    public:
    int size;
    List()
    {
        this->head = nullptr;
        this->size = 0;
    }

    ~List()
    {
        while(!isEmpty())
        {
            popFront();
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

    void pushBack(int numberToPush)
    {
        Node *newNode = new Node(numberToPush);
        Node *current = head;
        if (isEmpty())
        {
            head = newNode;
        }

        else
        {
            while(current->getNext() != nullptr)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        size++;
    }

    void pushMiddle(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);
        Node *current = head;
        Node *previous = nullptr;

        if(isEmpty())
        {
            head = newNode;
        }

        else
        {
            for (int i = 0; i < size/2; i++) // encontra o meio
            {
                previous = current; // armazena o anterior
                current = current->getNext(); // percorre para o proximo
            }
            previous->setNext(newNode); // o nó anterior ao meio terá newNode como next
            newNode->setNext(current); // o newNode terá como próximo o current
            size++;
        }
    }

    void popMiddle()
    {
        if (isEmpty())
        {
            cout << "Lista vazia!" << endl;
        }
        else
        {   
            Node *current = head;
            Node *previous = nullptr;
            for (int i = 0; i < size/2; i++) // percorre ate a metade
            {
                previous = current;
                current = current->getNext();
            }

            previous->setNext(current->getNext()); // o proximo elemento agora sera o next
            delete current; // remove o current 
        }
        
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
            newNode->setNext(head);
            setHead(newNode);
        }
        size++;       
    }

    void popBack()
    {
        if(isEmpty())
        {
            cout << "Lista vazia!" << endl;
        }

        else
        {
            Node *current = head;
            Node *previous = nullptr;
            while (current->getNext() != nullptr)
            {   
                previous = current;
                current = current->getNext();
            }

            previous->setNext(nullptr);
            delete current;
            size--;
        }
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Lista vazia!" << endl;
        }

        else
        {
            Node *temp = head;
            setHead(head->getNext());
            delete temp;
        } 
    }

void print()
{
    Node *current = head;
    while(current != nullptr)
    {
        cout << current->getNumber() << " ";
        current = current->getNext();
    }
    cout << endl;
}

void printReverse()
{
    if (!isEmpty())
    {   
        Node *current = head;
        revert(current);
        cout << endl;
    }
}

void revert(Node *current)
{
    if (current == nullptr)
    {
        return;
    }

    revert(current->getNext());
    cout << current->getNumber() << " ";
}

void splitList(List &firstHalf, List &secondHalf)
{
    if (isEmpty())
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < size / 2; i++)   // Encontra o meio
    {
        previous = current;
        current = current->getNext();
    }

    secondHalf.setHead(current); // o head da segunda metade sera o current
    secondHalf.size = size - size / 2; // Ajustar o tamanho da segunda metade

    if (previous != nullptr)  // ajustar a lista original (primeira metade)
    {
        // Se previous não for nulo, ajustamos o próximo dele para nulo
        previous->setNext(nullptr);
    }

    firstHalf.setHead(head);
    firstHalf.size = size / 2; // ajustar o tamanho da primeira metade

    // limpar a lista original
    head = nullptr;
    size = 0;
}
};

int main()
{
    List list;
    List A;
    List B;

    list.pushFront(10);
    list.pushFront(4);
    list.pushFront(1);
    list.pushFront(5);
    list.pushFront(5);
    list.print();
    list.popMiddle();
    list.print();
    // list.splitList(A, B);
    // A.print();
    // B.print();

    return 0;
}