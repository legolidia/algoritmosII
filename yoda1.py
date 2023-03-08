num = int(input())

estrelas = input().split() 
soma = 0

i = 1

for i in range(0, len(estrelas)):
    estrelas[i] = int(estrelas[i])
    soma += estrelas[i]

roubados = 0
i = 0

while(i>=0 and i<num):
    roubados += 1
    if estrelas[i]%2!=0:
        i = i+1
    else:
        i = i-1
    
naoRoubados = soma-roubados

print("%d %d" %(roubados, naoRoubados))
