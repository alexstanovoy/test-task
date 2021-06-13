#include <logger.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


struct s_logger* logger_init(const char* log_file_name) {
  struct s_logger* logger = (struct s_logger*)malloc(sizeof(struct s_logger));
  if (logger == NULL) {
    return NULL;
  }
  logger_handler->logging_file = fopen(log_file_name, "w");
  if (logger_handler->logging_file == NULL) {
    free(logger);
    return NULL;
  }
  logger->logging_handler = default_log;
  logger->error_handler = default_error_handler;
  return logger;
}

void logger_destroy(struct s_logger* logger) {
  if (logger == NULL) {
    return;
  }
  fclose(logger->logging_file);
  free(logger);
}

void default_logger_handler(enum log_level level, const char* format, va_list ap) {
  vfprintf(logging_file, format, ap);
}

void default_error_handler(int err_no, const char* msg) {
  printf("Message %d, %s", err_no, msg);
}

void logging_error_handler(int err_no, const char* msg) {
  core_log_message(LogLevel::ERROR, "Message %d, %s", msg);
}

void handle_error(struct s_logger* logger, int err_no, const char* msg) {
  logger->error_handler->handler(err_no, msg);
}

void log_message(struct s_logger* logger, enum LogLevel log_level, const char* format, size_t count, ...) {
  va_list ap;
  va_start(ap, count);
  logger->logging_handler(log_level, format, ap);
}

void set_error_handler(struct s_logger* logger, error_handler_fnc handler) {
  logger->error_handler = handler;
}

void set_logging_handler(struct s_logger* logger, logging_handler_fnc handler) {
  logger->logging_handler = handler;
}
