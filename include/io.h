#ifndef IO_HEADER
#define IO_HEADER

#include <iostream>

class IO
{
public:
    template<typename T, typename... Ts>
    static void error(T t, Ts... ts)
    {
        std::cout << "[ERROR] ";
        print(t, ts...);
    }

    template<typename T, typename... Ts>
    static void debug(T t, Ts... ts)
    {
        std::cout << "[Debug] ";
        print(t, ts...);
    }

    template<typename T, typename... Ts>
    static void print(T t, Ts... ts)
    {
        std::cout << t;
        print(ts...);
    }

    template<typename T>
    static void print(T t)
    {
        std::cout << t << '\n';
    }
};

#endif // IO_HEADER
