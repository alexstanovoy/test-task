#include <logger.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


struct s_logger* logger_init(const char* log_file_name) {
  struct s_logger* logger = (struct s_logger*)malloc(sizeof(struct s_logger));
  if (logger == NULL) {
    return NULL;
  }
  logger->logging_file = fopen(log_file_name, "w");
  if (logger->logging_file == NULL) {
    free(logger);
    return NULL;
  }
  logger->logging_handler = default_logger_handler;
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

void default_logger_handler(struct s_logger* logger, LogLevel log_level, const char* format, va_list ap) {
  (void)log_level;
  vfprintf(logger->logging_file, format, ap);
}

void default_error_handler(struct s_logger* logger, int err_no, const char* msg) {
  (void)logger;
  fprintf(stderr, "Message %d, %s", err_no, msg);
}

void logging_error_handler(struct s_logger* logger, int err_no, const char* msg) {
  log_message(logger, ERROR, "Message %d, %s", err_no, msg);
}

void handle_error(struct s_logger* logger, int err_no, const char* msg) {
  if (logger == NULL || msg == NULL) {
    exit(1);
  }
  logger->error_handler(logger, err_no, msg);
}

void log_message(struct s_logger* logger, LogLevel log_level, const char* format, ...) {
  if (logger == NULL || format == NULL) {
    exit(1);
  }
  va_list ap;
  va_start(ap, format);
  logger->logging_handler(logger, log_level, format, ap);
}

void set_error_handler(struct s_logger* logger, error_handler_fnc handler) {
  if (logger == NULL || handler == NULL) {
    exit(1);
  }
  logger->error_handler = handler;
}

void set_logging_handler(struct s_logger* logger, logging_handler_fnc handler) {
  if (logger == NULL || handler == NULL) {
    exit(1);
  }
  logger->logging_handler = handler;
}
