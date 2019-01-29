#include <iostream>


class BlogPost{
public:
    void everything(std::string name_,std::string title_, std::string text_,std::string pdate){
        authorName = name_;
        title = title_;
        text = text_;
        publicationDate = pdate;
    }
    std::string getname_(){
        return authorName;
    }
    std::string gettitle_(){
        return title;
    }
    std::string gettext_(){
        return text;
    }
    std::string getpdate(){
        return publicationDate;
    }
private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;

};

int main() {

    std::string au ="Jhon Doe";
    std::string tit ="Lorem Ipsum";
    std::string tex ="Lorem ipsum dolor sit amet.";
    std::string pub ="2000.05.04";

   BlogPost ob;
   ob.everything(au, tit, tex, pub);

   std::cout<<ob.getname_()<<"\n"<<ob.gettitle_()<<"\n"<<ob.gettext_()<<"\n"<<ob.getpdate()<<std::endl;

   std::cout<<""<<std::endl;

   std::string au1 ="Tim Urban";
   std::string tit1 ="Wait but why";
   std::string tex1 ="A popular long-form, stick-figure-illustrated blog about almost everything.";
   std::string pub1 ="2010.10.10.";

   BlogPost ob1;
   ob1.everything(au1, tit1, tex1, pub1);

   std::cout<<ob1.getname_()<<"\n"<<ob1.gettitle_()<<"\n"<<ob1.gettext_()<<"\n"<<ob1.getpdate()<<std::endl;




    return 0;
}



//Create a few blog post objects:
//"Lorem Ipsum" titled by John Doe posted at "2000.05.04."
//Lorem ipsum dolor sit amet.
//"Wait but why" titled by Tim Urban posted at "2010.10.10."
//A popular long-form, stick-figure-illustrated blog about almost everything.
//"One Engineer Is Trying to Get IBM to Reckon With Trump" titled by William Turton at "2017.03.28."
//Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.