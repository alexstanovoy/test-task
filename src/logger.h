#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum {
  TRACE = 0,
  DEBUG = 1,
  INFO = 2,
  WARNING = 3,
  ERROR = 4,
} LogLevel;

struct s_logger;

typedef void (*error_handler_fnc)(struct s_logger* logger, int err_no, const char* msg);

typedef void (*logging_handler_fnc)(struct s_logger* logger, LogLevel level, const char* format, va_list ap);

struct s_logger {
  error_handler_fnc error_handler;
  logging_handler_fnc logging_handler;
  FILE* logging_file;
  // pthread_mutex?
};


struct s_logger* logger_init(const char* log_file_name);

void logger_destroy(struct s_logger* logger);

void default_logger_handler(struct s_logger* logger, LogLevel level, const char* format, va_list ap);

void default_error_handler(struct s_logger* logger, int err_no, const char* msg);

void logging_error_handler(struct s_logger* logger, int err_no, const char* msg);

void handle_error(struct s_logger* logger, int err_no, const char* msg);

void log_message(struct s_logger* logger, LogLevel level, const char* format, ...);

void set_error_handler(struct s_logger* logger, error_handler_fnc handler);

void set_logging_handler(struct s_logger* logger, logging_handler_fnc handler);
