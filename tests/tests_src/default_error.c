#include <logger.h>
#include <assert.h>
#include <string.h>


int main() {
  struct s_logger* logger = logger_init("file");
  handle_error(logger, 13, "1488\n");
  handle_error(logger, 42, "228\n");
  logger_destroy(logger);
}
