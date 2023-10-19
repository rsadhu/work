#include <gtest/gtest.h>
#include "json/json.h"

#include <iostream>

class MockClass
{
public:
    MockClass()
    {
        m_str = "test";
    }

    void process(int num = 0)
    {
        if (num % 2 == 0)
        {
            m_str = "TEST";
        }
    }
    std::string m_str;
};

class LearnFixture : public ::testing::Test
{
public:
    LearnFixture()
    {
        std::cout << "LearnFixture::LearnFixture\n";
    }

    virtual ~LearnFixture()
    {
        std::cout << "LearnFixture::~LearnFixture\n";
    }

    virtual void SetUp()
    {
        std::cout << "LearnFixture::SetUp\n";
    }

    virtual void TearDown()
    {
        std::cout << "LearnFixture::TearDown\n";
    }
};

TEST_F(LearnFixture, first_test)
{
    MockClass mc;
    mc.process(2);
    std::string str = "test";

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    EXPECT_EQ(mc.m_str, str);
}

TEST_F(LearnFixture, second_test)
{
    MockClass mc;
    mc.process(1);
    EXPECT_EQ(mc.m_str, "test");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}