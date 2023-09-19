#include <iostream>
using namespace std;

struct Node
{
    string nome;
    int idade;
    Node *next;
};

void addToEnd(Node *&head, string nome, int idade)
{
    Node *newNode = new Node;
    newNode->nome = nome;
    newNode->idade = idade;
    newNode->next = nullptr;

    if(head == nullptr)
    {
        head = newNode;
    }

    else
    {
        Node *current = new Node;
        current = head;

        while (current->next != nullptr) // percorre a lista enquanto o próximo elemento nao for nulo
        {
            current = current->next; // o atual recebe o proximo
        }
        current->next = newNode; // se o próximo apontar para nulo, agora ele irá apontar para o novo nó adicionado
        
    }

}

void printList(Node *head)
{
    Node *current = head;
    while(current != nullptr)
    {
        cout << "Nome: " << current->nome << ", Idade: " << current->idade << endl;
        current = current->next;
    }
};

int main()
{
    Node *head = nullptr;
    addToEnd(head, "joao", 10);
    addToEnd(head, "maria", 14);

    printList(head);

    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = new Node;
        temp = current;
        delete temp;
    }
    
    return 0;
}
