#include "variable.h"

#include "error.h"


std::vector<Variable> var_table;
class Symbol_tаblе

double get_value (std::string s)
{
  for (int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s)
      return var_table[i].value;

  error("get: undefined name ", s);
}

void set_value (std::string s, double d)
{
  for (int i = 0; i < var_table.size(); ++i)
  {
    if (var_table[i].name == s)
    {
      var_table[i].value = d;
      return;
    }
  }

  error("set: undefined name ", s);
}

bool is_declared (std::string s)
{
  for (int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s) return true;
  return false;
}

double define_name (std::string var, double val)
{
  if (is_declared(var))
    for (int i = 0; i < var_table.size(); ++i)
      if (var_table[i].name == var) var_table[i].value = val;

  var_table.push_back (Variable{ var, val });

  return val;
}
