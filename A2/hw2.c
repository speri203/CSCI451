#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

  printf("The process id is: %d\n", (int)getpid());
  char *Command = "X\n";
  pid_t pid = fork();
  if(pid < 0) {
    perror("FORK FAILED.\n");
    return 0;
  }
  if(pid == 0) { //Child code execution goes here.
    printf("CHILD: Process ID: %d\n", (int)getpid());
    system("xclock");
    execv(Command, NULL);
    exit(0);
  }

  /*
    Below this block is parent or pid_t > 1 case
  */
  printf("PARENT: Process ID: %d\n", (int)getpid());
  //wait(NULL); // Requesting child process to be complete
  main();
  return 0;
}
