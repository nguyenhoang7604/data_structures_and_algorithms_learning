#ifndef __READER_H__
#define __READER_H__

#include "common.h"

#include <iostream>
#include <string>

class Reader {
public:
    Reader(std::string const& inputFilePath);
    ~Reader();

    Common::PriceMap parse();
    void dump(Common::PriceMap const&);

protected:
    Common::PriceMap parsePrice(std::string const&);

private:
    std::string inputFilePath_;
    static std::string const Operator;
};

#endif //__READER_H__