//
// Created by Kovacs család on 2019-01-29.
//

#include "Sharpie.h"
#include <iostream>
#include <string>

Sharpie::Sharpie(std::string color_, float width_){
color=color_;
width= width_;
inkAmount=100;
}

void Sharpie::use (){
    inkAmount--;
}
