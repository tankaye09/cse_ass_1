#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v pts > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int returnValue;
   returnValue = system(command);
   if (returnValue < 0)
   {
      printf("Error executing command");
      exit(1);
   }
   free(command);

   int live_daemons = 0;

   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   // 2. Fetch line by line using getline()
   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result
   FILE *fp;
   char *line_buffer = 0;
   size_t size = 0;
   int line_count = 0;
   int lineExist;

   fp = fopen("output.txt", "r");

   if (!fp)
   {
      printf("CSEShell: File doesn't exist.\n");
      return 1;
   }

   while (1)
   {
      lineExist = getline(&line_buffer, &size, fp);
      // printf(lineExist);
      free(line_buffer);
      line_buffer = NULL;
      if (lineExist == -1)
      {
         break;
      }
      line_count++;
   }
   fclose(fp);
   printf("There are %d lines in %s\n", line_count, "output.txt");

   live_daemons = line_count;

   if (live_daemons == 0)
      printf("No daemon is alive right now \n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }

   // TODO: close any file pointers and free any statically allocated memory

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}