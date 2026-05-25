#include <stdio.h>

// Function to implement Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(a % b, b, &x1, &y1);

    *x = y1 - (a / b) * x1;
    *y = x1;

    return gcd;
}

// Function to find modular inverse
int modularInverse(int a, int n)
{
    int x, y;

    int gcd = extendedGCD(a, n, &x, &y);

    if (gcd != 1)
    {
        return -1; // Inverse does not exist
    }
    else
    {
        return (x % n + n) % n;
    }
}

int main()
{
    int a, n;

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of n: ");
    scanf("%d", &n);

    int inverse = modularInverse(a, n);

    if (inverse == -1)
    {
        printf("Modular inverse does not exist.\n");
    }
    else
    {
        printf("Modular inverse of %d modulo %d is: %d\n", a, n, inverse);
    }

    return 0;
}