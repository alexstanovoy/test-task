#include <logger.h>
#include <assert.h>
#include <string.h>


int main() {
  struct s_logger* logger = logger_init("file");
  set_error_handler(logger, logging_error_handler);
  handle_error(logger, 13, "1488\n");
  handle_error(logger, 42, "228\n");
  logger_destroy(logger);

  FILE* log_file = fopen("file", "r");

  int x;
  char s1[256], s2[256], s3[256];  // Yes, it's unsafe, I know.
  fscanf(log_file, "%s %s %s", s1, s2, s3);
  assert(strcmp(s1, "Message") == 0);
  assert(strcmp(s2, "13,") == 0);
  assert(strcmp(s3, "1488") == 0);
  assert(x == TRACE);

 fscanf(log_file, "%s %s %s", s1, s2, s3);
  assert(strcmp(s1, "Message") == 0);
  assert(strcmp(s2, "42,") == 0);
  assert(strcmp(s3, "228") == 0);
  assert(x == TRACE);
  fclose(log_file);
}
