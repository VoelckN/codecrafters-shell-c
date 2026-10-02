#include <stdio.h>
#include <stdlib.h>
#include <string.h> //For strcspn() in step 2

int main(int argc, char *argv[]) {
  // Flush after every printf
  while (1) {
    setbuf(stdout, NULL);

    printf("$ ");
    char input[1024];
    /* Why fgets()?
    Use fgets() instead of scanf() because scanf() does parsing, fgets just reads the line.
    Parsing will have to be done later, and it's different for different commands.
    */
    fgets(input, sizeof(input), stdin);

    /* About strcspn()
    strcspn() gives string length of <command> up to <"\n"> (given punctuation).
    The character at that location in command (command[#]="\n") is replaced with null terminator.
    */
    input[strcspn(input, "\n")] = '\0'; // Double quotes and single quotes are different!
    char * command = strtok(input, " ");
    char * parameters = strtok(NULL, "");
    
    if (strcmp(input, "exit")==0) {
      break;
    } else if (strcmp(command, "echo")==0){
      printf("%s\n", parameters);
    } else {
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}
