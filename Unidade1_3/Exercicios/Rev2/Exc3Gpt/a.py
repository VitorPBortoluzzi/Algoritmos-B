import random

# Configurações
num_funcionarios = 1000
salario_min = 5000
salario_max = 30000
total_vendas_min = 1000
total_vendas_max = 10000

# Abre o arquivo para escrita
with open('funcionarios.txt', 'w') as file:
    for i in range(1, num_funcionarios + 1):
        codigo = i
        salario_atual = round(random.uniform(salario_min, salario_max), 2)
        total_vendas = round(random.uniform(total_vendas_min, total_vendas_max), 2)
        
        # Formata a linha para o arquivo
        linha = f"CodFuncionario:{codigo}; SalarioAtual:{salario_atual}; TotaldeVendas:{total_vendas}\n"
        file.write(linha)
