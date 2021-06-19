#include<stdio.h>
                 //Program reads two-digit number and prints every digit, separated by a space
int main() {
   int a = 0;
   scanf("%d", &a); // %d - Считать десятичное число целого типа
   printf("%d %d\n", a/10, a%10); // a/10 - full, a%10 - partiall
   return 0;
}
