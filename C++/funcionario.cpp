#include <iostream>
#include "funcionario.h"
using namespace std;

Funcionario::Funcionario(string nome, float salario, string dataAdmissao)
{
    this->nome = nome;          
    this->salario = salario;    
    this->dataAdmissao = dataAdmissao;
}

// Getters
string Funcionario::getNome()
{
    return nome;
}

float Funcionario::getSalario()
{
    return salario;
}

string Funcionario::getDataAdmissao()
{
    return dataAdmissao; 
}

// Setters
void Funcionario::setNome(string novoNome)
{
    nome = novoNome;
}

void Funcionario::setSalario(float novoSalario)
{
    salario = novoSalario;
}

void Funcionario::setDataAdmissao(string novaDataAdmissao)
{
    dataAdmissao = novaDataAdmissao; 
}


void Funcionario::infoFuncionario()
{
    cout << "\nNome: " << getNome() << "\nSalario: " << getSalario() << "\nData de Admissao: " << getDataAdmissao() << endl;
    cout << "--------------------------------------------------"<<endl;
}
