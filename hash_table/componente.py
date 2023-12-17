from enum import Enum
from collections import defaultdict

class Status(Enum):
    PROCESSANDO = 'Processando'
    ENTREGUE = 'Entregue a transportadora'
    FINALIZADO = 'Finalizado'
    ALFANDEGA = 'Inpeção na alfândega'
    TAXADO = 'Pedido taxado'

class Componente:
    def __init__(self, id, localizacao, status):
        self.__id = id
        self.__localizacao = localizacao

        if not isinstance(status, Status):
            raise ValueError('Status invalido!!\n')
        
        self.__status

    def get_status(self):
        return self.__status
    
    def get_id(self):
        return self.__id
    
    def get_localizacao(self):
        return self.__localizacao
    
    def set_status(self, status):
        self.__status = status

    def set_localizacao(self, localizacao):
        self.__localizacao = localizacao

    def set_id(self, id):
        self.__id = id

    def __str__(self):
        return f'Pedido'

componente = Componente( id = 1, localizacao = 'Jaboatão dos Guararapes - PE', status = Status.PROCESSANDO)
componente2 = Componente( id = 2, localizacao = 'Curitiba', status = Status.TAXADO)

tabela_hash = defaultdict(list)

tabela_hash[componente.get_id()].append(componente)
tabela_hash[componente2.get_id()].append(componente2)

print(dict(tabela_hash))
