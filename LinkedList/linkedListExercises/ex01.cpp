#include <iostream>
using namespace std;

class Node
{
    private:
    int firstNumber;
    int secondNumber;

    public:
    Node *next;
    Node(int firstNumber, int secondNumber)
    {
        this->firstNumber = firstNumber;
        this->secondNumber = secondNumber;
    }

    int getfirstNumber()
    {
        return firstNumber;
    }

    int getSecondNumber()
    {
        return secondNumber;
    }

};
class List
{

    public:
    Node *head;
    List()
    {
        head = nullptr;
    }

    void addToEnd(int firstNumber, int secondNumber)
    {   
        Node *newNode = new Node(firstNumber, secondNumber);
        newNode->next = nullptr;

        if(head == nullptr)
        {
            head = newNode;
        }

        else
        {
            Node *current = head; // inicia no head
            while(current->next != nullptr) // Enquanto o próximo for diferente de nulo, percorre a lista
            {
                current = current->next; // o atual recebe o proximo
            }
            current->next = newNode; // quando estiver no ultimo, o proximo elemento ira receber o newNode(novo elemento que foi adicionado)
        }
    }

    void addToStart(int firstNumber, int secondNumber)
    {
        Node *newNode = new Node(firstNumber, secondNumber);
        newNode->next = head; // o próximo nó será o antigo head
        head = newNode;
    }

    void deleteLastElement()
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
    }

    void deleteFirstElement()
    {   
        Node *current = head;
        head = head->next; // o proximo valor se tornara o head
        delete current;
    }

    void sizeOfTheList()
    {
        Node *current = head;
        int count = 0;
        while(current != nullptr)
        {
            current = current->next;
            count++;
        }
        cout << "\nSize of the list: " << count << endl;
    }

    void printList()
    {
        cout << "\nList:" << endl;
        Node *current = head;
        while(current != nullptr)
        {
            cout << "N1: " << current->getfirstNumber() << ", N2: " << current->getSecondNumber() << endl;
            current = current->next;
        }
    }
    void clearMemory()
    {
        Node *current = head;
        while(current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            temp->next = nullptr;
            delete temp;
        }

    }

    string existsInList(Node *node)
    {
        Node *current = head;
        while(current != nullptr)
        {
            if(current->getfirstNumber() == node->getfirstNumber() && current->getSecondNumber() == node->getSecondNumber())
            {   
                return "Exists in the list";
            }

            current = current->next;
        }
        return "Doesn't exist";
    }

};

int main()
{
    List lista;

    lista.addToEnd(10, 20);
    lista.addToEnd(11, 21);
    lista.addToEnd(11, 22);
    lista.addToEnd(1, 23);
    lista.addToStart(1, 2);

    Node *node = new Node(10, 20);
    string returnString = lista.existsInList(node);
    cout << "Return: " << returnString << endl;
    // lista.printList();
    // lista.deleteLastElement();
    // lista.deleteFirstElement();
    lista.printList();
    // lista.sizeOfTheList();

    lista.clearMemory();
    
    return 0;
}