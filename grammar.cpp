#include "grammar.h"
#include "token_stream.h"
#include "error.h"
#include "variable.h"
#include "output.h"
#include "cmath"
double primary ()
{
  Token t = ts.get();
  switch (t.kind)
  {
  case '(':
  {
    double d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("')' expected ");
    return d;
  }

  case '-':
    return -primary();
  case '+':
    return +primary();

  case number:
    return t.value;

  case name:
    return get_value(t.name);

  default:
    error("primary expected");
  }
}


double term ()
{
  double left = primary();
  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '*':
      left *= primary();
      break;
    
    case '%':
    {
      double d = primary();
      if (d == 0) error("divide by zero");
      left = fmod(left, d);
      break;
    }
    case '/':
    {
      double d = primary();
      if (d == 0) error("divide by zero");
      left /= d;
      break;
    }

    default:
      ts.putback(t);
      return left;
    }
  }
}


double expression ()
{
  double left = term();
  while (true)
  {
    Token t = ts.get();

    switch (t.kind)
    {
    case '+':
      left += term();
      break;

    case '-':
      left -= term();
      break;

    default:
      ts.putback(t);
      return left;
    }
  }
}


double declaration ()
{
  Token t = ts.get();
  if (t.kind != name)
    error("name expected in declaration");

  std::string var = t.name;

  t = ts.get();
  if (t.kind != '=')
    error("'=' missing in declaration of ", var);
    
  return define_name (var, expression());
}


output statement ()
{
  Token t = ts.get();
  switch (t.kind)
  {
  output out;
  case let:
    
    out.number = declaration();
    out.status = let;
    return out;
  default:
    ts.putback(t);
    out.number = expression();
    out.status = number;
    return out;
  }
}