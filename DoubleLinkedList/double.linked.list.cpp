#include <iostream>
using namespace std;

struct Node {
    int number;       
    Node* next;      
    Node* prev;      
};

void addToEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->number = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    } 
    
    else 
    {
       
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

}

void printFoward(Node *head)
{
    Node *current = head;
    while(current != nullptr)
    {
        cout << current->number << " ";
        current = current->next;
    }
}

void printBackwards(Node *tail)
{
    Node *current = tail;
    while(current != nullptr)
    {
        cout << current->number << " ";
        current = current->prev;
    }
}

int main()
{
    Node *head = nullptr;
    addToEnd(head, 1);
    addToEnd(head, 45);
    addToEnd(head, 40);

    printFoward(head);
    cout << endl;

    // Encontrando o último nó da lista
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    printBackwards(current);
}