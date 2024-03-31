#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <map>
#include <string>

struct Common
{
    using Result = std::pair<std::string, std::pair<std::string, double>>;
    using OperatorPrice = std::map<std::string, double>;
    using PriceMap = std::map<std::string, OperatorPrice>;
};


#endif //__COMMON_H__