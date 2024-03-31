#include "common.h"
#include "reader.h"
#include "calculator.h"

int main()
{
    /// Temporary use relative path
    Reader reader("../input.txt");
    Common::PriceMap priceMap = reader.parse();
    reader.dump(priceMap);
    Calculator calculator(priceMap);

    std::string phoneNumber("68123456789");
    Common::Result  result = calculator.getCheapestPrefix(phoneNumber);

    if (result == Common::Result()) {
        std::cout << "Phone number [" << phoneNumber <<  "is not supported" << std::endl;
    } else {
        std::cout << "Cheapest prefix is: \n";
        calculator.dump(result);
    }


    return 0;
}