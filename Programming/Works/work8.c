#include <printf.h>
#include <string.h>

void showTitle(const int task_number) {
    printf("--- Task %d ---\n", task_number);
}

/**
 * Compare two strings
 */
void compareStrings(const char *firstString, const char *secondString) {
    int comparingResult = strcmp(firstString, secondString);

    if (comparingResult == 0) {
        printf("[%s] equals [%s]\n", firstString, secondString);
    }
    else if (comparingResult < 0) {
        printf("[%s] precedes [%s]\n", firstString, secondString);
    }
    else if (comparingResult > 0) {
        printf("[%s] follows [%s]\n", firstString, secondString);
    }
}

/**
 * Compare symbols of first and second strings.
 * Prefer to use strncmp(firstString, secondString, amount)
 */
void compareSymbolsStrings(const char *firstString, const char *secondString, unsigned amountSymbols) {
    char firstPart[256];
    char secondPart[256];

    strncpy(firstPart, firstString, amountSymbols);
    strncpy(secondPart, secondString, amountSymbols);

    compareStrings(firstPart, secondPart);
}

/**
 * Split strings into tokens and print them
 */
void splitString(char *string, char *separators) {
    printf("Splitting up the input string [%s]\n", string);

    char *token = strtok(string, separators);
    while (token) {
        puts(token);
        token = strtok(NULL, separators);
    }
}

/**
 * Get position of symbols from set
 */
int getPosition(const char *phrase, const char *symbolsSet) {
    return (int) (strpbrk(phrase, symbolsSet) - phrase);
}

// Variant 17
int main() {
    char phrase[] = "Hello world";
    char *firstPart = "Hello";

    // Task 1 (3)
    showTitle(1);
    compareStrings(phrase, firstPart);

    // Task 2 (4)
    showTitle(2);
    compareSymbolsStrings(phrase, firstPart, 5);

    // Task 3 (7)
    showTitle(3);
    int phraseLength = (int) strlen(phrase);
    printf("Length of phrase is %d symbols\n", phraseLength);

    // Task 4 (10)
    showTitle(4);
    char *targetSymbols = " od";

    printf("Symbol from set has found at [%d] position\n", getPosition(phrase, targetSymbols));

    // Task 5 (13)
    showTitle(5);

    char loremIpsum[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
            " Duis semper odio at lacinia volutpat."
            " Suspendisse potenti."
            " Mauris vehicula velit volutpat malesuada vestibulum.";

    splitString(loremIpsum, " ");

    return 0;
}