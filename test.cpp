#include <gtest/gtest.h>

class TestBasic : public ::testing::Test
{
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(TestBasic, TestBasic)
{
    ASSERT_EQ(2 + 2, 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
