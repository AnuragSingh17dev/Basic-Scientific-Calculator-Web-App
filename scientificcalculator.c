#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

double solve_arithmetic(double value1, double value2, char operator) {
    switch(operator) {
        case '+':
            return value1 + value2;
        case '-':
            return value1 - value2;
        case '*':
            return value1 * value2;
        case '/':
            if (value2 != 0)
                return value1 / value2;
            else {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error: Invalid operator '%c'\n", operator);
            exit(EXIT_FAILURE);
    }
}

double solve_scientific(char function[], double value) {
    if (strcmp(function, "sqrt") == 0)
        return sqrt(value);
    else if (strcmp(function, "sin") == 0)
        return sin(value);
    else if (strcmp(function, "cos") == 0)
        return cos(value);
    else if (strcmp(function, "tan") == 0)
        return tan(value);
    else {
        printf("Error: Invalid function '%s'\n", function);
        exit(EXIT_FAILURE);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    double value1, value2, result;
    char operator, function[5];
    bool scientific = false;
    char choice;

    printf("Welcome to the Basic Scientific Calculator in C!\n");

    do {
        printf("\nSelect operation:\n");
        printf("1. Arithmetic (+, -, *, /)\n");
        printf("2. Scientific (sqrt, sin, cos, tan)\n");
        printf("3. Quit\n");
        printf("Enter choice (1/2/3): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter arithmetic expression (e.g., 5 + 3): ");
                scanf(" %[^\n]", input);
                sscanf(input, "%lf %c %lf", &value1, &operator, &value2);
                result = solve_arithmetic(value1, value2, operator);
                printf("Result: %lf\n", result);
                break;
            case '2':
                printf("\nEnter scientific function and operand (e.g., sqrt 16): ");
                scanf(" %[^\n]", input);
                sscanf(input, "%s %lf", function, &value1);
                result = solve_scientific(function, value1);
                printf("Result: %lf\n", result);
                break;
            case '3':
                printf("Exiting the calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

        // Clear input buffer
        while ((getchar()) != '\n');

    } while (choice != '3');

    return 0;
}
