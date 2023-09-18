#include <iostream>
using namespace std;

struct Node {
    int number;        
    Node* next;      
};

void addToEnd(Node *&head, int number)
{
    Node *newNode = new Node;
    newNode->number = number;
    newNode->next = nullptr;

    if (head == nullptr) // se o head estiver vazio
    {
        head = newNode; // o head irá receber o novo nó adicionado
    }

    else // quando o head já estiver preenchido
    {
        Node *current = head; // atual aponta para head

        while (current->next != nullptr) // enquanto o próximo elemento for diferente de nulo, ou seja, se ele não for o ultimo da lista
        {
           current = current->next; // o atual recebe o proximo e percorre a lista
        }
        
        current->next = newNode; //  se o próximo apontar para nulo nulo, agora ele irá apontar para o novo nó adicionado(o último)

    }

};

void printList(Node * &head)
{
    Node *current = head;

    while (current != nullptr)  // enquanto o atual for diferente de nulo
        {   
            cout << current->number << endl; // printa o numero armazenado no atual
            current = current->next; // passa para o próximo
        }
};

int main() 
{
    Node *head = nullptr; // Inicializa o head como vazio
    addToEnd(head, 10);
    addToEnd(head, 50);
    addToEnd(head, 1);
    addToEnd(head, 11);

    // Imprimir lista
    printList(head);

    // Liberando a memória alocada para os nós
    Node *current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;

}
