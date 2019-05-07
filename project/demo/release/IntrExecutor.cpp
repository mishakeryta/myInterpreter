#include "Interpreter.hpp"


int main(int argc , char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage: ./IntrExecutor <path>\n";
        return 1;
    }

    std::string file = argv[1];
    Intr::Interpreter interpreter(file,std::cout);
    interpreter.execute();
}

