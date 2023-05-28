#calculadora de banco de horas de folha de ponto

print("Digite a hora de entrada:")
horaEntrada, minEntrada = input().split(':')

horaEntrada = int(horaEntrada)
minEntrada = int(minEntrada)

print("Digite o horario de almoço:")
horaEntradaAlmoco, minEntradaAlmoco = input().split(':')

horaEntradaAlmoco = int(horaEntradaAlmoco)
minEntradaAlmoco = int(minEntradaAlmoco)

print("Digite a hora da saida do horario de almoço:")
horaSaidaAlmoco, minSaidaAlmoco = input().split(':')

horaSaidaAlmoco = int(horaSaidaAlmoco)
minSaidaAlmoco = int(minSaidaAlmoco)

soma = (horaEntradaAlmoco - horaEntrada)*60 + horaSaidaAlmoco - horaEntradaAlmoco + (minEntradaAlmoco - minEntrada) + (minSaidaAlmoco - minEntradaAlmoco)

faltam = 585 - soma

horaSaida = horaSaidaAlmoco + faltam//60
if(minSaidaAlmoco + faltam%60 >= 60):
    minSaida = minSaidaAlmoco + faltam%60 - 60
    horaSaida += 1
else:
    minSaida = minSaidaAlmoco + faltam%60

print("Hora da saída deverá ser:")
print(horaSaida, minSaida, sep=':')


