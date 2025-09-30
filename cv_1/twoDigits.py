import sys

# 1. Exponent should be in a binary form
# 2. Horners scheme should be used
# 3. Watch out for 01


# Digits are encoded between 48 and 57
LOW_MARGIN_ASCII_DIG = 48
TOP_MARGIN_ASCII_DIG = 57

def toASCII(char:str) -> int:
    return ord(char)

def toBase(decNum:int, base:int) -> list[int]:
    currNum = decNum
    baseList = []

    while (currNum > 0):
        remainder = currNum % base
        currNum //= base
        baseList.insert(0,remainder)

    return baseList

def isValidDigitASCII(charASCII:str) -> bool:
    return charASCII >= LOW_MARGIN_ASCII_DIG and charASCII <= TOP_MARGIN_ASCII_DIG

def getNextChar() -> str:
    nextChar = sys.stdin.read(1)
    return nextChar

def getNextNumber() -> int:
    nextNumber = 0 # Assume for horners scheme

    nextCharASCII = toASCII(getNextChar())

    # Remove garbage
    while (not isValidDigitASCII(nextCharASCII)):
        nextCharASCII = toASCII(getNextChar())

    # Is a valid digit [0-9]
    while (isValidDigitASCII(nextCharASCII)):
        currDigit = nextCharASCII - LOW_MARGIN_ASCII_DIG
        nextNumber = nextNumber * 10 + currDigit
        nextCharASCII = toASCII(getNextChar())
    
    return nextNumber

def getLastNDigits(number:int, n:int) -> int:
    numberStr = str(number)
    lastTwoStr = numberStr[-n:]
    return int(lastTwoStr)

def runDigitProgram():

    baseNumber = getNextNumber()
    power = getNextNumber()

    def getLastTwoPowerDigits(baseNumber, power):
        baseLastTwo = cLastTwo = getLastNDigits(baseNumber, 2) # Only last two digits matter
        powerInBiBase = toBase(power, 2) # Exponent will be in binary for concatenation via Horner's scheme

        for i in range(1, len(powerInBiBase)):
            cDigit = powerInBiBase[i]

            if (cDigit == 0):
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo, 2)
            elif (cDigit == 1):
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo * baseLastTwo, 2)

        return cLastTwo

    lastTwoPowerDigits = getLastTwoPowerDigits(baseNumber, power)
    print(lastTwoPowerDigits)

runDigitProgram()

