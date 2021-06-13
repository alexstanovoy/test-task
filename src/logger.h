#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


typedef void (*error_handler_fnc)(int err_no, const char* msg);
typedef void (*logging_handler_fnc)(enum log_level level, const char* format, va_list ap);

enum LogLevel {
  TRACE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

struct s_logger {
  error_handler_fnc error_handler;
  logging_handler_fnc logging_handler;
  FILE* logging_file;
};


struct s_logger* logger_init();

void logger_destroy(struct s_logger* logger);

void default_logger_handler(enum log_level level, const char* format, va_list ap);

void default_error_handler(int err_no, const char* msg);

void handle_error(struct s_logger* logger, int err_no, const char* msg);

void log_message(struct s_logger* logger, enum log_level level, const char* format, ...);

void set_error_handler(struct s_logger* logger, error_handler_fnc handler);

void set_logging_handler(struct s_logger* logger, logging_handler_fnc handler);
