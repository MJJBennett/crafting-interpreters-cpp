#include <iostream>

class IO
{
public:
    template<typename T, typename... Ts>
    static void error(T t, Ts... ts)
    {
        std::cout << "Error: ";
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

private:
//    static void __print(
};
