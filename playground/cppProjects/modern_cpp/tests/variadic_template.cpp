#include <iostream>


template<typename T>
T add(const T& arg)
{
  return arg;
}

template<typename T, typename... ARGS>
T add(const T& arg, const ARGS&... args)
{
  std::cout<< arg <<" printing first ag each time\n";
  return arg + add(args...);
}


void tprintf(const char* format) // base function
{
    std::cout << format;
}
 
template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
    for ( ; *format != '\0'; format++ ) {
        if ( *format == '%' ) {
           std::cout << value;
           tprintf(format+1, Fargs...); // recursive call
           return;
        }
        std::cout << *format;
    }
}
 
int main()
{
    add(1, 2u, 3u, 'a', 0.5 , 5.0f);

   // tprintf("% world% %\n","Hello",'!',123);

    return 0;
}
