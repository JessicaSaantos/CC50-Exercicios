# TODO

from cs50 import get_int

# verificação da entrada do usuário
while True:
    card = get_int("Card: ")
    if card > 0:
        break

# Calculando de acordo com Luhn’s Algorithm


def luhn_checksum(card):
    def digits_of(n):
        return [int(d) for d in str(n)]
    digits = digits_of(card)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    checksum += sum(odd_digits)
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    return checksum % 10
    

length = 0
visa = card
master = card
amex = card

# Diferenciar entre VISA, Master e AMEX
length = len(str(card))

# Identificando cartão VISA
while visa >= 10:
    visa = int(visa/10)

# Identificando cartão AMEX
while amex >= 10**13:
    amex = int(amex/10**13)

# Identificando cartão Master
while master >= 10**14:
    master = int(master/10**14)

# Imprimindo resultado
if luhn_checksum(card) == 0:
    if visa == 4 and (length == 13 or length == 16):
        print("VISA")
    elif length == 15 and (amex == 34 or amex == 37):
        print("AMEX")
    elif length == 16 and (51 <= master <= 55):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
