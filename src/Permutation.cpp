//
// Created by OVERLORD on 20.07.2021.
//

#include "../include/Permutation.h"
#include "exception"

Permutation::Permutation() {
    per.clear();
    per.push_back(0);
}

Permutation::Permutation(int n) {
    per.clear();
    for(int i = 1;i < n;i++)
        per.push_back(i);
    per.push_back(0);
}

int Permutation::act(int n) const {
    if(n < 0)
        throw "Error: permutation can not act on negative integers!";
    return (per.size() > (uint16_t)n ? per[n] : n);
}

Permutation::Permutation(std::vector<int> per_) {
    if(std::set<int>(per_.begin(), per_.end()).size() == per_.size()){
        per = per_;
    }else{
        std::cerr << "AAAAA!!!!!\n";
        throw std::exception();
    }
}
