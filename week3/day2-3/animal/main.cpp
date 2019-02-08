#include <iostream>


class Animal{
public:
        Animal(int hunger, int thirst){
        hunger_v = 50;
        thirst_v = 50;
        }

void eat(){
            hunger_v--;
        }
void drink(){

            thirst_v--;
        }
void play(){
            hunger_v++;
            thirst_v++;
        }

private:
    int hunger_v;
    int thirst_v;

};



int main() {

    return 0;
}



//Create an Animal class
//Every animal has a hunger value, which is a whole number
//Every animal has a thirst value, which is a whole number
//when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//Every animal can drink() which decreases their thirst by one
//Every animal can play() which increases both by one