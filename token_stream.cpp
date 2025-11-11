#include "token_stream.h"

#include <iostream>
#include "error.h"

Token_stream ts;

Token Token_stream::get ()
{
  if (full)
  {
    full = false;
    return buffer;
  }

  char ch;
  
  if (!std::cin.get(ch)) {
    return Token{quit};
  }

  switch (ch)
  {
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case ';':
  case '=':
    return Token{ ch };
  case '\n':
    return Token{print};
  case 'q':
    return Token{quit};

  case ' ': case '\t': case '\r':  
    return get();

  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  {
    std::cin.putback(ch);
    double val;
    std::cin >> val;
    return Token{ number, val };
  }

  default:
    if (isalpha(ch))
    {
      std::string s = "";
      s += ch;
      while (std::cin.get(ch) &&
             (isalpha(ch) || isdigit(ch) || ch == '_'))
        s += ch;
      std::cin.putback(ch);

      if (s == declkey) return Token{ let };

      return Token{ name, s };
    }
    error("Bad token");
  }
}

void Token_stream::putback (Token t)
{
  if (full)
    error("putback() into a full buffer");

  buffer = t;
  full = true;
}

void Token_stream::ignore (char c)
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }
  full = false;

  char ch;
  while (std::cin >> ch)
    if (ch == c) return;
}