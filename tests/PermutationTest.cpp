//
// Created by OVERLORD on 20.07.2021.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Permutation.h"

TEST(PermutationTest, DefaultConstructorTest){
    EXPECT_NO_THROW(Permutation());

    EXPECT_EQ(0,Permutation().act(0));
    EXPECT_EQ(1,Permutation().act(1));
    EXPECT_EQ(2,Permutation().act(2));
}

TEST(PermutationTest, CyclicConstructorTest){
    EXPECT_EQ(0, Permutation(2).act(1));
    EXPECT_EQ(1, Permutation(2).act(0));


    EXPECT_NO_THROW(Permutation(2));
    EXPECT_NO_THROW(Permutation(100));
    EXPECT_NO_THROW(Permutation(0));
    EXPECT_THROW(Permutation(-1),std::exception);
}

TEST(PermutationTest, GeneralConstructorTest){
    EXPECT_NO_THROW(Permutation({0,1,2,3}));
    EXPECT_NO_THROW(Permutation({1,0,2,3}));
    EXPECT_NO_THROW(Permutation({3,2,1,0}));

    EXPECT_THROW(Permutation({0,0,2}),std::exception);
    EXPECT_THROW(Permutation({0,1,3}),std::exception);
    EXPECT_THROW(Permutation({-1,1,2}),std::exception);
}

TEST(PermutationTest, ActTest){
    Permutation p{{0,1,2}};
    EXPECT_THROW(p.act(-1),std::exception);
}

TEST(PermutationTest, NumTest){
    // explict values:
    EXPECT_EQ(Permutation().num(),0);
    EXPECT_EQ(Permutation(0).num(),0);
    EXPECT_EQ(Permutation(1).num(),1);
    EXPECT_EQ(Permutation(2).num(),2);


    for(int i = 0; i < 10; i ++)
        EXPECT_EQ(Permutation(i).num(),i);
    EXPECT_EQ(Permutation({0,1,2,3,4,5}).num(),6);
    EXPECT_EQ(Permutation({1,0,2,3,4,5}).num(),6);
    EXPECT_EQ(Permutation({0,2,1,3,4,5}).num(),6);
    EXPECT_EQ(Permutation({0,2,1,3,5,4}).num(),6);

}

TEST(PermutationTest, ProperNumTest){
    // explict values:
    EXPECT_EQ(Permutation().proper_num(),1);
    EXPECT_EQ(Permutation(0).proper_num(),1);
    EXPECT_EQ(Permutation(1).proper_num(),1);
    EXPECT_EQ(Permutation(2).proper_num(),2);

    for(int i = 1; i < 10; i ++)
        EXPECT_EQ(Permutation(i).proper_num(),i);
    EXPECT_EQ(Permutation({0,1,2,3,4,5}).proper_num(),1);
    EXPECT_EQ(Permutation({1,0,2,3,4,5}).proper_num(),2);
    EXPECT_EQ(Permutation({0,2,1,3,4,5}).proper_num(),3);
    EXPECT_EQ(Permutation({0,2,1,3,5,4}).proper_num(),6);
}

TEST(PermutationTest, EqualTest){
    EXPECT_TRUE(Permutation()==Permutation());
    EXPECT_TRUE(Permutation()==Permutation(0));
    EXPECT_TRUE(Permutation(0)==Permutation(1));
    EXPECT_TRUE(Permutation(1)==Permutation(0));

    for(int i = 0; i < 10; i++)
        EXPECT_TRUE(Permutation(i)==Permutation(i));

    EXPECT_TRUE(Permutation({1,2,0,3,4})==Permutation({1,2,0,3,4,5}));
    EXPECT_TRUE(Permutation({1,2,0,3,4})==Permutation({1,2,0}));
    EXPECT_TRUE(Permutation({1,2,0})==Permutation({1,2,0,3,4,5}));

    EXPECT_FALSE(Permutation({2,1,0,3,4})==Permutation({1,2,0,3,4,5}));
    EXPECT_FALSE(Permutation({2,1,0,3,4})==Permutation({1,2,0}));
    EXPECT_FALSE(Permutation({2,1,0})==Permutation({1,2,0,3,4,5}));

    EXPECT_FALSE(Permutation({1,2,0,3,4})!=Permutation({1,2,0,3,4,5}));
    EXPECT_FALSE(Permutation({1,2,0,3,4})!=Permutation({1,2,0}));
    EXPECT_FALSE(Permutation({1,2,0})!=Permutation({1,2,0,3,4,5}));

    EXPECT_TRUE(Permutation({2,1,0,3,4})!=Permutation({1,2,0,3,4,5}));
    EXPECT_TRUE(Permutation({2,1,0,3,4})!=Permutation({1,2,0}));
    EXPECT_TRUE(Permutation({2,1,0})!=Permutation({1,2,0,3,4,5}));
}

TEST(PermutationTest, MultiplicationTest){
    EXPECT_TRUE(Permutation()*Permutation() == ID);
    EXPECT_TRUE(Permutation(0)*Permutation(0) == ID);
    EXPECT_TRUE(Permutation(1)*Permutation(0) == ID);
    EXPECT_TRUE(C2 * C2 == ID);
    EXPECT_TRUE(C3 * C3 * C3 == ID);
    EXPECT_TRUE(C4 * C4 * C4 * C4 == ID);
    EXPECT_TRUE(C5 * C5 * C5 * C5 * C5 == ID);
    EXPECT_TRUE(C2 * C3 != C3 * C2);
    EXPECT_TRUE(C2 * C3 == Permutation({0,2,1}));
    EXPECT_TRUE(C3 * C2 == Permutation({2,1,0}));
}

TEST(PermutationTest, MultiplicationAssignmentTest){
    Permutation p = C2;
    EXPECT_TRUE((p *= C2) == ID);
    EXPECT_TRUE(p == ID);
}

TEST(PermutationTest, InvTest){
    EXPECT_TRUE(C2.inv() == C2);
    EXPECT_TRUE(C3.inv() == C3 * C3);
    EXPECT_TRUE(Permutation({0,1,3,4,2}) == Permutation({0,1,4,2,3}).inv());
}

TEST(PermutationTest, PowTest){
    for(int i = 0; i < 10; i++)
        EXPECT_TRUE((Permutation(i) ^ i) == ID);
    EXPECT_TRUE( (C4 ^ 2) == (C4 ^ -2));

    for(int i = 0; i < 10; i++)
        EXPECT_TRUE((Permutation(i) ^= i) == ID);

    Permutation p({1,3,2,0,7,4,5,6});
    EXPECT_TRUE((p^3) == (p * p * p));
    EXPECT_TRUE((p^-3) == (p * p * p).inv());
}