#include <iostream>
using namespace std;

class Node
{
    private:
    int firstNumber;
    int secondNumber;

    public:
    Node *next;
    Node(int firstNumber, int secondNumber) // Construtor
    {
        this->firstNumber = firstNumber;
        this->secondNumber = secondNumber;
    }

    int getfirstNumber()
    {
        return this->firstNumber;
    }

    int getSecondNumber()
    {
        return this->secondNumber;
    }

    void setFirstNumber(int newFirstnumber)
    {
        firstNumber = newFirstnumber;
    }

    void setsecondNumber(int newsecondNumber)
    {
        secondNumber = newsecondNumber;
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
        cout << "Size of the list: " << count << endl;
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

    bool existsInList(Node *node)
    {
        Node *current = head;
        while(current != nullptr)
        {
            if(current->getfirstNumber() == node->getfirstNumber() && current->getSecondNumber() == node->getSecondNumber())
            {   
                return  true;
            }

            current = current->next;
        }
        return false;
    }

    void modifyNodeNumbers(int newFirstNumber, int newSecondNumber)
    {   
        Node *newNode = new Node(newFirstNumber, newSecondNumber);
        newNode->next = head; // o próximo nó será o antigo head
        head = newNode;
        if(newNode != nullptr)
        {
            newNode->setFirstNumber(newFirstNumber);
            newNode->setsecondNumber(newSecondNumber);
        }
    }

    void printNodeNumbers(Node *newNode)
    {
        cout << "First Number: " << newNode->getfirstNumber() << ", Second Number: " << newNode->getSecondNumber() << endl;
    }

    void getNextNumber(Node *node)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->getfirstNumber() == node->getfirstNumber() && current->getSecondNumber() == node->getSecondNumber())
        {
            if (current->next != nullptr)
            {
                cout << "Next: N1: " << current->next->getfirstNumber() << ", N2: " << current->next->getSecondNumber() << endl;
                return; // ENCERRA A VERIFICAÇÃO
            }
            
            else
            {
                cout << "Next node does not exist." << endl;
                return;
            }
        }
        current = current->next;
    }
    cout << "Node not found in the list." << endl;
}

    void clearMemory()
    {
        Node *current = head;
        while(current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

    }
};

int main()
{
    List lista;

    lista.addToEnd(11, 21);
    lista.addToEnd(11, 22);
    lista.addToEnd(1, 23);

    lista.printList();

    Node *newNode = new Node(11, 22);
    // lista.modifyNodeNumbers(2, 1);
    lista.printList();
    cout << endl;
    lista.getNextNumber(newNode);

    lista.clearMemory();
    
    return 0;
}
