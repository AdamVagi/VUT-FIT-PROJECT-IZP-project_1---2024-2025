/**
 * @file tnine.c
 * @author Adam Vágner <xvagnea00@fit.vutbr.cz>
 * @brief IZP PROJECT 1 => PRÁCE S TEXTEM
 * @date 24-10-2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 101

// Checking if input arguments are digits
int isAllDigits(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Divide input argument into single digits and put them into array
int extractArgument(char *arg, int arguments_array[])
{
    int len = strlen(arg);
    for (int idx = 0; idx < len; idx++)
    {
        arguments_array[idx] = arg[idx] - '0';
    }
    return len;
}

// Put each digit to the corresponding set of chars
struct ArgData
{
    int number;
    char firstChar;
    char secondChar;
    char thirdChar;
    char fourthChar;
};

// Throught switch delegate every number to belonging group of chars
void divideArgument(int arguments_array[], int arg_len, struct ArgData data_array[])
{
    for (int idx = 0; idx < arg_len; idx++)
    {
        // Get the current digit
        int current_digit = arguments_array[idx];

        // Declare chars for each digit
        switch (current_digit)
        {
        case 1:
            data_array[idx].number = 1;
            break;

        case 2:
            data_array[idx].number = 2;
            data_array[idx].firstChar = 'a';
            data_array[idx].secondChar = 'b';
            data_array[idx].thirdChar = 'c';
            break;

        case 3:
            data_array[idx].number = 3;
            data_array[idx].firstChar = 'd';
            data_array[idx].secondChar = 'e';
            data_array[idx].thirdChar = 'f';
            break;

        case 4:
            data_array[idx].number = 4;
            data_array[idx].firstChar = 'g';
            data_array[idx].secondChar = 'h';
            data_array[idx].thirdChar = 'i';
            break;

        case 5:
            data_array[idx].number = 5;
            data_array[idx].firstChar = 'j';
            data_array[idx].secondChar = 'k';
            data_array[idx].thirdChar = 'l';
            break;

        case 6:
            data_array[idx].number = 6;
            data_array[idx].firstChar = 'm';
            data_array[idx].secondChar = 'n';
            data_array[idx].thirdChar = 'o';
            break;

        case 7:
            data_array[idx].number = 7;
            data_array[idx].firstChar = 'p';
            data_array[idx].secondChar = 'q';
            data_array[idx].thirdChar = 'r';
            data_array[idx].fourthChar = 's';
            break;

        case 8:
            data_array[idx].number = 8;
            data_array[idx].firstChar = 't';
            data_array[idx].secondChar = 'u';
            data_array[idx].thirdChar = 'v';
            break;

        case 9:
            data_array[idx].number = 9;
            data_array[idx].firstChar = 'w';
            data_array[idx].secondChar = 'x';
            data_array[idx].thirdChar = 'y';
            data_array[idx].fourthChar = 'z';
            break;

        case 0:
            data_array[idx].number = 0;
            data_array[idx].firstChar = '+';
            break;
        }
    }
}

// Check if read phone numbers contains given arguments
int sequenceContainsNumber(char *phone_number, int arguments_array[], int arg_len)
{
    // Length of read phone number
    int phone_len = strlen(phone_number);

    // Loop throught the phone number
    for (int idx = 0; idx <= phone_len - arg_len; idx++)
    {
        int is_match = 1;

        // Going throught array of given arguments
        for (int i = 0; i < arg_len; i++)
        {
            if (phone_number[idx + i] != (arguments_array[i] + '0'))
            {
                // Returns no match and next number
                is_match = 0;
                break;
            }
        }

        // All numbers in sequence were matched
        if (is_match)
        {
            return 1;
        }
    }
    return 0;
}

// Converting uppercase letters to its corresponding lowercase
char myToLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + 32;
    }
    return ch;
}

// Check if read names contains given arguments
int sequenceContainsChar(char *name, struct ArgData data_array[], int arg_len)
{
    // Length of read name
    int name_len = strlen(name);

    // Loops throught the name
    for (int idx = 0; idx <= name_len - arg_len; idx++)
    {
        int is_match = 1;

        // Going throught array of given arguments
        for (int i = 0; i < arg_len; i++)
        {
            char name_char = myToLower(name[idx + i]);

            // Check if the current character matches any of the possible chars for the digit
            if (name_char != data_array[i].firstChar && name_char != data_array[i].secondChar &&
                name_char != data_array[i].thirdChar && name_char != data_array[i].fourthChar)
            {
                // Return no match and next char
                is_match = 0;
                break;
            }
        }

        // All chars in sequence were matched
        if (is_match)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // Declare arrays to hold the name and number inputs
    char name[MAX_LINE_LEN], number[MAX_LINE_LEN];

    // Check if there are more than 3 arguments
    if (argc > 3)
    {
        fprintf(stderr, "Not found\n");
        return 1;
    }

    // Check if there are no given sequences of numbers and print the whole txt file
    if (argc < 2)
    {
        // Read names and numbers until EOF
        while (fgets(name, MAX_LINE_LEN, stdin) != NULL)
        {
            fgets(number, MAX_LINE_LEN, stdin);

            // Check for long input for name and number
            if (strlen(name) == MAX_LINE_LEN - 1 && name[strlen(name) - 1] != '\n')
            {
                fprintf(stderr, "Long input\n");
                return 1;
            }

            if (strlen(number) == MAX_LINE_LEN - 1 && number[strlen(number) - 1] != '\n')
            {
                fprintf(stderr, "Long input\n");
                return 1;
            }

            // Remove newline character from name and number
            for (int i = 0; name[i] != '\0'; i++)
            {
                if (name[i] == '\n')
                {
                    name[i] = '\0';
                }
            }
            for (int i = 0; number[i] != '\0'; i++)
            {
                if (number[i] == '\n')
                {
                    number[i] = '\0';
                }
            }

            // Print the name and number
            printf("%s, %s\n", name, number);
        }
        return 1;
    }

    // Check if the given argument contains only digits
    if (!isAllDigits(argv[1]))
    {
        fprintf(stderr, "Not found\n");
        return 1;
    }

    // Put argument into an array of digits
    int arguments_array[MAX_LINE_LEN];
    int arg_len = extractArgument(argv[1], arguments_array);

    // Array of created structures
    struct ArgData data_array[arg_len];

    // Fill the array with corresponding characters for each digit
    divideArgument(arguments_array, arg_len, data_array);

    // Track if find any matching contact
    int found = 0;

    // Again reading, checking and printing from txt file into stdout
    while (fgets(name, MAX_LINE_LEN, stdin) != NULL)
    {
        fgets(number, MAX_LINE_LEN, stdin);

        if (strlen(name) == MAX_LINE_LEN - 1 && name[strlen(name) - 1] != '\n')
        {
            fprintf(stderr, "Error input\n");
            return 1;
        }

        if (strlen(number) == MAX_LINE_LEN - 1 && number[strlen(number) - 1] != '\n')
        {
            fprintf(stderr, "Error input\n");
            return 1;
        }

        for (int idx = 0; name[idx] != '\0'; idx++)
        {
            if (name[idx] == '\n')
            {
                name[idx] = '\0';
            }
        }
        for (int idx = 0; number[idx] != '\0'; idx++)
        {
            if (number[idx] == '\n')
            {
                number[idx] = '\0';
            }
        }

        // Check if the number matches
        if (sequenceContainsNumber(number, arguments_array, arg_len))
        {
            printf("%s, %s\n", name, number);
            found = 1;
            continue;
        }

        // Check if the name matches
        if (sequenceContainsChar(name, data_array, arg_len))
        {
            printf("%s, %s\n", name, number);
            found = 1;
        }
    }

    // No matches were found
    if (!found)
    {
        fprintf(stderr, "Not found\n");
    }
    return 0;
}