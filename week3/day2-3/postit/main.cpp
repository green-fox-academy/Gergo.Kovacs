#include <iostream>



class PostIt{
public:
    void everithing (int bgcolor,std::string txt,int txtcolor) {
        bgcolor = backgroundColor;
        txt = text;
        txtcolor = textColor;
    }


private:
    int backgroundColor;
    std::string text;
    int textColor;

};
    // orange color blue text = Idea1
    //pink color balck text = Awesome
    //yellow color green text Superb!




int main() {

    PostIt GeriObject1;
    GeriObject1.everithing(orange, "Idea1" ,blue );

    PostIt GeriObject2;
    GeriObject1.everithing(pink,"Awesome", black);

    PostIt GeriObject3;
    GeriObject3.everithing(yellow, "Superb!", green);





    return 0;
}