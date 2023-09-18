#include <iostream>
#include "departamento.h"
#include "empresa.h"
using namespace std;

Empresa::Empresa(string nomeEmpresa, string cnpj)
{
    this-> nomeEmpresa = nomeEmpresa;
    this-> cnpj = cnpj;
}

string Empresa::getNomeEmpresa()
{
    return nomeEmpresa;
}

string Empresa::getCnpj()
{
    return cnpj;
}

void Empresa::setNomeEmpresa(string novoNomeEmpresa)
{
    nomeEmpresa = novoNomeEmpresa;
}

void Empresa::setCnpj(string novoCnpj)
{
    cnpj = novoCnpj;
}

void Empresa::contratarFuncionario(Funcionario funcionario, Departamento departamento)
{
    departamento.adicionarFuncionarioAoDepartamento(funcionario);
}

void Empresa::criarDepartamento(Departamento departamento)
{
    departamentosEmpresa.push_back(departamento);
}

void Empresa::infoEmpresa()
{   
    cout << "\nNome da Empresa: " << nomeEmpresa << "\nCNPJ: " << cnpj << endl;
    cout << "\nDepartamentos: " << endl;

    int tamanhoDepartamento = departamentosEmpresa.size();
    for (int departamento = 0; departamento < tamanhoDepartamento; departamento ++)
    {
       departamentosEmpresa[departamento].listarDepartamento();
    }

}

