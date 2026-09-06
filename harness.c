#include <stdio.h>   // for printf, fgets
#include <string.h>  // for strstr, strcspn

int main(void) {
    // Buffer to hold user input. 100 chars should be plenty for simple testing.
    char input[100];

    // Infinite loop: will only stop when we explicitly 'break' out of it.
    while (1) {

        // Prompt the user so they know the program is waiting for input.
        printf("Enter a message (type 'exit' to quit): ");

        // Read a line of text from the keyboard into 'input'.
        // fgets is safer than scanf because it limits how many characters it reads,
        // preventing buffer overflow.
        fgets(input, sizeof(input), stdin);

        // fgets includes the newline character ('\n') the user typed when pressing Enter.
        // strcspn finds the position of that newline and we overwrite it with a
        // null terminator ('\0') so 'input' behaves like a normal clean string.
        input[strcspn(input, "\n")] = '\0';

        // Compare the input to "exit". strcmp returns 0 if the strings match exactly.
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break; // Exit the while loop, ending the program.
        }

        // Check if the word "hello" appears anywhere inside the input.
        // strstr searches for a substring and returns NULL if it's not found.
        if (strstr(input, "hello") != NULL) {
            printf("Hi there! Nice to see you!\n");
        } else {
            // If it wasn't "exit" and didn't contain "hello", just echo it back.
            printf("You said: %s\n", input);
        }
    }

    return 0; // Tells the operating system the program finished successfully.
}