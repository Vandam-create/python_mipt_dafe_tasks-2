#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

struct Variable
{
  std::string name;
  double value;

  Variable (std::string n, double v)
    : name{ n }, value{ v }
  { }
};


extern std::vector<Variable> var_table;

double get_value (std::string s);
void set_value (std::string s, double d);
bool is_declared (std::string s);
double define_name (std::string var, double val);

#endif