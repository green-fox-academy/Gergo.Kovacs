//
// Created by Kovacs család on 2019-01-30.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter(int number= 0);

    void add(int x);
    void add();
    int get();
    void reset();

private:
    int num_;
    int num_start;
};


#endif //COUNTER_COUNTER_H
