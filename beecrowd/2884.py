# Leitura dos valores de N (número de interruptores) e M (número de lâmpadas)
N, M = map(int, input().split())

# Inicializa as lâmpadas acesas inicialmente como um número binário
lights = 0

# Leitura das lâmpadas acesas inicialmente
turned_on = list(map(int, input().split()))

# Atualiza o estado das lâmpadas acesas usando operações de bit
for i in range(1, turned_on[0] + 1):
    lights |= 1 << (turned_on[i] - 1)

# Lista para armazenar as sequências de lâmpadas controladas por cada interruptor
interrupts = []

# Leitura dos interruptores e suas respectivas lâmpadas
for _ in range(N):
    values = list(map(int, input().split()))
    sequence = 0
    for i in range(1, values[0] + 1):
        sequence |= 1 << (values[i] - 1)
    interrupts.append(sequence)

# Variável para indicar se todas as lâmpadas foram apagadas e contador de operações
answer = 0
found = False

# Simulação de acionamento dos interruptores
for _ in range(2 * N):
    position = answer % N
    answer += 1
    lights ^= interrupts[position]
    if lights == 0:
        found = True
        break

# Impressão do resultado
if found:
    print(answer)
else:
    print(-1)
