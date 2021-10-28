#include "Hello.h"
#include <gtest/gtest.h>

TEST(Hello, none) {
    GTEST_ASSERT_EQ(1, 1);
}

TEST(Hello, int) {
    std::vector<int> a{10, 20, 30};
    std::vector<int> b{1, 2, 3};
    int *c;
    int ret = func_add<int>(a.data(), b.data(), a.size(), b.size(), c);
    GTEST_ASSERT_EQ(ret, 0);
}

TEST(Hello, float) {
    std::vector<float> a{10.f, 20.f, 30.f};
    std::vector<float> b{1.f, 2.f, 3.f};
    float *c;
    int ret = func_add<float>(a.data(), b.data(), a.size(), b.size(), c);
    GTEST_ASSERT_EQ(ret, 0);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}