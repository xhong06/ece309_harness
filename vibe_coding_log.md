This is the file with the vibe coding log.

(This is the prompt submitted to Claude Code)
Prompt 1:
I need to write a simple command-line program in C. I am a beginner, so please keep the 
code as simple as possible. As a constraint, do not use external libraries, only use standard ones like <stdio.h> 
and <string.h>. 

Here is the specification for the program: 
  1. It should run an infinite while loop that asks for user input using fgets. 
  2. If the user types 'exit', the loop should break and the program should end. 
  3. If the user types a sentence containing the word 'hello', the program should print a 
hardcoded greeting. 
  4. If the user types anything else, it should echo their input back to them. 
  5. Please add clear, line-by-line comments explaining what the code is doing.






(Claude Code's response to prompt 1)
Response 1:
Here's a simple C program that matches your spec:

```c
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
```

### How it works, step by step
- **`fgets(input, sizeof(input), stdin)`** reads up to 99 characters (leaving room for the null terminator) from standard input (the keyboard) into `input`.
- **`strcspn(input, "\n")`** finds where the newline character is in the string, and we replace it with `'\0'` to clean up the string (otherwise "hello\n" wouldn't match nicely and printing would look odd).
- **`strcmp`** does an exact match check for "exit".
- **`strstr`** checks if "hello" is a *substring* anywhere in the sentence (so "hello there" or "well hello!" would both trigger it).
- The `while (1)` loop keeps running until `break` is hit.

### To compile and run it
```bash
gcc program.c -o program
./program
```

A couple of things worth knowing as a beginner:
- This match on "hello" is case-sensitive — typing "Hello" won't trigger it. If you want case-insensitive matching, that requires a bit more code (looping through and lowercasing each character), so let me know if you'd like that added.
- If someone pastes in a line longer than 99 characters, `fgets` will just stop at the limit rather than crash, which is part of why it's the safe choice here.









(This is the command to compile the code and the result of the compilation)
Compilation:
$ gcc harness.c -o harness

//No errors; printed nothing.







(This is a test run of the program examining different edge cases)
Running the Program:
$ ./harness hello
Enter a message (type 'exit' to quit): hello
Hi there! Nice to see you!
Enter a message (type 'exit' to quit): hi
You said: hi
Enter a message (type 'exit' to quit): hi there
You said: hi there
Enter a message (type 'exit' to quit): quit
You said: quit
Enter a message (type 'exit' to quit): e
You said: e
Enter a message (type 'exit' to quit): ex
You said: ex
Enter a message (type 'exit' to quit): exi
You said: exi
Enter a message (type 'exit' to quit): exi 
You said: exi 
Enter a message (type 'exit' to quit): exi t
You said: exi t
Enter a message (type 'exit' to quit): ex it
You said: ex it
Enter a message (type 'exit' to quit): exit
Goodbye!
