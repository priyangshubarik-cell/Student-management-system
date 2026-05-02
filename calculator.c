#include <stdio.h>
#include <math.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulus(int a, int b);
float power(float a, float b);

int main() {
    float num1, num2;
    int choice;
    char again;

    do {

        printf("Enter first number: ");
        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        printf("\nChoose operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");
        printf("6. Power (^)\n");

        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        printf("\n-------------------------------------\n");

        switch(choice) {
            case 1:
                printf("Result = %.2f\n", add(num1, num2));
                break;

            case 2:
                printf("Result = %.2f\n", subtract(num1, num2));
                break;

            case 3:
                printf("Result = %.2f\n", multiply(num1, num2));
                break;

            case 4:
                if(num2 != 0)
                    printf("Result = %.2f\n", divide(num1, num2));
                else
                    printf("❌ Error! Division by zero.\n");
                break;

            case 5:
                printf("Result = %d\n", modulus((int)num1, (int)num2));
                break;

            case 6:
                printf("Result = %.2f\n", power(num1, num2));
                break;

            default:
                printf("❌ Invalid choice!\n");
        }

        printf("-------------------------------------\n");
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    printf("\n👋 Thank you for using the calculator!\n");

    return 0;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int modulus(int a, int b) {
    return a % b;
}

float power(float a, float b) {
    return pow(a, b);
}