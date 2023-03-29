
#include <gtest/gtest.h>
#include "../KRET/KRET.h"

TEST(ExampleTests, Test1)
{
    setlocale(LC_ALL, "Russian");

    NumberAsString X;
    string str = "123";
    X.Set(str);
    string str1 = "сто двадцать три рубля";
    string str2 = X.GetString();
    ASSERT_EQ(str2, str1);
}

TEST(AnotherTests, Test1)
{
    setlocale(LC_ALL, "Russian");

    NumberAsString X;
    string str = "777";
    X.Set(str);
    string str1 = "семьсот семьдесят семь";
    string str2 = X.GetString();
    ASSERT_EQ(str2, str1);
}