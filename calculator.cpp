/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>


#include "token_stream.h"
#include "error.h"
#include "grammar.h"
#include "variable.h"
#include "output.h"

const std::string prompt = "> ";
const std::string result = "= ";


void clean_up_mess ()
{
  ts.ignore (print);
}


void calculate ()
{
  while (true)
  try
  {
    std::cout << prompt;
    Token t = ts.get();
    while (t.kind == print)
      t = ts.get();
    if (t.kind == quit) return;

    ts.putback(t);
    output temp = statement();
    if(temp.status != let)
    std::cout << result << temp.number << std::endl;
    else
    std::cout << "Success" << std::endl;
  }
  catch (std::runtime_error& e)
  {
    std::cerr << e.what() << std::endl;
    clean_up_mess();
  }
}


