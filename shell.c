#include "shell.h"

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{
  printf("Token is: %s \n", args[1]);
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/find", args);
  if (success < 0)
  {
    printf("Find failed to execute execvp \n");
    return 1;
  }
  /** TASK 4 **/
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
  printf("Token is: %s \n", args[1]);
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/display", args);
  if (success < 0)
  {
    printf("DisplayFile failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'display' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/listdirall", args);
  if (success < 0)
  {
    printf("ListDirAll failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/listdir", args);
  if (success < 0)
  {
    printf("ListDir failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDir
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
  printf("Token is: %s \n", args[1]);
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/countline", args);
  if (success < 0)
  {
    printf("CountLine failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'countline' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/summond", args);
  if (success < 0)
  {
    printf("Summond failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'summond' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue
}

/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
  int success = execvp("/mnt/c/Users/tanka/Desktop/CSE/Ass_1/ProgrammingAssignment1/PA1/shellPrograms/checkdaemon", args);
  if (success < 0)
  {
    printf("CheckDaemon failed to execute execvp \n");
    return 1;
  }

  /** TASK 4 **/
  // 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue

  return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  return 0;
}

/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  if (args[1] == NULL)
  {
    printf("Please type a shell command after \'usage\' \n");
    return 1;
  }
  int functionIndex = -1;

  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args)
{
  if (args[0] == NULL)
    return 1;

  else
  {
    for (int i = 0; i < numOfBuiltinFunctions(); i++)
    {
      int checkEqual = strcmp(builtin_commands[i], args[0]);
      if (strcmp(builtin_commands[i], args[0]) == 0)
      {
        if (i > 3)
        {
          {
            pid_t pid;

            pid = fork();

            if (pid < 0)
            {
              fprintf(stderr, "Fork has failed. Exiting now");
              return 1;
            }
            else if (pid == 0) //child
            {
              return builtin_commandFunc[i](args);
            }
            else //parent
            {
              int child_status;
              int exit_status = -1;
              printf("Fork works, waiting for child \n");
              pid_t child_pid = waitpid(pid, &child_status, WUNTRACED);
              //if child terminates properly, WIFEXITED(status) returns TRUE
              if (WIFEXITED(child_status))
              {
                exit_status = WEXITSTATUS(child_status);
              }
              if (exit_status == -1)
              {
                printf("Child did not terminate properly \n");
              }
              else if (exit_status != 1)
              {
                printf("System error \n");
              }
            }
            return 1;
          }
        }
        else
        {
          return builtin_commandFunc[i](args);
        }
      }
    }
    printf("Invalid command received. Type help to see what commands are implemented. \n");
  }
  return 1;

  /** TASK 3 **/

  // 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
  // 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
  // 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
  // 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
  // 5. For the parent process, wait for the child process to complete and fetch the child's return value.
  // 6. Return the child's return value to the caller of shellExecuteInput
  // 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
  /** TASK 1 **/
  // read one line from stdin using getline()

  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  // 2. Check that the char* returned by malloc is not NULL
  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  // 4. Return the char*

  char *buffer = malloc(sizeof(char) * SHELL_BUFFERSIZE);
  int size = sizeof(buffer);
  if (buffer != NULL)
  {
    getline(&buffer, &size, stdin);
  }
  buffer[strlen(buffer) - 1] = 0;
  return buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/

char **shellTokenizeInput(char *line)
{

  /** TASK 2 **/
  // 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
  // 2. Check that char ** that is returend by malloc is not NULL
  // 3. Tokenize the *line using strtok() function
  // 4. Return the char **
  char **token_positions = malloc(sizeof(char *) * SHELL_BUFFERSIZE);
  if (token_positions != NULL)
  {
    char *token = strtok(line, " ");
    int index = 0;

    token_positions[index] = token;
    index++;
    while (token != NULL)
    {
      token = strtok(NULL, " ");
      token_positions[index] = token;
      index++;
    }
    token_positions[index] = NULL;
  }

  return token_positions;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
  //instantiate local variables
  char *line;     // to accept the line of string from user
  char **args;    // to tokenize them as arguments separated by spaces
  int status = 1; // to tell the shell program whether to terminate shell or not

  while (status == 1)
  {
    printf("CSEShell> ");
    line = shellReadLine();
    args = shellTokenizeInput(line);
    status = shellExecuteInput(args);
    free(line);
    free(args);
  }
  exit(0);
  /** TASK 5 **/
  //write a loop where you do the following:

  // 1. print the message prompt
  // 2. clear the buffer and move the output to the console using fflush
  // 3. invoke shellReadLine() and store the output at line
  // 4. invoke shellTokenizeInput(line) and store the output at args**
  // 5. execute the tokens using shellExecuteInput(args)

  // 6. free memory location containing the strings of characters
  // 7. free memory location containing char* to the first letter of each word in the input string
  // 8. check if shellExecuteInput returns 1. If yes, loop back to Step 1 and prompt user with new input. Otherwise, exit the shell.
}

int main(int argc, char **argv)
{

  printf("Shell Run successful. Running now: \n");

  // Run command loop
  shellLoop();
  return 0;
}