#include <cs50.h>
#include <stdio.h>
#include <math.h>

int startDigit(long long card, int power);
int countCardLen(long long card);
int evenSum(long long card);
int oddSumx2(long long card);

int main(void)
{
    // AmEx 34 or 37; MasterCard 51, 52, 53, 54, 55; Visa 4.
    
    // AmEx 15-digit, MasterCard 16-digit, Visa 13- and 16-digit.
    
    // Checksum % 10 = 0.
    
    printf("Number: ");
    
    long long cardNum = GetLongLong();

    int cardLen = 0;
    
    cardLen = countCardLen (cardNum);
    
    int firstDigit = startDigit (cardNum, cardLen - 1);
    int first2Digits = startDigit (cardNum, cardLen - 2);
    
    int checksum = evenSum (cardNum) + oddSumx2 (cardNum);
    
    printf("checksum = %d\n", checksum);
    
    if (!(checksum % 10) && (cardLen == 13 || cardLen == 15 || cardLen == 16))
    {
        if (firstDigit == 4)
        {
            printf("VISA\n");
        } 
            else if ((first2Digits == 51) || (first2Digits == 52) || (first2Digits == 53) || (first2Digits == 54) || (first2Digits == 55))
        {
            printf("MASTERCARD\n");
        }
            else if ((first2Digits == 34) || (first2Digits == 37))
        {
            printf("AMEX\n");
        } else 
            printf("INVALID\n");

    } else 
        printf("INVALID\n");
}

// leaves only first digit(s) of card number
int startDigit(long long card, int power)
{
    int xDigit = card / pow(10, power);
    return xDigit;
}

// counts quantity of card's digits
int countCardLen(long long card)
{
    int cardLen = 0;
    while(card != 0)
    {
        card /= 10;
        cardLen++;
    }
    return cardLen;
}

// counts sum of card's even digits 
int evenSum(long long card)
{
    int evenSum = 0;
    int mod = 0;
    
    while(card > 0)
    {
        mod = card % 10; 
        evenSum += mod;
        card /= 100; 
    }
     
    return evenSum;
}

// counts sum of card's odd*2 digits (in case of 12 or 16 after *2 it counts each digit separately 1+2 or 1+6)
int oddSumx2(long long card)
{
    int oddSum = 0;
    int mod = 0;
    
    card /= 10;
    while (card > 0)
    {
        mod = (card % 10) * 2;
        if (mod / 10 != 0)
        {
            oddSum += (mod % 10) + (mod / 10);
        } 
        
        else 
        {    
            oddSum += mod;
        }
        
        card /= 100;
    }
     
    return oddSum;
}