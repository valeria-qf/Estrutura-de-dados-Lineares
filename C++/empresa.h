#include <iostream>
#include "funcionario.h"
#include "departamento.h"
#include <vector>
using namespace std;

#ifndef EMPRESA_H
#define EMPRESA_H

class Empresa
{
    public:
        Empresa(string nomeEmpresa, string cnpj);
        void infoEmpresa();
        string getNomeEmpresa();
        string getCnpj();
        void setNomeEmpresa(string novoNomeEmpresa);
        void setCnpj(string novoCnpj);
        void criarDepartamento(Departamento departamento);
        void contratarFuncionario(Funcionario funcionario, Departamento departamento);

    private:
        string cnpj;
        string nomeEmpresa;
        vector<Departamento> departamentosEmpresa;
};

#endif