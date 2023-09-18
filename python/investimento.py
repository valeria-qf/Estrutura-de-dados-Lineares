investimento_inicial_reais = float(input('\Digite o valor de investimento inicial: '))
deposito_mensal_reais = float(input('Digite o valor do depósito mensal: '))
taxa_juros_anual = float(input('Digite a taxa de juros anual: '))
tempo_investimento_anos = int(input('Digite o tempo de investimento em anos: '))

taxa_juros_mensal = ((taxa_juros_anual / 12) / 100)
montante_total_reais = investimento_inicial_reais
tempo_investimento_meses = tempo_investimento_anos * 12
juros_totais = 0

for mes in range(tempo_investimento_meses):
    juros_mensais = montante_total_reais  * taxa_juros_mensal
    montante_total_reais += deposito_mensal_reais
    montante_total_reais += juros_mensais
    juros_totais += juros_mensais

taxa_anual_efetiva = ((1 + taxa_juros_mensal) ** 12 - 1) * 100

print('\nMontante Total: R${:.2f}'.format(montante_total_reais))
print('Juros Totais: R${:.2f}'.format(juros_totais))
print('Taxa Anual Efetiva: {:.2f}%'.format(taxa_anual_efetiva))
