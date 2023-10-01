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
        return number;
    }

    void setNumber(int newNumber)
    {
        this->number = newNumber;
    }
};

class List
{
    public:
    Node *head;
    int sizeList;
    List()
    {
        this->head = nullptr;
        this->sizeList = 0;
    }

    void pushBack(int numberToPush)
    {   
        Node *newNode = new Node(numberToPush);

        if (head == nullptr)
        {
            head = newNode;   
        }
        
        else
        {
            Node *current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        sizeList++;
    }

    void popBack()
    {
        if (head == nullptr)
        {
            cout << "lista vazia" << endl;
        }

        else
        {
        Node *previous = nullptr;
        Node *current = head;
        while(current->next != nullptr)
        {   
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
        delete current;
        sizeList--;
        }
        
    }

    int SizeOfTheList()
    {
        return sizeList;
    }

    int obtainValue(Node *node)
    {
        return node->getNumber();
    }

    int obtainNext(Node *node)
    {   
        if (node->next != nullptr)
        {
            return node->next->getNumber();
        }

        else
        {   
            cout << "Nao ha proximo" << endl;
            return -1;
        }
    }

    void printList()
    {
        Node *current = head;
        while(current != nullptr)
        {
            cout << current->getNumber() << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool ExistsInList(Node *node)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->getNumber() == node->getNumber())
            {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void alterNode(Node *node, int numberToAlter)
    {
        if(ExistsInList(node))
        {   
            node->setNumber(numberToAlter);
        }

        else
        {
            cout << "Nó não encontrado na lista" << endl;
        }
    }

    Node *searchNode(Node *node)
    {
        if(ExistsInList(node))
        {
            return node;
        }

        else
        {
            cout << "Nó não encontrado." << endl;
            return nullptr;
        }
    }

   void clearList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    sizeList = 0;
}

};

int main()
{
    // Criando uma lista
    List myList;

    // Adicionando alguns elementos à lista
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);

    // Imprimindo a lista
    cout << "Lista atual: ";
    myList.printList();

    // Verificando o tamanho da lista
    cout << "Tamanho da lista: " << myList.SizeOfTheList() << endl;

    // Criando um novo nó
    Node *node = new Node(2);
    int saida1 = node->getNumber();
    cout << saida1 << endl;
    myList.alterNode(node, 15);
    int saida = node->getNumber();
    cout << saida << endl;
    myList.printList();
    
    myList.popBack();
    myList.printList();

    myList.obtainNext(node);

    Node noder(1);
    Node *nodeinList = myList.searchNode(&noder);
    cout << "buscando.. " << nodeinList->getNumber();

    myList.clearList();
    myList.printList();

    return 0;
}
