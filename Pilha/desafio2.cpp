// Escreva um programa que leia um inteiro n e uma sequência de n números inteiros e positivos e imprima primeiro os números impares na ordem inversa da leitura e, depois, os números pares também na ordem inversa da leitura. Use duas pilhas : uma para armazenar os números impares e outra para armazenar os números pares.

#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
    public:
    int number;
    Node *next;
    Node(int number)
    {
        this->next = nullptr;
        this->number = number;
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
        while(!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(int number)
    {
        Node *newNode = new Node(number);
        
        if (isEmpty())
        {
            head = newNode;
        }

        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Pilha vazia" << endl;
        }

        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->number << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse()
    {   
        Node *current = head;
        if (!isEmpty())
        {
        cout << "Invertido" << endl;
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
        
        revert(current->next);
        cout << current->number << " ";
    }
};

int main()
{
    Stack oddNumbers;
    Stack evenNumbers;

    cout << "Insira o tamanho da sua lista de numeros: " << endl;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {     
        int number = 0;
        cout << "Digite um numero: " << endl;
        cin >> number;
        if (number > 0)
        {
            (number % 2 == 0) ? evenNumbers.push(number) : oddNumbers.push(number);
        }

        else
        {
            cout << "Insira apenas valores positivos!";
            return -1;
        }
    }
    
    system("cls");
    cout << "Pares: " << endl;
    evenNumbers.print();
    evenNumbers.printReverse();
    cout << "Impares: " << endl;
    oddNumbers.print();
    oddNumbers.printReverse();
    
    return 0;
}