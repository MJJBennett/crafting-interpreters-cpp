#include <interpreter.h>
#include <iostream>
#include "io.h"

std::optional<std::string> Interpreter::get_line()
{
    std::string line;
    if (m_file) 
    {
        IO::debug("Reading line from file.");
        if (!getline(*m_file, line)) return {};
    }
    else 
    {
        IO::debug("Reading line from stdin.");
        if (!getline(std::cin, line)) return {};
    }
    m_line_count++;
    return line; 
}

void Interpreter::error(std::string line)
{
    IO::error("(At line ", m_line_count, ")"); 
}

int Interpreter::run()
{
    while (true)
    {
        const auto input = get_line();
        if (!input) break;
        IO::debug("Input: ", *input);
    }
    return 0;
}
