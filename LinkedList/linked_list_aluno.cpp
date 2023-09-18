#include <iostream>
using namespace std;

struct aluno
{
    int matricula;
    string nome;
    float nota;
    aluno *proximo;
};

int main()
{
    aluno *ini, *temp, *aux;
    temp = new aluno;
    ini = temp;
    temp->matricula = 100;
    temp->nome = "Joao";
    temp->nota = 88;
    temp->proximo = NULL;
    aux = temp; // ponteiro auxiliar

    temp = new aluno;
    aux->proximo = temp; // endereço do anterior(aux) recebe o do proximo(temp)
    temp->matricula = 99;
    temp->nome = "Maria";
    temp->nota = 90;
    temp->proximo = NULL;
    aux = temp;

    temp = new aluno;
    aux->proximo = temp; // endereço do anterior(aux) recebe o do proximo(temp)
    temp->matricula = 79;
    temp->nome = "Chico";
    temp->nota = 40;
    temp->proximo = NULL;
    aux = temp;

    aux = ini;

    while(aux != NULL)
    {
        cout << "Nome: " << aux->nome << ", Matricula: " << aux->matricula << ", Nota: " << aux->nota << endl;
        aux = aux->proximo; // Pula para o proximo

    }

    return 0;
};