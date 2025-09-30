import sys

# Digits are encoded between 48 and 57
LOW_MARGIN_ASCII_DIG = 48
TOP_MARGIN_ASCII_DIG = 57

def toASCII(char:str) -> int:
    return ord(char)

def isValidDigitASCII(charASCII:str) -> bool:
    return charASCII >= LOW_MARGIN_ASCII_DIG and charASCII <= TOP_MARGIN_ASCII_DIG

def getLastNDigits(number:int, n:int) -> int:
    numberStr = str(number)
    lastTwoStr = numberStr[-n:]
    return int(lastTwoStr)

def runDigitProgram():

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
    
    def getLastTwoPowerDigits(baseNumber, power):
        baseLastTwo = cLastTwo = getLastNDigits(baseNumber, 2) # Only last two digits matter
        powerArray = [int(x) for x in str(power)]

        for i in range(1, len(powerArray)):
            cDigit = powerArray[i]

            if (cDigit == 0):
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo, 2)
            elif (cDigit == 1):
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo * baseLastTwo, 2)

        cLastTwoStr = str(cLastTwo) if len(str(cLastTwo)) >= 2 else "0" + str(cLastTwo)

        return cLastTwoStr

    baseNumber = getNextNumber()
    power = getNextNumber()

    lastTwoPowerDigits = getLastTwoPowerDigits(baseNumber, power)
    print(lastTwoPowerDigits)

runDigitProgram()

