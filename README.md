# SO-project2
Entrega: 5 de janeiro

Temos cliente e servidor, em vez do ems


>> Pipes <<
echoo "hello world" | ./main

named pipe -> mkfifo pipe (comando chamado pipe)
              echo "hello" > pipe (guardado no ficheiro pipe)
              ./main < pipe (lê do pipe)


PRIMEIRO EXERCICIO: (ligar o cliente ao pipe) HÀ UM GUIAO SOBRE PIPE
Server <- Cliente (ligação unidirecional)
Server -> Cliente
(2 pipes)

pipe de gestão (para ler e escrever para não se fechar - rw)
- fazer a ligação com o cliente 2
- quando o ultimo cliente se desligar temos o EOF

Criar cliende = ligar as pipes

Comandos - enviar no formato q é recebido, não converter em carateres


SEGUNDO EXERCICIO: vários clientes
um thread = um cliente

MAX_Sessions = 2
server cria 2 threads
cliente um liga-se fica c/ a 1a thread
cliente 2 liga-se fica c/ a 2a thread
cliente 3 fica à espera até ter uma thread p ele

buffer produtor consumidor: termos um conjunto de clientes (consumidores) superior aos recursos (2 threads - produtores)
logo para isto precisamos de uma camada intermédia (o buffer p c) - variáveis de condição
+ consumidores (clientes) que produtores (threads)

Buffer - camada intermédia entre server/threads e clientes, coordena a situação
Implementar COM variavéis de condição


>> Variáveis de condição <<
maneira de tranmitir sinais entre threads
têm mutex associado

int cout = 1
mutex m_cout = INIT
condvar c_cout = INIT
mete em pausa a thread até condição chegar

while (true) -> versão má
  if count == 0
    break

while (true) -> opção boa
  if cout > 0
    cond_wait(c_cout)
  if cond == 0
    
    
como por a thread a correr outra vez ? 
-> cond_signal acordar uma das threads 
-> cond_broadcast acordam todas as threads


TERCEIRO EXERCÌCIO:
>> Sinais <<
