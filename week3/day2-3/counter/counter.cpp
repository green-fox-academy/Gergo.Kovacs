//
// Created by Kovacs család on 2019-01-30.
//

#include "counter.h"
#include <istream>


Counter::Counter(int number) {
   num_=number;
   num_start=number;
    }
    void Counter::add(int x) {
        num_=num_+x;
    }
    void Counter::add() {
        num_=num_+1;
    }
    int  Counter::get(){
        return num_;
    }
    void Counter::reset() {
        num_=num_start;
    }




