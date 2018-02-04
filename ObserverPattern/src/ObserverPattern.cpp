//============================================================================
// Name        : observer.cpp
// Author      : Channamallikarjun ROlli
// Version     :
// Copyright   : Your copyright notice
// Description : Observer pattern in C++
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Observer {
  public:
    virtual void update(string s) = 0;// pure virtual function
};

class People: public Observer
{
  public:
    People(string s) {
        name = s;
    }
    void update(string s) {
        action(s);
    }
    void action(string s)
    {
        cout << name << " is running away from a " << s << endl;
    }
  protected:
    string name;
};

class Organization: public Observer
{
  public:
    Organization(string s) {
        name = s;
    }
    void update(string s) {
        action(s);
    }
    void action(string s)
    {
        cout << name << " is paying attention on a " << s << endl;
    }
  protected:
    string name;
};

class Subject {
    // 1. "independent" functionality
    public:
    vector < class Observer * > views; // A Collection to keep track of all Registered Observers
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    virtual void notify() = 0; // Making this virtual void as notify for each subject is unique.
};

class FireDept: public Subject
{
    string location;
  public:
    void setAlarm(string locat)
    {
        location = locat;
        notify();//notify method is called
    }

    void notify() {
      // 5. Publisher broadcasts
      for (int i = 0; i < views.size(); i++)
        views[i]->update("fire alarm near " + location);//at runtime it calls the particular class
    }
};

class PoliceDept: public Subject
{
    string location;
  public:
    void setAlarm(string locat)
    {
        location = locat;
        notify();//notify method is called
    }

    void notify() {
      // 5. Publisher broadcasts
      for (int i = 0; i < views.size(); i++)
        views[i]->update("attack alarm near " + location);//at runtime it calls the particular class
    }
};

int main()
{
  FireDept dept1;// FireDept object
  PoliceDept dept2; // PoliceDept object
  People subscriber1("Sam"); //People object for Sam
  dept1.attach(&subscriber1); //People object named "Sam" is subscribes to the FireDept.
  People subscriber2("Mary"); //People object for Mary
  dept2.attach(&subscriber2);//People object named "Mary" is subscribes to the PoliceDept
  Organization subscriber3("UCLA");// Organization for UCLA
  dept1.attach(&subscriber3);// subscribing the Organization object to FireDept
  dept2.attach(&subscriber3);// subscribing the Organization object to PoliceDept
  dept1.setAlarm("San Diego");//calling the FireDept alarm
  dept2.setAlarm("Irvine");//calling the PoliceDept alarm.
}
