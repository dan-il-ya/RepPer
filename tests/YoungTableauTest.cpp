//
// Created by OVERLORD on 21.07.2021.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/YoungTableau.h"
#include "string"
#include "sstream"

void EXPECT_STRINGSTREAMEQ(const YoungTableau &tb, const std::string &s_){
    std::string tmp, s;
    std::stringstream ss;
    ss << tb;
    while(!ss.eof()){
        ss >> tmp;
        s += tmp + ' ';
    }
    //ss.getline() >> s;
    EXPECT_EQ(s, s_ + ' ');
}

TEST(YoungTableauTest, StringOutputTest){
    EXPECT_STRINGSTREAMEQ(YoungTableau(C2),"(0 1)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C3),"(0 1 2)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C4),"(0 1 2 3)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C5),"(0 1 2 3 4)");

    EXPECT_STRINGSTREAMEQ(YoungTableau(C2 * C2.shift(2)),
                          "(2 3)(0 1)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C2 * C2.shift(3)),
                          "(3 4)(0 1)(2)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C2 * C2.shift(4)),
                          "(4 5)(0 1)(3)(2)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C3 * C2.shift(3)),
                          "(0 1 2)(3 4)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C4* C3.shift(4) * C2.shift(7)),
                          "(0 1 2 3)(4 5 6)(7 8)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C4 * C2.shift(4) * C3.shift(6)),
                          "(0 1 2 3)(6 7 8)(4 5)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C4 * C2.shift(4) * C3.shift(6) * C3.shift(9)),
                          "(0 1 2 3)(9 10 11)(6 7 8)(4 5)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(C4 * C2.shift(4) * C4.shift(6)),
                          "(6 7 8 9)(0 1 2 3)(4 5)");

    EXPECT_STRINGSTREAMEQ(YoungTableau(Permutation{{5,4,3,2,1,0}}),
                          "(2 3)(1 4)(0 5)");
    EXPECT_STRINGSTREAMEQ(YoungTableau(Permutation{{1,3,4,0,5,2}}),
                          "(2 4 5)(0 1 3)");
}
