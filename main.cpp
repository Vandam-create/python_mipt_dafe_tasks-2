#include <iostream>
#include <stdexcept>

#include "variable.h"
#include "calculator.h"
#include <fstream>

void f();
void f();



int main()
try
{
    define_name("pi", 3.141592653589793);
    define_name("e", 2.718281828459045);

    std::string filename = "test.txt";
    
    std::ifstream input_file(filename);
    
    if (input_file) {

        std::streambuf* original_cin = std::cin.rdbuf();
        
        std::cin.rdbuf(input_file.rdbuf());
        
        calculate();
        
        std::cin.rdbuf(original_cin);
        
        std::cout << " End of file " << std::endl;
      
        return 0;   
    }
    else {
        std::cerr << "Test file '" << filename << "' not found. Starting interactive mode." << std::endl;
    }

    return 0;
}
catch (std::exception& e)
{
    std::cerr << "exception: " << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Oops, unknown exception" << std::endl;
    return 2;
}
/*
int main ()
try
{
  define_name ("pi", 3.141592653589793);
  define_name ("e",  2.718281828459045);

  calculate();

  return 0;
  
 
}
catch (std::exception& e)
{
  std::cerr << "exception: " << e.what() << std::endl;
  return 1;
}
catch (...)
{
  std::cerr << "Oops, unknown exception" << std::endl;
  return 2;
}
*/