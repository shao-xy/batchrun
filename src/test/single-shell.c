#include <string.h>
#include "common/common.h"

int main(int argc, char * argv[])
{
  if (argc == 1) {
    fprintf(stderr, "Usage: %s <shell-cmd>\n", argv[0]);
    return 0;
  }

  argc--;
  argv++;

  setlocale(LC_ALL, "");
  initscr();

  int pr[2], pw[2];
  if (pipe(pr) < 0 || pipe(pw) < 0) {
    perror("Pipe failed");
    exit(1);
  }
  
  // no need to do this: "ls -l" is valid, while "'ls -l'" is not.
  // 
  // char start_file[1024];
  // char * argv0 = argv[0];
  // int i = 0;
  // while (argv0[i] != ' ' && argv0[i] != '\0' && argv0[i] != '\t' && argv0[i] != '\n')
  //   i++;
  // strncpy(start_file, argv0, i);

  //char ** new_argv = (char **) calloc(argc + 3, sizeof(char *));
  //new_argv[0] = "sh";
  //new_argv[1] = "-c";
  //char ** new_argv_c = new_argv + 2;
  //do {
  //  printf("*argv = %s\n", *argv);
  //  *new_argv_c++ = *argv++;
  //} while (--argc);

  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(-1);
  } else if (pid == 0) {
    // child process
    //return execvp("/bin/sh", new_argv);
    //return execvp(start_file, argv);
    close(STDOUT_FILENO);
    dup2(pr[1], STDOUT_FILENO);
    return execvp(argv[0], argv);
  } else {
    // main process
    //dup2(STDIN_FILENO, pw[0]);
    wait(NULL);
    int flags = fcntl(pr[0], F_GETFL, 0);
    fcntl(pr[0], F_SETFL, flags | O_NONBLOCK);
    char c;
    while (read(pr[0], &c, 1) == 1) {
      printw("%c", c);
      //printf("%c", c);
    }
  }
  
  getch();
  endwin();
  return 0;
}
