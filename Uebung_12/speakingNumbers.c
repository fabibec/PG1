#include <stdio.h>

void getNumber(int *number);
int reverseNumber(int number);
void spellNumber(int number);

int main (void)
{
    int num;
    getNumber(&num);
    spellNumber(num);
    return 0;
}

void getNumber(int *number){
    printf("Please enter your number:");
    scanf("%d", number);
}

/**
 * Spells the input number into the terminal
 *
 * @param number number that need's to be spelled
 */
void spellNumber(int number) {
    // Number gets reversed so the front digits can be extracted easier
    number = reverseNumber(number);
    int digit;
    printf("The number is called: ");
    while (number > 0)
    {
        digit = number % 10;
        number /= 10;
        switch (digit) {
            case 0:
                printf("zero");
                break;
            case 1:
                printf("one");
                break;
            case 2:
                printf("two");
                break;
            case 3:
                printf("three");
                break;
            case 4:
                printf("four");
                break;
            case 5:
                printf("five");
                break;
            case 6:
                printf("six");
                break;
            case 7:
                printf("seven");
                break;
            case 8:
                printf("eight");
                break;
            default:
                printf("nine");
        }
        printf(" ");
    }
    printf("\n");
}

int reverseNumber(int number)
{
    int reversed_number = 0;
    while (number > 0)
    {
        reversed_number = (reversed_number * 10) + (number % 10);
        number /= 10;
    }
    return reversed_number;
}