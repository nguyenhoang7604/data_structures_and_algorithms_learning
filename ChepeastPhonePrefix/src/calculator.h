#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
#include "common.h"

class Calculator {
public:
    Calculator(Common::PriceMap const& pricemap);
    ~Calculator();

    Common::Result getCheapestPrefix(std::string const& phoneNumber);
    /// Compare two result, retrn true if new result is cheaper
    bool compareResult(Common::Result const&, Common::Result const&) const; // public for UT
    /// Create a result from matching prefix index
    Common::Result makeResult(std::string const&, std::string const&, double const&); // public for UT
    void dump(Common::Result const&) const;

private:
    Common::PriceMap pricemap_;
};

#endif //__CALCULATOR_H__