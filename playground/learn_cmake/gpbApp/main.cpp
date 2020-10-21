#include <google/protobuf/message.h>
#include  <gtest/gtest.h>


TEST( LEARN_GTEST , equalNumbers)
{
    auto num1 =  10, num2 = 10;
    EXPECT_EQ(num1, num2);
}




int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}