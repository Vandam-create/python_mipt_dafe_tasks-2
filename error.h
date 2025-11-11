#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <stdexcept>
/*
 Функции для обработки ошибок
*/
[[noreturn]] inline void error (const std::string& s)
{
  throw std::runtime_error(s);
}

[[noreturn]] inline void error (const std::string& s, const std::string& s2)
{
  error (s + s2);
}

#endif