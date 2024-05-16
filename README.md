# Trabalho proposto pelo professor Lauro Víctor

# Grupo: Phelippe Schnel, Brener, Bruno

Trabalho de Programação II – Prof. Lauro Víctor
Este trabalho consiste em modelar e implementar um sistema gerenciador para
uma sorveteria. Leia atentamente o enunciado do problema, identifique os
elementos do sistema e cumpra as etapas abaixo. O projeto será testado contra
plágio vindo de Inteligência Artificial (ChatGPT entre outros). Caso o código seja
produzido desta maneira, o trabalho do grupo será desconsiderado.

Enunciado do Problema
Uma sorveteria precisa controlar suas compras, entender seus clientes e
realizar algumas consultas. Para isso, você foi contratado para desenvolver a
primeira versão de um software gerenciador dessa loja.

Etapas
Leia todas as etapas antes de começar a implementar o trabalho. Lembre-se
que a participação de todos influencia diretamente na nota final do trabalho.

1. Criar o menu principal
Você deve fazer um menu pedindo para o usuário escolher entre as seguintes
opções:
• Cadastrar novas vendas
• Ver informações de uma venda específica, baseado no nome do cliente
• Ver informações de todas as vendas
• Encerrar o programa

2. Fazer o cadastro de uma quantidade de vendas definida pelo usuário
Pergunte ao usuário qual a quantidade de vendas que ele deseja cadastrar. Crie
um vetor com alocação dinâmica de memória e cadastre cada venda realizada.
Cada venda é uma estrutura representada pelo cliente (estrutura), número de
itens, número de sabores e valor total da compra.
A cada venda pergunte dados do cliente que é uma estrutura com os campos
nome, sexo e idade. Observe as validações abaixo:
• Impedir o cadastro de valores negativos e informar este erro.
• Impedir o cadastro quando o sexo do cliente for inválido (diferente de m, f
ou n) e informar este erro.
• Impedir o cadastro se o nome do cliente possuir menos de 3 letras e
informar este erro.

• Informar ao final de cada cadastro de compra que a mesma foi
cadastrada com sucesso caso não aconteça nenhum erro.

Após o término de todo o cadastro salve as informações em um bloco de notas
nomeado de “registros.txt”. Pergunte ao usuário se ele deseja cadastrar mais
itens (quantidade informada novamente) ou voltar ao menu principal.

3. Pesquisar uma venda específica
• Você deve pedir o nome do cliente a ser pesquisado.
• Informar todas as vendas feitas para este cliente, ou seja, o valor total de
cada compra, o número de sabores e a quantidade de itens em cada
compra.
• Exiba também a média de valor das compras feitas por este cliente.
• Caso não encontre o cliente deve-se informar que não há compras naquele
nome.
Após exibir a informação das compras ou a informação que não encontrou,
perguntar se o usuário deseja pesquisar novamente ou retornar ao menu
principal.

4. Ver informações de todas as vendas
Você deve:
• Pedir um valor que será usado para exibir a quantidade de vendas abaixo
deste valor.
• Exibir a quantidade de vendas que teve somente 1 item vendido.
• Exibir a quantidade de vendas que teve um número par de sabores.
• Exibir a quantidade de compradores mulheres.
• Exibir o valor total comprado por homens.
• Exibir a quantidade total de itens vendidos.
• Exibir o número total de sabores vendidos.
• Exibir o valor total das compras.
• Exibir o valor médio de uma compra.
• Exibir os dados da venda do cliente com o maior nome (se ele fez mais de
uma compra, exibir os dados de cada venda).
• Exibir os dados da venda do cliente mais novo (se ele fez mais de uma
compra, exibir os dados de cada venda).

Após exibir as informações, deve-se perguntar se o usuário deseja retornar
ao menu principal. Se sim retorne ao menu principal, senão encerre o
programa.

5. Ao abrir o programa, carregue todas as compras do bloco de notas, caso
exista
Todo o registro de compras deve ser salvo no bloco de notas “registros.txt”. Ao
cadastrar novas vendas, todas elas devem ser adicionadas às vendas já
existentes no bloco de notas. A gerência das informações salvas no bloco de
notas assim como a melhor forma de navegar no bloco de notas para obter as
informações é de livre decisão do desenvolvedor.