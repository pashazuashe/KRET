
#include <gtest/gtest.h>
#include "../KRET/KRET.h"
#include <iostream>
#include <sstream>
#include <string>

TEST(MyTest, Test1)
{
    setlocale(LC_ALL, "ru_RU");

    string str = "сто двадцать рублей";
    NumberAsString X;
    X.Set(int(120));
    string str2 = *X.GetString();

    EXPECT_EQ(str, str2);

    cout << "\n"
         << "X = " << str2 << "\n";

    setlocale(LC_ALL, "RU.utf8");
    cout << "str = " << str << "\n\n";
}
// тут несостыковочка с кодировками :(
// хотя английские буковки работают