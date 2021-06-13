#include <logger.h>
#include <assert.h>
#include <string.h>


int is_used = 0;

void func(struct s_logger* logger, LogLevel level, const char* format, va_list ap) {
  (void)logger;
  (void)level;
  (void)format;
  (void)ap;
  is_used = 1;
}

int main() {
  struct s_logger* logger = logger_init("file");
  assert(is_used == 0);
  set_logging_handler(logger, func);
  assert(is_used == 0);
  log_message(logger, TRACE, "Hello %s %d\n", "world", TRACE);
  assert(is_used == 1);
  logger_destroy(logger);
}
