//
// Created by OVERLORD on 20.07.2021.
//

#include "../include/Permutation.h"
#include "exception"

Permutation::Permutation() {
    per.clear();
}

Permutation::Permutation(int n) {
    if(n < 0) {
        n = -n;
        per.clear();
        per.push_back(n - 1);
        for(int i = 0;i < n - 1;i++)
            per.push_back(i);
    }else if(n > 0){
        per.clear();
        for(int i = 1;i < n;i++)
            per.push_back(i);
        per.push_back(0);

    }
}

int Permutation::act(int n) const {
    if(n < 0){
        std::cerr << "Error: permutation can not act on negative integers!\n";
        throw std::exception();
    }
    return (per.size() > (uint16_t)n ? per[n] : n);
}

Permutation::Permutation(std::vector<int> per_) {
    if( (std::set<int>(per_.begin(), per_.end()).size() == per_.size()) and
        (*std::min_element(per_.begin(), per_.end()) == 0) and
        (*std::max_element(per_.begin(), per_.end()) == (int)per_.size() - 1)){
        per = per_;
    }else{
        std::cerr << "Error: wrong integer collection in permutation constructor.\n";
        throw std::exception();
    }
}

std::ostream &operator<<(std::ostream &os, const Permutation &permutation) {
    os << '[';
    for(auto a = permutation.per.begin(); a < (permutation.per.end() - 1); a++)
        os << *a << ',';
    os << *(permutation.per.end() - 1);
    os << ']';
    return os;
}

int Permutation::num() const {
    return (int)per.size();
}

Permutation Permutation::operator*(const Permutation &permutation) const {
    std::vector<int> v(std::max(proper_num(),permutation.proper_num()));
    for(int i = 0; i < (int)v.size(); i++)
        v[i] = act(permutation.act(i));
    return Permutation(v);
}

int Permutation::proper_num() const {
    int num = this->num();
    if(num == 0)
        return 1;
    while((num > 1) && (act(num - 1) == num - 1))
        num--;
    return num;
}

Permutation& Permutation::operator*=(const Permutation &permutation) {
    return (*this = *this * permutation);
}

bool Permutation::operator==(const Permutation &permutation) const {
    if(proper_num() != permutation.proper_num()){
        return false;
    }
    for(int i = 0; i < proper_num(); i++)
        if(act(i) != permutation.act(i))
            return false;
    return true;
}

bool Permutation::operator!=(const Permutation &permutation) const {
    return !((*this) == permutation);
}

Permutation Permutation::inv() const {
    std::vector<int> v(proper_num());
    for(int i = 0; i < proper_num(); i++)
        v[act(i)] = i;
    return Permutation{v};
}

Permutation Permutation::operator^(int pow) const {
    if(pow < 0)
        return ((*this) ^ (- pow)).inv();
    Permutation p = ID;
    for(int i = 0 ; i < pow ; i++)
        p *= *this;
    return p;
}

Permutation& Permutation::operator^=(int pow){
    return (*this = *this ^ pow);
}

Permutation Permutation::shift(int k) const {
    return (*this) ^ (Permutation(proper_num() + k) ^ k);
}

Permutation Permutation::operator^(const Permutation& permutation) const {
    return permutation * *this * permutation.inv();
}

Permutation &Permutation::operator^=(const Permutation &permutation) {
    return (*this = (*this ^ permutation));
}
