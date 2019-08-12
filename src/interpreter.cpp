#include <interpreter.h>
#include <iostream>
#include "io.h"
#include "scanner.h"

bool Interpreter::foundError = false;

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

void Interpreter::error(unsigned int line, const std::string& message)
{
    report(line, "", message);
}

void Interpreter::report(unsigned int line, const std::string& where, const std::string& message)
{
    IO::error("(Line ", line, ") ", where, message);
    foundError = true;
}

int Interpreter::run()
{
    unsigned int found_lines = 0;
    while (!foundError || !m_file)
    {
        const auto input = get_line();
        if (!input) break;
        IO::debug("Input: `", *input, "` - Scanning for tokens.");
        Scanner scanner(*input, found_lines);
        auto tokens = scanner.scan_tokens();
        IO::debug("Finished scanning input tokens.");
        for (auto&& token : tokens)
        {
            IO::debug("Token: ", token);
        }
    }
    return 0;
}
