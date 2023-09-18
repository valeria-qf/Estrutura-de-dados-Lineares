#include "departamento.h"
#include <iostream>
using namespace std;

Departamento::Departamento(string nomeDepartamento)
{
    this->nomeDepartamento = nomeDepartamento;
}

void Departamento::adicionarFuncionarioAoDepartamento(Funcionario funcionario)
{
    funcionariosDoDepartamento.push_back(funcionario);
    cout << "tamanho funcionarios depto: "<< funcionariosDoDepartamento.size() << endl;

}

void Departamento::listarDepartamento()
{   
    cout << nomeDepartamento << endl;

    int tamanhoFuncionarios = funcionariosDoDepartamento.size();
    cout << "\nTamanho da lista de funcionarios: " << tamanhoFuncionarios << endl;
    
    // Iterar pelos funcionários e exibi-los
    for (int funcionario = 0; funcionario < tamanhoFuncionarios; funcionario++)
    {
        cout << funcionariosDoDepartamento[funcionario].getNome() << endl;
    }
}

string Departamento::getNomeDepartamento()
{
    return nomeDepartamento;
}

vector<Funcionario> Departamento::getFuncionariosDepartamento()
{
    return funcionariosDoDepartamento;
}
