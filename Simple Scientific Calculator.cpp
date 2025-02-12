#include <stdio.h>
#include <math.h>

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double squareRoot(double num);
double power(double base, double exponent);
int factorial(int num);
double logarithm(double num);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double celsius_to_fahrenheit(double celsius);
double meters_to_kilometers(double meters);

// Function to display calculation history
void display_history(char history[][100], int count);

int main() {
    double num1, num2, result;
    int choice, history_count = 0;
    char history[100][100];

    while (1) {
        // Display menu
        printf("\n--- Simple Scientific Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square Root\n");
        printf("6. Exponentiation\n");
        printf("7. Factorial\n");
        printf("8. Logarithm\n");
        printf("9. Sine\n");
        printf("10. Cosine\n");
        printf("11. Tangent\n");
        printf("12. Celsius to Fahrenheit\n");
        printf("13. Meters to Kilometers\n");
        printf("14. View Calculation History\n");
        printf("15. Exit\n");
        printf("Enter your choice (1-15): ");
        scanf("%d", &choice);

        if (choice == 15) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 6) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        } else if (choice >= 7 && choice <= 13) {
            printf("Enter a number: ");
            scanf("%lf", &num1);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                sprintf(history[history_count++], "%.2lf + %.2lf = %.2lf", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                sprintf(history[history_count++], "%.2lf - %.2lf = %.2lf", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                sprintf(history[history_count++], "%.2lf * %.2lf = %.2lf", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                sprintf(history[history_count++], "%.2lf / %.2lf = %.2lf", num1, num2, result);
                break;
            case 5:
                result = squareRoot(num1);
                sprintf(history[history_count++], "√%.2lf = %.2lf", num1, result);
                break;
            case 6:
                result = power(num1, num2);
                sprintf(history[history_count++], "%.2lf ^ %.2lf = %.2lf", num1, num2, result);
                break;
            case 7:
                result = factorial((int)num1);
                sprintf(history[history_count++], "%d! = %.2lf", (int)num1, result);
                break;
            case 8:
                result = logarithm(num1);
                sprintf(history[history_count++], "log(%.2lf) = %.2lf", num1, result);
                break;
            case 9:
                result = sine(num1);
                sprintf(history[history_count++], "sin(%.2lf°) = %.2lf", num1, result);
                break;
            case 10:
                result = cosine(num1);
                sprintf(history[history_count++], "cos(%.2lf°) = %.2lf", num1, result);
                break;
            case 11:
                result = tangent(num1);
                sprintf(history[history_count++], "tan(%.2lf°) = %.2lf", num1, result);
                break;
            case 12:
                result = celsius_to_fahrenheit(num1);
                sprintf(history[history_count++], "%.2lf°C = %.2lf°F", num1, result);
                break;
            case 13:
                result = meters_to_kilometers(num1);
                sprintf(history[history_count++], "%.2lf meters = %.2lf kilometers", num1, result);
                break;
            case 14:
                display_history(history, history_count);
                continue;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Display result
        printf("Result: %.2lf\n", result);
    }

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

double squareRoot(double num) {
    if (num >= 0)
        return sqrt(num);
    else {
        printf("Error: Negative number\n");
        return 0;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

int factorial(int num) {
    if (num < 0)
        return -1;
    int result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}

double logarithm(double num) {
    if (num > 0)
        return log10(num);
    else {
        printf("Error: Undefined for non-positive numbers\n");
        return 0;
    }
}

double sine(double angle) {
    return sin(angle * M_PI / 180);
}

double cosine(double angle) {
    return cos(angle * M_PI / 180);
}

double tangent(double angle) {
    return tan(angle * M_PI / 180);
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double meters_to_kilometers(double meters) {
    return meters / 1000;
}

void display_history(char history[][100], int count) {
    if (count == 0) {
        printf("No history available.\n");
    } else {
        printf("\nCalculation History:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, history[i]);
        }
    }
}
