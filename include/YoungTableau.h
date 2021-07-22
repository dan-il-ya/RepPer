//
// Created by OVERLORD on 21.07.2021.
//

#ifndef REPPER_YOUNGTABLEAU_H
#define REPPER_YOUNGTABLEAU_H

#include <ostream>
#include "vector"
#include "set"

#include "Permutation.h"

class YoungTableau {
    // TODO:
    //  --
    // DONE:
    //  --
    std::vector<std::vector<int>> tb = {};
public:
    explicit YoungTableau(const Permutation& permutation);

    friend std::ostream &operator<<(std::ostream &os, const YoungTableau &tableau);
};


#endif //REPPER_YOUNGTABLEAU_H
