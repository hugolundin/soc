#include "utilities.h"

std::ostream &operator<<(std::ostream &os, CData const &c) 
{
    return os << (int) c;
}
