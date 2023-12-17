from collections import defaultdict

class Funcionario:

    def __init__(self, nome, matricula, id):
        self.__nome = nome
        self.__matricula = matricula
        self.__id = id
    
    # getters
    def set_nome(self, nome):
        self.__nome = nome
    
    def set_matricula(self, matricula):
        self.__matricula = matricula

    def set_id(self, id):
        self.__id = id
    
    # setters
    def get_matricula(self):
        return self.__matricula

    def get_nome(self):
        return self.__nome
    
    def get_id(self):
        return self.__id

    def __str__(self):
        return f'Nome:{self.__nome} - Matricula:{self.__matricula}\n'
    
    def __repr__(self):
        return f'Nome:{self.__nome} - Matricula:{self.__matricula}\n'

funcionario = Funcionario(nome = 'Pato maloka', matricula = 109405, id = 1)
funcionario2 = Funcionario(nome = 'Joao', matricula = 109705, id = 2)

tabela_hash = defaultdict(list)

tabela_hash[funcionario.get_id()].append(funcionario)
tabela_hash[funcionario2.get_id()].append(funcionario2)

print(dict(tabela_hash))

