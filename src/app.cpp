#include <vector>
#include <string>
#include <fstream>
#include <io.h>
#include <interpreter.h>

int main(int argc, char* argv[])
{
    // Little bit of boilerplate to either launch in
    // command-line interpreter mode or in file
    // interpreter mode.
    if (argc == 1)
    {
        Interpreter interpreter;
        return interpreter.run();
    }
    if (argc == 2)
    {
        std::string filename(*(argv + 1));

        std::ifstream input_file(filename);
        if (!input_file.is_open())
        {
            IO::error("File does not exist: ", filename);
        }

        Interpreter interpreter(std::move(input_file));
        return interpreter.run();
    }
    IO::error("Interpreter takes 0 or 1 commandline arguments.");
    return 11;
}
