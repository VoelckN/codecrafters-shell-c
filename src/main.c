#include <stdio.h>
#include <stdlib.h>
#include <string.h> //For strcspn() in step 2

int main(int argc, char *argv[]) {
  // Flush after every printf
  while (1) {
    setbuf(stdout, NULL);

    printf("$ ");
    char command[1024];
    /* Why fgets()?
    Use fgets() instead of scanf() because scanf() does parsing, fgets just reads the line.
    Parsing will have to be done later, and it's different for different commands.
    */
    fgets(command, sizeof(command), stdin);

    /* About strcspn()
    strcspn() gives string length of <command> up to <"\n"> (given punctuation).
    The character at that location in command (command[#]="\n") is replaced with null terminator.
    */
    command[strcspn(command, "\n")] = '\0'; // Double quotes and single quotes are different!
    printf("%s: command not found\n", command);
  }

  return 0;
}
