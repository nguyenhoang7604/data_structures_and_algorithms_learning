#include "calculator.h"
#include <sstream>

using namespace std;


Calculator::Calculator(Common::PriceMap const& pricemap)
    : pricemap_(pricemap)
{

}

Calculator::~Calculator()
{

}

void Calculator::dump(Common::Result const& result) const
{
    std::cout << result.first << std::endl;
    std::cout << result.second.first << std::endl;
    std::cout << result.second.second << std::endl;
}

bool Calculator::compareResult(Common::Result const& lhs, Common::Result const& rhs) const
{
    /// Two result need to have same prefix or prefer longer prefix?
    /// Current solution just don't case about that case
    /*
        if (lhs.second.first != rhs.second.first) return false;
    */

    if ( lhs == Common::Result() || lhs.second.second > rhs.second.second) return true;

    return false;
}

Common::Result Calculator::makeResult(std::string const& operatorName, std::string const& prefix, double const& price)
{
    return Common::Result(operatorName, std::pair<std::string, double>(prefix, price));
}

Common::Result Calculator::getCheapestPrefix(std::string const& phoneNumber)
{
    auto result = Common::Result();

    /// Loop all operator
    for (auto operatorPrice : pricemap_) {

        /// Try to decrease the phone number and find the matched prefix
        /// This way is faster since the phone number lenght should be short and the Prefix list is various.

        auto phoneLenght = phoneNumber.length();
        while (phoneLenght > 0) {

            auto prefix = phoneNumber.substr(0, phoneLenght);

            auto prefixIter = operatorPrice.second.find(prefix);
            if (prefixIter != operatorPrice.second.end()) {
                auto tmpResult = makeResult(operatorPrice.first, prefix, prefixIter->second);

                if (tmpResult == Common::Result()) continue; // Cannot make a result

                if (compareResult(result, tmpResult))
                    result = tmpResult;
                break;
            }
            phoneLenght--;
        }
    }
    return result;
}