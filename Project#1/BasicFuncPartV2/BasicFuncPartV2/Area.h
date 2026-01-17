#ifndef H_area
#define H_area

#include <string>
#include <iostream>

using namespace std;

class Area{
  public:
    void setDescription (string);
    void setGoal(bool);
    void setID(bool);
    string getDescription();
    bool getID();
    bool getGoal();
    void displayArea();
  private:
     string description;
     bool instadeath;
     bool goal;
};

#endif // H_area
