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
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error: Invalid operator.\n");
            printf("Please enter equation:'%c'\n", operator);
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
        printf("Error: Invalid function\n");
        printf("Please enter equation:'%s'\n", function);
        exit(EXIT_FAILURE);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    double value1, value2, answer;
    char operator, function[5];
    bool scientific = false;
    char option;

    printf("Basic Scientific Calculator!\n");

    do {
        printf("\nSelection Screen:\n");
        printf("1. Arithmetic (+, -, *, /)\n");
        printf("2. Scientific (sqrt, sin, cos, tan)\n");
        printf("3. Quit\n");
        printf("Select an Option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("\nEnter arithmetic expression: ");
                scanf(" %[^\n]", input);
                sscanf(input, "%lf %c %lf", &value1, &operator, &value2);
                answer = solve_arithmetic(value1, value2, operator);
                printf("Answer: %.2f\n", answer);
                break;
            case '2':
                printf("\nEnter scientific function and operand: ");
                scanf(" %[^\n]", input);
                sscanf(input, "%s %lf", function, &value1);
                answer = solve_scientific(function, value1);
                printf("Answer: %.2f\n", answer);
                break;
            case '3':
                printf("\nExiting the calculator!\n");
                break;
            default:
                printf("Invalid Option. Select an Option:\n");
        }

        while ((getchar()) != '\n');

    } while (option != '3');

    return 0;
}
