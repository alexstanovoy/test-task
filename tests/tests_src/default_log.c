#include <logger.h>
#include <assert.h>
#include <string.h>


int main() {
  struct s_logger* logger = logger_init("file");
  log_message(logger, TRACE, "Hello %s %d\n", "world", TRACE);
  log_message(logger, DEBUG, "Hello %s %d\n", "world", DEBUG);
  log_message(logger, INFO, "Hello %s %d\n", "world", INFO);
  log_message(logger, WARNING, "Hello %s %d\n", "world", WARNING);
  log_message(logger, ERROR, "Hello %s %d\n", "world", ERROR);
  logger_destroy(logger);
  FILE* log_file = fopen("file", "r");

  int x;
  char s1[256], s2[256];  // Yes, it's unsafe, I know.
  fscanf(log_file, "%s %s %d", s1, s2, &x);
  assert(strcmp(s1, "Hello") == 0);
  assert(strcmp(s2, "world") == 0);
  assert(x == TRACE);

  fscanf(log_file, "%s %s %d", s1, s2, &x);
  assert(strcmp(s1, "Hello") == 0);
  assert(strcmp(s2, "world") == 0);
  assert(x == DEBUG);

  fscanf(log_file, "%s %s %d", s1, s2, &x);
  assert(strcmp(s1, "Hello") == 0);
  assert(strcmp(s2, "world") == 0);
  assert(x == INFO);

  fscanf(log_file, "%s %s %d", s1, s2, &x);
  assert(strcmp(s1, "Hello") == 0);
  assert(strcmp(s2, "world") == 0);
  assert(x == WARNING);

  fscanf(log_file, "%s %s %d", s1, s2, &x);
  assert(strcmp(s1, "Hello") == 0);
  assert(strcmp(s2, "world") == 0);

  assert(x == ERROR);
  fclose(log_file);
}
