#include <iostream>
using namespace std;

class Node
{
    public:
    char parenthesis;
    Node *next;
    Node(char parenthesis)
    {
        this->next = nullptr;
        this->parenthesis = parenthesis;
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

    void push(char parenthesis)
    {
        Node *newNode = new Node(parenthesis);
        
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

    void verifyParenthesis(string expression)
    {
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '(')
            {
                push(expression[i]);
            }

            else if (expression[i] == ')')
            {   
                if (isEmpty())
                {
                    cout << "Nao ha correspondente para fechar" << endl;
                    return; // finaliza for
                }

                else
                {
                    pop();
                   
                }
                
            }
            
            else
            {
                cout << "Caractere inválido!" << expression[i] << endl;            
            }    
        }

        if (isEmpty())
        {
            cout << "Expressao valida" << endl;
        }

        else
        {
            cout << "Expressao invalida!" << endl;
        }
          
    }
};

int main()
{
    Stack stack;
    cout << "Insira uma expressao de parentesis" << endl;

    string expression;
    cin >> expression;
    stack.verifyParenthesis(expression);

    return 0;
}