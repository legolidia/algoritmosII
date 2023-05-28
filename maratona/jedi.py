A, B, C = input().split()

lados = [float(A), float(B), float(C)]

lados.sort(reverse=True)

a = lados[0]
b = lados[1]
c = lados[2]

if a>=(b+c):
    print("NAO FORMA TRIANGULO")
else:
    if a**2 == (b**2 + c**2):
        print("TRIANGULO RETANGULO")
    if a**2 > (b**2 + c**2):
        print("TRIANGULO OBTUSANGULO")
    if a**2 < (b**2 + c**2):
        print("TRIANGULO ACUTANGULO")
    if a==b and b==c:
        print("TRIANGULO EQUILATERO")
    if (a==b and c!=a) or (b==c and a!=b) or (a==c and b!=a):
        print("TRIANGULO ISOSCELES")