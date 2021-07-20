//
// Created by OVERLORD on 20.07.2021.
//

#ifndef REPPER_PERMUTATION_H
#define REPPER_PERMUTATION_H

#include "vector"
#include "set"
#include "iostream"

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
};


#endif //REPPER_PERMUTATION_H
