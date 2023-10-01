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

    // Getters e Setters
    Node *getNext()
    {
        return next;
    }

    int getNumber()
    {
        return number;
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

class List
{
    private:
    Node *head;
    int sizeList;

    public:
    List()
    {
        this->head = nullptr;
        this->sizeList = 0;
    }

    ~List()
    {
        while(!isEmpty())
        {
            popBack();
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

        if(isEmpty())
        {
            setHead(newNode);
        }

        else
        {
            Node *current = head;
            while(current->getNext() != nullptr)
            {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        sizeList++;
    }

    void popBack()
    {
        if (!isEmpty())
        {   
            Node *current = head;
            Node *previous = nullptr; // precisa declarar o previous por que o próximo elemento do ultimo nó deve apontar para nulo
            while(current->getNext() != nullptr)
            {
                previous = current; // armazena o ultimo elemento
                current = current->getNext();
            }
            previous->setNext(nullptr);
            delete current;
        }

        else
        {
            cout << "A lista já está vazia!" << endl;
        }
    }

    void removeDuplicates()
    {
        Node *current = head;

        while (current != nullptr) // enquanto o atual for diferente de nulo
        {
            Node *aux = current;
            while(aux->getNext() != nullptr) // enquanto o próximo for diferente de nulo
            {
                if(aux->getNext()->getNumber() == current->getNumber()) // se o próximo numero for igual ao numero atual
                {
                    Node *duplicate = aux->getNext(); // o proximo numero é armazenado em um temporario
                    aux->setNext(aux->getNext()->getNext()); // o proximo numero do aux agora será o próximo número do próximo número
                    delete duplicate;
                    sizeList--;
                }

                else // se não houver duplicatas, passa para o proximo numero
                {
                    aux = aux->getNext();
                }
            }
            current = current->getNext(); // avança para o próximo
        }
    }
     void printList()
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
            cout << "List vazio!";
        }
    }

};

int main()
{
    List list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(20);
    list.printList();
    list.removeDuplicates();
    list.printList();
    return 0;
}