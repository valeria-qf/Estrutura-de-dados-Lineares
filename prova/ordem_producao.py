from collections import defaultdict
from enum import Enum
from datetime import date

class StatusOrdem(Enum):
    ATRASADO = 'Atrasado'
    EM_DIA = 'Em dia'
    ADIANTADO = 'Adiantado'

    def __str__(self):
        if StatusOrdem.ATRASADO:
            return 'Atrasado'
        elif StatusOrdem.EM_DIA:
            return 'Em dia'
        elif StatusOrdem.ADIANTADO:
            return 'Adiantado'

class OrdemProducao:
    def __init__(self, num_ordem:int, status_ordem:StatusOrdem, detalhes_produto:str, prazo_validade:str , data_fabricacao:str):
        self.__detalhes_produto = detalhes_produto
        self.__prazo_validade = prazo_validade
        self.__data_fabricacao = data_fabricacao
        self.__num_ordem = num_ordem

        if not isinstance(status_ordem, StatusOrdem):
            raise ValueError('Status invalido!\n')
        
        self.__status_ordem = status_ordem

    # getters
    def get_num_ordem(self):
        return self.__num_ordem
    
    def get_detalhes_produto(self):
        return self.__detalhes_produto
    
    def get_status_ordem(self):
        return self.__status_ordem
    
    def get_prazo_validade(self):
        return self.__prazo_validade
    
    def get_data_fabricacao(self):
        return self.__data_fabricacao
    

    # setters
    def set_num_ordem(self, num_ordem):
        self.__num_ordem = num_ordem
    
    def set_status_ordem(self, status_ordem:StatusOrdem):
        self.__status_ordem = status_ordem
    
    def set_detalhes_produto(self, detalhes_produto):
        self.__detalhes_produto = detalhes_produto

    def set_data_fabricacao(self, data_fabricacao):
        self.__data_fabricacao = data_fabricacao
    
    def set_prazo_validade(self, prazo_validade):
        self.__prazo_validade = prazo_validade


    def __str__(self):
        return f'Numero da ordem: {self.__num_ordem} \nStatus: {self.__status_ordem} \nDetalhes: {self.__detalhes_produto} \nFabricacao: {self.__data_fabricacao} \nValidade: {self.__prazo_validade}\n'
    
    def __repr__(self):
        return f'Numero da ordem: {self.__num_ordem} \nStatus: {self.__status_ordem} \nDetalhes: {self.__detalhes_produto} \nFabricacao: {self.__data_fabricacao} \nValidade: {self.__prazo_validade}\n'
    
class GerenciarOrdens:
    def __init__(self):
        self.ordens_hash = defaultdict(list)
    
    def adicionar_nova_ordem(self, ordem: OrdemProducao):
        self.ordens_hash[ordem.get_num_ordem()].append(ordem)
    
    def remover_ordem(self, ordem: OrdemProducao):
        self.ordens_hash.pop(ordem.get_num_ordem())

    def verificar_ordem(self, ordem: OrdemProducao):
        if self.ordens_hash[ordem.get_num_ordem()]:
            print(self.ordens_hash[ordem.get_num_ordem()])
            return
        print('Ordem não encontrada')
    
    def atualizar_ordem(self, ordem: OrdemProducao):

        while True:
            acao = int(input('\n0 - Sair \n1 - Atualizar Status \n2 - Atualizar Detalhes \n3 - Atualizar data de fabricação \n4 - Atualizar prazo de validade\n'))

            if acao == 1:

                opcao_status = int(input('\nSelecione o novo status\n 1 - Atrasado \n2 - Em dia  \n 3 - Adiantado\n>'))
                if opcao_status == 1:
                    ordem.set_status_ordem(StatusOrdem.ATRASADO)
                elif opcao_status == 2:
                    ordem.set_status_ordem(StatusOrdem.EM_DIA)
                elif opcao_status == 3:
                    ordem.set_status_ordem(StatusOrdem.ADIANTADO)
                else:
                    raise ValueError('Opção inválida')
                break
            
            elif acao == 2:
                detalhes = input('> ')
                ordem.set_detalhes_produto(detalhes)
                break
            
            elif acao == 3:
                data_fabricacao = input('> ')
                ordem.set_data_fabricacao(data_fabricacao)
                break
            
            elif acao == 4:
                prazo_validade = input('> ')
                ordem.set_prazo_validade(prazo_validade)
                break
            
            elif acao == 0:
                break

ordem = OrdemProducao(data_fabricacao='27/10/2024', prazo_validade= '30 dias', status_ordem= StatusOrdem.EM_DIA, num_ordem= 9, detalhes_produto= 'Contém gluten')

gerenciar_ordens = GerenciarOrdens()
gerenciar_ordens.adicionar_nova_ordem(ordem)
gerenciar_ordens.verificar_ordem(ordem)
gerenciar_ordens.atualizar_ordem(ordem)
# gerenciar_ordens.remover_ordem(ordem)
gerenciar_ordens.verificar_ordem(ordem)
