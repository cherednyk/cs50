#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define VISA 4
#define MC_FIRST 51 
#define MC_LAST 55
#define AMEX_ONE 34
#define AMEX_TWO 37

int countCardLen(long long userInput);
bool lenInvalid();
bool sumInvalid(int card[]);
void cardType(int card[]);

void longToArray(long long userInput, int card[]);

int cardLen = 0;

int main(void)
{
    // AmEx 15-digit; Visa 13- and 16-digit; MasterCard 16-digit.

    printf("Number: ");
    
    long long userInput = GetLongLong();
    
    cardLen = countCardLen (userInput);
    
    if (lenInvalid())
    {
        return 0;
    }
    
    int card[cardLen];
    
    longToArray(userInput, card);
    
    if (sumInvalid(card))
    {
        return 0;
    }
    
    cardType(card);
}


// counts quantity of card's digits
int countCardLen(long long userInput)
{
    while(userInput)
    {
        userInput /= 10;
        cardLen++;
    }
    return cardLen;
}

// validates the card's length
bool lenInvalid()
{
    if (cardLen != 13 && cardLen != 15 && cardLen != 16)
    {
        printf("INVALID\n");
        return true;
    } 
    return false;
}

// Converts long long to array
void longToArray(long long userInput, int card[])
{
    for (int i=cardLen - 1; i >= 0; i--)
    {
        card[i] = userInput % 10;
        userInput /= 10;
    }
}

// prints the card's type (visa/amex/MC)
void cardType(int card[])
{
    int firstDigit = card[0];
    int firstTwoDigits = firstDigit * 10 + card[1];
    
    if (firstDigit == VISA)
    {
        printf("VISA\n");
    } 
    else if ((firstTwoDigits >= MC_FIRST) && (firstTwoDigits <= MC_LAST))
    {
        printf("MASTERCARD\n");
    }
    else if ((firstTwoDigits == AMEX_ONE) || (firstTwoDigits == AMEX_TWO))
    {
        printf("AMEX\n");
    }
}

// Validates the card's checksum
bool sumInvalid(int card[])
{
    int sum = 0;
    int tmp;
    int oddCounter = 1;
    
    for (int i=cardLen - 1; i >= 0; i--)
    {
        if (oddCounter % 2 == 0)
        {
            if (card[i] > 4)
            {
                tmp = 0;
                tmp += card[i] * 2 - 9;
                sum += tmp;
            }
            else
            {
                sum += card[i] * 2;
            }
        }
        else
        {
            sum += card[i];
        }
        
        oddCounter++;
    }
    
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return true;
    }
    else
    {
        return false;
    }
}