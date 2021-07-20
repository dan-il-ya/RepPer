//
// Created by OVERLORD on 20.07.2021.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/Permutation.h"

TEST(PermutationTest, DefaultConstructorTest){
    EXPECT_EQ(0,Permutation().act(0));

    EXPECT_NO_THROW(Permutation());
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
    EXPECT_THROW(Permutation({0,0,2}),std::exception);
    EXPECT_THROW(Permutation({0,1,3}),std::exception);
    EXPECT_THROW(Permutation({-1,1,2}),std::exception);
}

TEST(PermutationTest, ActTest){
    Permutation p{{0,1,2}};
    EXPECT_THROW(p.act(-1),std::exception);
}