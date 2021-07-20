//
// Created by OVERLORD on 20.07.2021.
//

#ifndef REPPER_PERMUTATION_H
#define REPPER_PERMUTATION_H

#include "vector"
#include "set"
#include "iostream"
#include "algorithm"

class Permutation {
    // TODO:
    //  -- cyclic_type()
    //  --
    //  --
    //  --
    // DONE:
    //  -- operator*
    //  -- operator*=
    //
    std::vector<int> per = {};
public:
    Permutation();
    explicit Permutation(int n);
    explicit Permutation(std::vector<int> per_);

    int num() const;

    int proper_num() const;

    Permutation inv() const;

    int act(int n) const;

    bool operator==(const Permutation& permutation) const;

    bool operator!=(const Permutation& permutation) const;

    Permutation operator*(const Permutation& permutation) const;

    Permutation& operator*=(const Permutation& permutation);

    Permutation operator^(int pow) const;

    Permutation& operator^=(int pow);

    friend std::ostream &operator<<(std::ostream &os, const Permutation &permutation);
};


static Permutation ID{0};
static Permutation C2{2};
static Permutation C3{3};
static Permutation C4{4};
static Permutation C5{5};



#endif //REPPER_PERMUTATION_H
