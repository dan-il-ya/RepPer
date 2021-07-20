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
    if(n < 0) {
        std::cerr << "Error: cannot construct cycle with negative ord.";
        throw std::exception();
    }
    per.clear();
    for(int i = 1;i < n;i++)
        per.push_back(i);
    per.push_back(0);
}

int Permutation::act(int n) const {
    if(n < 0){
        std::cerr << "Error: permutation can not act on negative integers!\n";
        throw std::exception();
    }
    return (per.size() > (uint16_t)n ? per[n] : n);
}

Permutation::Permutation(std::vector<int> per_) {
    if( (std::set<int>(per_.begin(), per_.end()).size() == per_.size()) &&
        (*std::min_element(per_.begin(), per_.end()) == 0) &&
        (*std::max_element(per_.begin(), per_.end()) == (int)per_.size() - 1)){
        per = per_;
    }else{
        std::cerr << "Error: wrong integer collection in permutation constructor.\n";
        throw std::exception();
    }
}

std::ostream &operator<<(std::ostream &os, const Permutation &permutation) {
    os << '[';
    for(auto a = permutation.per.begin();a < (permutation.per.end() - 1);a++)
        os << *a << ',';
    os << *(permutation.per.end() - 1);
    os << ']';
    return os;
}
