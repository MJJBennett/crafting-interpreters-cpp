#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <optional>
#include <fstream>

class Interpreter
{
public:
    Interpreter(std::ifstream&& input_file) : m_file({std::move(input_file)}) {}
    Interpreter() {}

    std::optional<std::string> get_line();

    int run();

    void error(std::string line);

private:
    std::optional<std::ifstream> m_file;

    unsigned int m_line_count = 0;
};

#endif // INTERPRETER_H
