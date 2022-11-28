#include "saveload.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(MultiplyTests, TestIntegerOne_One)
{
    const auto expected = 1;
    const auto actual = 1;
    ASSERT_EQ(expected, actual);
}

TEST(Serialize, Serialize_test) {
    std::stringstream stream;
    std::vector<int> arr{ 1,2,3,4,5,6,7,8,9 };
    Serialize(arr, stream);
    std::vector<int> result;
    Deserialize(stream, result);
    ASSERT_EQ(arr, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}