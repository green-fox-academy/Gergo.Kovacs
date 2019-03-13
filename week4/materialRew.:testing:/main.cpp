#include <iostream>
#include <>

class PasswordChecker
{
 private:
  int _minCharacters;
  int _maxCharacters;
  int _minNUmbers;
 public:
  PasswordChecker();
  PasswordChecker(int minCharacters, int maxCharacters, int minNUmbers);
};





//testing:Feladat irunk egy osztály megadok neki egy jelszót és ellenőrizze le hogy az jó(biztonsági szempontból)
//Unit test: a lehető legkisebb egységet teszteli.(egy  egy atomi funkciót fog letesztelni)
//Integrációs tesztek: a unit testek összessége amikor kommunikálnak egymássla jól fognak működni.
//System/validasion teszt: végső fázisainál szoktuk használni (mint amikor egy felhasználót engednél oda.
//
//