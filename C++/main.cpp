#include "funcionario.h"
#include "empresa.h"
#include "departamento.h"
#include <iostream>
using namespace std;

int main()
{
    Empresa empresa("Dunder Mifflin", "11.111.111/0001-90");

    Funcionario funcionario1("VALERIA", 1000, "09/04/2023");
    Funcionario funcionario2("Joao", 2000, "20/01/2023");
    funcionario1.infoFuncionario();
    funcionario1.getDataAdmissao();

    Departamento contabilidade("Contabilidade");
    empresa.criarDepartamento(contabilidade);
    
    empresa.contratarFuncionario(funcionario1, contabilidade);

    empresa.infoEmpresa();
}
