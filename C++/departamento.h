#include <iostream>
#include <vector>
#include "funcionario.h"
using namespace std;

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

class Departamento
{
    private:
    string nomeDepartamento;
    vector<Funcionario> funcionariosDoDepartamento;

    public:
    string getNomeDepartamento();
    vector<Funcionario> getFuncionariosDepartamento();
    Departamento(string nomeDepartamento);
    void adicionarFuncionarioAoDepartamento(Funcionario funcionario);
    void listarDepartamento();
};

#endif