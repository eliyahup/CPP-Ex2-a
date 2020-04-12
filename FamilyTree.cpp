#include "FamilyTree.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace family;

node::node()
{
    string name;
    node *father = NULL;
    node *mother= NULL;
}

node::node(string name)
{
    name = name;
    node *father = NULL;
    node *mother= NULL;

}

	 Tree& Tree::addFather(string son,string father){
		  return *this;
	 }
	  Tree& Tree::addMother(string son,string mother){
		  return *this;
	 }
	  string Tree::relation(string relation){
		 return ""; 
	 }
	  string Tree::display(){
		  return "";
		 
	 }
	  string Tree::find(string relation){
		  return "";
	 }
	 	  bool Tree::remove(string name){
		 return true;
	 }




