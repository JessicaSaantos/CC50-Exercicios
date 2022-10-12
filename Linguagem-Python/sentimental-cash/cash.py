# TODO

from cs50 import get_float
# verificando entrada do usuário
while True:
    cents = get_float("Change: ")
    if cents > 0:
        break
# arredondando valor
cents = round(cents * 100)

count = 0

# verificando valor das moedas p/ contabilizar a quantidade
while cents >= 25:
    cents = cents - 25
    count += 1

while cents >= 10:
    cents = cents - 10
    count += 1

while cents >= 5:
    cents = cents - 5
    count += 1

while cents >= 1:
    cents = cents - 1
    count += 1

print("Total coins: ", count)