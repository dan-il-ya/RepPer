//
// Created by OVERLORD on 21.07.2021.
//

#include "../include/YoungTableau.h"

YoungTableau::YoungTableau(const Permutation& permutation) {
    tb.clear();

    std::set<int> s;
    for(int i = 0; i < permutation.proper_num(); i++)
        s.insert(i);

    for(auto el : s){
        std::vector<int> v_;
        v_.clear();
        int el_ = el;

        el = permutation.act(el);
        v_.push_back(el);
        while(el_ != el)
            s.erase(el),
            el = permutation.act(el),
            v_.push_back(el);

        tb.push_back(v_);
    }

    for(auto &cyc : tb){
        auto min = std::min_element(cyc.begin(), cyc.end());
        if(min != cyc.begin()){
            std::vector<int> cyc_(min,cyc.end());
            cyc_.insert(cyc_.end(),cyc.begin(), min);
            cyc = cyc_;
        }
    }

    auto cmp = [](std::vector<int> first, std::vector<int> second)->bool{
        if(first.size() > second.size()) return true;
        else if((first.size() == second.size()) and (!first.empty()))
            if(first[0] > second[0]) return true;
        return false;
    };
    std::sort(tb.begin(), tb.end(), cmp);
}

std::ostream &operator<<(std::ostream &os, const YoungTableau &tableau) {
    for(auto &s : tableau.tb){
        os << '(';
        if(s.size() == 1){
            os << s[0];
        } else {
            for(auto it = s.begin(); it != (s.end() - 1); it++)
                os << *it << ' ';
            os << *(s.end() - 1);
        }
        os << ')';
    }
    return os;
}
