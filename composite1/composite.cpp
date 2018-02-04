/*
*	composite.cpp
*	Created by : Channamallikarjun Rolli
*	Mar 9, 2017
*	2:16:30 PM
*/

#include <iostream>
using namespace std;
#include <vector>

//interface
class Component
{
public:
	virtual void play() = 0;// pure virtual function
};

//Leaf class "LegoBrick1X1" that implements interface Component
class LegoBrick1X1 : public Component
{
  public:
    LegoBrick1X1(string val)//Constructor
    {
        color = val;
    }
    void play()
    {
        cout << "A " << color << " Lego 1X1 brick" << endl;
    }
    string color;//declaring the color
};

//Leaf class "LegoBrick1X2" that implements interface Component
class LegoBrick1X2 : public Component
{
  public:
    LegoBrick1X2(string val)//Constructor
    {
        color = val;
    }
    void play()
    {
        cout << "A " << color << " Lego 1X2 brick" << endl;
    }
    string color;
};

//Leaf class "LegoBrick2X2" that implements interface Component
class LegoBrick2X2: public Component
{
  public:
    LegoBrick2X2(string val)//Constructor
    {
        color = val;
    }
    void play()//method
    {
        cout << "A " << color << " Lego 2X2 brick" << endl;
    }
    string color;
};

//Leaf class "LegoFigure" that implements interface Component
class LegoFigure : public Component
{
  public:
    LegoFigure(string val)//Constructor
    {
        occupation = val;
    }
    void play()//method
    {
        cout << "A " << occupation << " Lego figure." << endl;
    }
    string occupation;
};

//Composite Class
class LegoProduct : public Component
{
	vector <Component *> children;
	string name;
	public :
    LegoProduct(string val)//Constructor
    {
        name = val;
    }

	void add(Component *ele)//add method
	{
		children.push_back(ele);
	}
	void play()//method
	{
		cout << "A Lego " << name <<" that contains" << endl;
		for(int i=0;i<children.size();i++)
		{
			children[i]->play();
		}
	}
};
int main()
{
	  LegoBrick1X1 brick1("red");//brick1 contains red color
	  LegoBrick1X2 brick2("yellow");//brick2 contains yellow color
	  LegoBrick2X2 brick3("blue");// brick3 contains blue color
	  LegoBrick2X2 brick4("green");//brick4 contains green color

	  LegoFigure figure1("prince");//figure1 contains prince
	  LegoFigure figure2("princess");//figure2 contains princess
	  LegoFigure figure3("knight");// figure3 contains knight

	  LegoProduct product1("castle");//product1 contains castle
	  LegoProduct product2("kindom");//product2 contians kingdom

	  product1.add(&brick1);
	  product1.add(&brick2);
	  product1.add(&brick3);
	  product1.add(&brick4);

	  product2.add(&figure1);
	  product2.add(&figure2);
	  product2.add(&figure3);
	  product2.add(&product1);
	  product2.play();

return 1;
}
