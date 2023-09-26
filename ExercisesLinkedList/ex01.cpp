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
        this->next = next;
    }

    int getNumber()
    {
        return number;
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

    void addToEnd(int number)
    {
        Node *newNode = new Node(number);
        newNode->next = nullptr; 

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
    }

    void removeElementFromList()
    {
        Node *previous = nullptr;
        Node *current = head;
        while (current->next != nullptr)
        {   
            previous = current;
            current = current->next;
        }

        previous->next = nullptr;
        delete current;
        
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
    void removeDuplicates(Node *node)
    {
        Node *current = node;
        Node *previous = nullptr;
        int count = 0;
        while (current->next != nullptr)
        {
            if(node->getNumber())
            {
                count++;

                if(count > 1)
                {
                    previous = current;
                    current = current->next;
                    delete current;
                }
            }
        }
        
    }

};