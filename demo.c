#include <stdio.h>

int convert_d(int n);
void convert_to_octal(int n);
void convert_to_hexadecimal(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int decimal_value = convert_d(n);
    printf("Decimal representation: %d\n", decimal_value);
    printf("Octal representation: ");
    convert_to_octal(decimal_value);
    printf("\n");
    printf("hexadecimal representation:");
    convert_to_hexadecimal(decimal_value);
    printf("\n");

    return 0;
}

int convert_d(int n) {
    int dec = 0;
    int i = 0, rem;

    while (n != 0) {
        rem = n % 10; // Get the last digit
        dec += rem * (1 << i); // Calculate the binary value
        n /= 10; // Remove the last digit
        ++i; // Move to the next power of 2
    }
    return dec;
}

void convert_to_octal(int n) { // Corrected function signature
    if (n == 0) {
        printf("0");
        return;
    }

    int octal[50]; // Array to store octal digits
    int index = 0;

    while (n > 0) {
        octal[index] = n % 8; // Get the remainder
        n /= 8; // Divide by 8
        index++; // Move to the next index
    }

    // Print the octal number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", octal[i]);
    }
}
void convert_to_hexadecimal(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char hex[50]; // Array to store hexadecimal digits
    int index = 0;

    while (n > 0) {
        int remainder = n % 16; // Get the remainder
        if (remainder < 10) {
            hex[index] = remainder + '0'; // Convert to character
        } else {
            hex[index] = remainder - 10 + 'A'; // Convert to character ('A' = 10, 'B' = 11, ...)
        }
        n /= 16; // Divide by 16
        index++; // Move to the next index
    }

    // Print the hexadecimal number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}