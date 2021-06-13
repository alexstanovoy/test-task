[![Build Status](https://www.travis-ci.com/alexstanovoy/test-task.svg?branch=master)](https://www.travis-ci.com/alexstanovoy/test-task)
[![Codecov status](https://codecov.io/github/AjReme/Library-STLB/coverage.svg?branch=master)](https://codecov.io/gh/alexstanovoy/test-task)

Сборка:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Тестирование: `ctest`

Все-таки `s_core` не выжил: мое чувство прекрасного не согласно с ним :(

Сущность перестала быть синглтоном: я думаю, что пользователю стоит написать свои 3 строчки на синглтон, если он его хочет, мне же не хочется, чтобы на пользователе осталась чистка памяти из-за этих строчек.

Многопоточность не добавлял. Однако достаточно просто добавить mutex в `s_logger` и lock/unlock в `handle_error` и `log_message` (берегитесь дедлока, если `error_handler` и `logger_handler` будут вызываться друг из друга! Это нужно учесть при проектировании хендлеров).

Travis и Codecov - в подарок!
