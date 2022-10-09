# importando função get_int da biblioteca cs50
from cs50 import get_int

# Loop de verificação da altura
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

# Usando for para estruturação da pirâmide
for i in range(0, n, 1):
    for j in range(0, n, 1):
        if (i + j < n - 1):
            print(" ", end="")
        else:
            print("#", end="")
    print()