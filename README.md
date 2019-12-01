# EXECUÇÃO
Basta rodar os comandos:
* *make*
* *./main* 

# REGRAS CHAVE
Para determinar os clientes prioritários usamos um sorteio, com chance de 20% de acerto, esse tipo de cliente tem a senha com dois dígitos e pela letra [P].
Os tipos de clientes são representados pelas letras [C], [N] e [S].
O tempo é contado a cada rodada de atendimento, a quantidade de minutos é sorteada em uma escala de 1 - 5.
No botão do pânico, é sorteado um guichê que será suspenso na próxima rodada, caso esteja vazio na mesma.

# ARQUIVOS
As operações básicas dos TADs utilizados na aplicação foram colocadas no arquivo [model.c](./model.c), enquanto as estruturas ficaram no [model.h]((./model.h)). O responsável por manipular a fila e os clientes é o arquivo [ticket.c](./ticket.c), onde consta todas as regras de negócio do sistema.

O [main.c](./main.c) é apenas para entrada de dados e definições gerais acerca do fluxo de dados do aplicativo.

# MÉTODOS CHAVE
* *void addClientInLine(tLine * line, bool isSpecial);* - Responsável por adicionar os clientes e determinar a senha deles, nesse processo ocorre um sorteio para determinar se o cliente é ou não prioritário.
* *void orderAttendance(tLine * lineCustomers);* - Organiza a fila por prioridade, busca os itens que devem estar na frente e então aloca eles na primeira posição do vetor, tomando cuidado para que a varredura não se torne um looping infinito.
* *void attendance(tLine * lineCustomers, tList * listServiceWindow);* - Remove os clientes da fila e insere no guichê que estiver livre
* *void blockWindow(tList * list, int windowContent);* - Bloqueia o guichê a partir do seu número de identificação. Apenas um guichê pode ser bloqueado por vês.
* *void clearWindows(tList * list);* - Conclui o atendimento dos guichês, deixando eles liberados, ae de um possível bloqueio, para a próxima rodada da fila.
