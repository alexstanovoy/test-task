#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*error_handler_fnc)(int err_no, const char* msg);
typedef void (*log_fnc)(enum log_level level, const char* format, va_list ap);


static FILE* logging_file = NULL;
static struct s_core* core = NULL;

enum log_level {
  TRACE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

struct s_error_handler {
    error_handler_fnc handle_;
};

struct s_log {
  log_fnc log_;
};

struct s_core {
  struct s_error_handler* handler_;
  struct s_log* log_;
};


struct s_core* core_instance();

struct s_log* log_new(log_fnc logger);

void log_destroy(struct s_log* logger);

void default_log(enum log_level level, const char* format, va_list ap);

void default_error_handler(int err_no, const char* msg);

void core_handle_error(int err_no, const char* msg);

void core_log_message(enum log_level level, const char* format, ...);

void core_set_error_handler(error_handler_fnc handler);
