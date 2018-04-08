#include <iostream>
#include <assert.h>
#ifndef DEBUG_HPP
#define DEBUG_HPP

#ifdef DEBUG
#define log(x) std::cout << x << std::endl
#else 
#define log(x)
#endif

#endif // DEBUG_HPP
