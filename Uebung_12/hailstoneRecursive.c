#include <stdio.h>

void getInt(int *num);
int hailstoneRecursive(int num, int counter);

int main (void)
{
    int num;
    getInt(&num);
    hailstoneRecursive(num, 0);
    return 0;
}

/**
 * Gets a number from the user
 * @param num address where to save the number to
 */
void getInt(int *num)
{
    printf("Input a positive number: ");
    scanf("%d", num);
}

/**
 * This function solves the hailstone puzzle through recursion
 * @param num current number that needs to be handled by the function
 * @param counter step currently made by the functions
 */
int hailstoneRecursive(int num, int counter) {
    if (num == 1) {
        printf("%d steps needed to reach 1", counter);
        return num;
    } else if (num % 2 == 0) {
        printf("%d is even, so bisect it: %d\n", num, num / 2);
        counter++;
        return hailstoneRecursive(num / 2, counter);
    } else {
        printf("%d is odd, so multiply it by 3 and add 1: %d\n", num, num * 3 + 1);
        counter++;
        return hailstoneRecursive(num * 3 + 1, counter);
    }
}


