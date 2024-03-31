#include "../src/reader.h"
#include "../src/common.h"
#include <gtest/gtest.h>

TEST(ReaderTest, readerTest) {
    Reader readerEmpty("");
    EXPECT_EQ(readerEmpty.parse(), Common::PriceMap());
    Reader reader("../input.txt");
    EXPECT_NE(reader.parse(), Common::PriceMap());
}
