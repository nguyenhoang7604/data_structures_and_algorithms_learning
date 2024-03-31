#include "../src/calculator.h"
#include "../src/common.h"
#include <gtest/gtest.h>
#include <string>

TEST(CalculatorTest, calculatorTest) {
    ///Mocking priceMap;
    Common::PriceMap priceMap;
    std::string operationX("Operation X");
    std::string operationY("Operation Y");
    priceMap.emplace("Operation X", Common::OperatorPrice());
    priceMap[operationX].emplace("0123", 0.65);
    priceMap[operationX].emplace("0234", 0.75);

    priceMap.emplace(operationY, Common::OperatorPrice());
    priceMap[operationY].emplace("0123", 1.5);
    priceMap[operationY].emplace("0234", 2.5);


    /// Make Result test
    Calculator calculator(priceMap);
    Common::Result cheapResult = calculator.makeResult(operationX, "0123", 0.65 );
    Common::Result expensiveResult = calculator.makeResult(operationY, "0123", 0.95);
    ASSERT_NE(cheapResult, Common::Result());
    ASSERT_NE(expensiveResult, Common::Result());

    EXPECT_FALSE(calculator.compareResult(cheapResult, expensiveResult));
    EXPECT_TRUE(calculator.compareResult(Common::Result(), expensiveResult));
    EXPECT_TRUE(calculator.compareResult(expensiveResult, cheapResult));


    /// getCheapestPrefix test
    std::string phoneNumer = "01234456778";
    auto result = calculator.getCheapestPrefix(phoneNumer);
    EXPECT_EQ(result.first, operationX);
    EXPECT_EQ(result.second.first, "0123");
    EXPECT_EQ(result.second.second, 0.65);


    auto resultEmpty = calculator.getCheapestPrefix(std::string());
    EXPECT_EQ(resultEmpty, Common::Result());
}
