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
    //  -- operator*
    //  -- operator*=
    //  -- cyclic_type()
    //  --
    // DONE:
    //  --
    //  --
    //
    std::vector<int> per = {0};
public:
    Permutation();
    explicit Permutation(int n);
    explicit Permutation(std::vector<int> per_);

    int act(int n) const;

    friend std::ostream &operator<<(std::ostream &os, const Permutation &permutation);
};


#endif //REPPER_PERMUTATION_H
