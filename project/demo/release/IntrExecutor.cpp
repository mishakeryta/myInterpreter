#include "Interpreter.hpp"


int main()
{
    std::string file = "test.txt";
    Intr::Interpreter interpreter(file,std::cout);
    interpreter.execute();
}

