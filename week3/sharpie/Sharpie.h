//
// Created by Kovacs család on 2019-01-29.
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>
class Sharpie{
public:
    Sharpie(std::string color_, float width_);



    void use ();


private:
    std::string color;
    float width, inkAmount;
};


#endif //SHARPIE_SHARPIE_H
//class Sharpie{
//public:
//    Sharpie(std::string color,float width,float inkAmount){
//
//    inkAmount=100;
//
//    }
//private:
//    std::string color;
//    float width;
//    float inkAmount;
//
//};