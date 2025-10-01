import sys

# Digits are encoded between 48 and 57
LOW_MARGIN_ASCII_DIG = 48
TOP_MARGIN_ASCII_DIG = 57

def toASCII(char:str) -> int:
    return ord(char)

def isValidDigitASCII(charASCII:str) -> bool:
    return charASCII >= LOW_MARGIN_ASCII_DIG and charASCII <= TOP_MARGIN_ASCII_DIG

def getLastTwoInputRowDigits() -> int:
    penultimateASCII, ultimateASCII = None, None
    currCharASCII = toASCII(getNextChar())

    while (isValidDigitASCII(currCharASCII)):
        penultimateASCII, ultimateASCII = ultimateASCII, currCharASCII
        currCharASCII = toASCII(getNextChar())
    
    ultimate = ultimateASCII- LOW_MARGIN_ASCII_DIG

    if (not penultimateASCII):
        return ultimate
    
    penultimate = penultimateASCII - LOW_MARGIN_ASCII_DIG

    lastTwoDigits = penultimate * 10 + ultimate
    return lastTwoDigits

def getLastNDigits(number:int, n:int = 1) -> int:
    numberStr = str(number)
    return int(numberStr[-n:])

def getNextChar() -> str:
    nextChar = sys.stdin.read(1)
    return nextChar

def getLastTwoDigitsPower():

    baseLastTwo = getLastTwoInputRowDigits() # Only last two digits matter
    cLastTwo = 1

    cPowerCharASCII = toASCII(getNextChar())
    while (isValidDigitASCII(cPowerCharASCII)):
        cDigit = cPowerCharASCII - LOW_MARGIN_ASCII_DIG

        if (cDigit == 0):
            cLastTwo = getLastNDigits(cLastTwo * cLastTwo, 2)
        elif (cDigit == 1):
            cLastTwo = getLastNDigits(cLastTwo * cLastTwo * baseLastTwo, 2)
        
        cPowerCharASCII = toASCII(getNextChar())

    cLastTwoStr = str(cLastTwo) if len(str(cLastTwo)) >= 2 else "0" + str(cLastTwo)

    print(cLastTwoStr)
    return



getLastTwoDigitsPower()


