#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


struct s_core* core_instance() {
  // Multithreading
  if (core == NULL) {
    core = (struct s_core*)malloc(sizeof(struct s_core));
    core->log_ = log_new(default_log);
    core->handler_ = error_handler_new(default_error_handler);
  }
  return core;
}

struct s_log* log_new(log_fnc logger) {
  struct s_log* log_instance = (struct s_log*)malloc(sizeof(struct s_log));
  log_instance->log_ = logger;
  if (logging_file == NULL) {
    logging_file = fopen("test.log", "rw");
  }
  return log_instance;
}

void default_log(enum log_level level, const char* format, va_list ap) {
  vfprintf(logging_file, format, ap);
}

struct s_error_handler* error_handler_new(error_handler_fnc handler) {
  struct s_error_handler* handler_ = malloc(sizeof(handler));
  handler_->handle_ = handler;
  return handler_;
}

void default_error_handler(int err_no, const char* msg) {
  printf("Message %d, %s", err_no, msg);
}

void logging_error_handler(int err_no, const char* msg) {
  core_log_message(log_level_error, "Message %d, %s", msg);
}

void core_log_message(enum log_level level, const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  core_instance()->log_->log_(level, format, ap);
}

void core_handle_error(int err_no, const char* msg) {
  core_instance()->handler_->handle_(err_no, msg);
}

void core_set_error_handler(error_handler_fnc handler) {
  struct s_core* core = core_instance();
  core->handler_->handle_ = handler;
}
