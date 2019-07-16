#include <string>
#include <optional>

class Interpreter
{
public:
    Interpreter(std::ifstream&& input_file) : m_file(std::move(input_file)) {
         
    }
    Interpreter() {}

    std::string get_line()
    {
        return ""; 
    }

    int run() {return 0;}

private:
    std::optional<std::ifstream> m_file;
};

