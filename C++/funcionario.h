#include <iostream>
using namespace std;

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
class Funcionario

{
public:
    Funcionario(string nome, float salario, string dataAdmissao);
    void infoFuncionario();
    string getNome();
    float getSalario();
    string getDataAdmissao();
    void setNome(string novoNome);
    void setSalario(float novoSalario);
    void setDataAdmissao(string novaDataAdmissao);

private:
    string nome;
    float salario;
    string dataAdmissao;

};

#endif