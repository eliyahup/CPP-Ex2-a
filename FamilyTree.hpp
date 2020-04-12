#pragma once 
#include <iostream>
#include <string>


using namespace std;
class node {

    private:
        string name;
        node *father;
        node *mother;

    public:
        node();

        node(string name);

        friend class Tree;

};
namespace family{

     class Tree{
         node *root;
         public:
         Tree(string san){
         root = new node(san);
         }
        Tree& addFather(string son,string father);
        Tree& addMother(string son,string mother);
        string relation(string relation);
        string display();
        string find(string relation);
        bool remove(string name);
     };

    
}








