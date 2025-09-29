import sys

# Digits are encoded between 48 and 57
LOW_MARGIN_ASCII_DIG = 48
TOP_MARGIN_ASCII_DIG = 57

def toASCII(char) -> int:
    return ord(char)

def isValidDigitASCII(charASCII:str) -> bool:
    return charASCII >= LOW_MARGIN_ASCII_DIG and charASCII <= TOP_MARGIN_ASCII_DIG

def getMaximumValueWithOccurrences() -> str:
        
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

    n = getNextNumber()
    maxNumber = getNextNumber()
    occurences = [str(1)]
    
    for i in range(2, n + 1):
        cNumber = getNextNumber()

        if (cNumber == maxNumber): occurences.append(str(i))
        elif (cNumber > maxNumber):
            maxNumber = cNumber
            occurences = [str(i)]

    print(maxNumber)
    print(" ".join(occurences))
    return

getMaximumValueWithOccurrences()