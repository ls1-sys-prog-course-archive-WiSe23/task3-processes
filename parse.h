#include <stddef.h>
#include <unistd.h>

struct command {
  struct command *next;

  char **argv;
  size_t argv_cap;
  int argc;
  char *output_redir;
  char *input_redir;
};

struct pipeline {
  struct command first_command;
  char background;
};

enum builtin_type {
  BUILTIN_NONE = 0,
  BUILTIN_EXIT = 1,
  BUILTIN_WAIT = 2,
  BUILTIN_KILL = 3
};

extern enum builtin_type current_builtin;
extern struct pipeline current_pipeline;
extern struct command *current_command, *previous_command;
extern int eof;
extern char* builtin_arg;

int yyparse(void);
void run_pipeline(struct pipeline *p);
void run_builtin(enum builtin_type builtin, char* builtin_arg);
