#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("test eli family") {
    family::Tree T ("eli"); 
	T.addFather("eli", "avi")   
	 .addMother("eli", "sima")   
	 .addFather("avi", "hanan")
	 .addMother("avi", "rachel")
	 .addFather("sima", "avraham")
	 .addMother("sima", "soltana")   
	 .addFather("avraham", "beber")
	 .addMother("avraham", "malca")
	 .addFather("soltana", "macluf")
	 .addMother("soltana", "mor")   
	 .addFather("rachel", "david")
	 .addMother("rachel", "merav")
	 .addFather("hanan", "ben")
	 .addMother("hanan", "lee");

	T.display();                     
 
     CHECK(T.relation("xyz") == ("unrelated"));
     CHECK(T.relation("eli") == ("me"));
     CHECK(T.relation("sima") == ("mother")); 
     CHECK(T.relation("avi") == ("father"));
     CHECK(T.relation("hanan") == ("grandfather"));
     CHECK(T.relation("rachel") == ("grandmother"));
     CHECK(T.relation("avraham") == ("grandfather"));
     CHECK(T.relation("soltana") == ("grandmother"));
	 CHECK(T.relation("beber") == ("great-grandfather")); 
     CHECK(T.relation("malca") == ("great-grandmother"));
     CHECK(T.relation("macluf") == ("great-grandfather"));
     CHECK(T.relation("mor") == ("great-grandmother"));
     CHECK(T.relation("david") == ("great-grandfather"));
     CHECK(T.relation("merav") == ("great-grandmother"));
	 CHECK(T.relation("ben") == ("great-grandfather"));
     CHECK(T.relation("lee") == ("great-grandmother"));

     
	 CHECK(T.find("xyz") == ("unrelated"));
     CHECK(T.find("me") == ("eli"));
     CHECK(T.find("mother") == ("sima"));
     CHECK(T.find("father") == ("avi"));
	 CHECK((T.find("grandfather") == ("hanan")||T.find("grandfather") == ("avraham")));
     CHECK((T.find("grandmother") == ("rachel")||T.find("grandmother")==("soltana")));
	 CHECK((T.find("great-grandfather") == ("beber")||T.find("great-grandfather") == ("macluf")||T.find("great-grandfather") == ("david")||T.find("great-grandfather") == ("ben")));
     CHECK((T.find("great-grandmother") == ("malca")||T.find("great-grandfather") == ("mor")||T.find("great-grandfather") == ("merav")||T.find("great-grandfather") == ("lee")));

	 

    T.remove("avi"); 
	T.remove("sima");
	 CHECK(T.relation("sima") == ("unrelated")); 
     CHECK(T.relation("avi") == ("unrelated"));
     CHECK(T.relation("hanan") == ("unrelated"));
     CHECK(T.relation("rachel") == ("unrelated"));
     CHECK(T.relation("avraham") == ("unrelated"));
     CHECK(T.relation("soltana") == ("unrelated"));
	 CHECK(T.relation("beber") == ("unrelated")); 
     CHECK(T.relation("malca") == ("unrelated"));
     CHECK(T.relation("macluf") == ("unrelated"));
     CHECK(T.relation("mor") == ("unrelated"));
     CHECK(T.relation("david") == ("unrelated"));
     CHECK(T.relation("merav") == ("unrelated"));
	 CHECK(T.relation("ben") == ("unrelated"));
     CHECK(T.relation("lee") == ("unrelated"));

	 T.addFather("eli", "avi")   
	 .addMother("eli", "sima")   
	 .addFather("avi", "hanan")
	 .addMother("avi", "rachel")
	 .addFather("sima", "avraham")
	 .addMother("sima", "soltana")   
	 .addFather("avraham", "beber")
	 .addMother("avraham", "malca")
	 .addFather("soltana", "macluf")
	 .addMother("soltana", "mor")   
	 .addFather("rachel", "david")
	 .addMother("rachel", "merav")
	 .addFather("hanan", "ben")
	 .addMother("hanan", "lee");

	 CHECK(T.relation("xyz") == ("unrelated"));
     CHECK(T.relation("eli") == ("me"));
     CHECK(T.relation("sima") == ("mother")); 
     CHECK(T.relation("avi") == ("father"));
     CHECK(T.relation("hanan") == ("grandfather"));
     CHECK(T.relation("rachel") == ("grandmother"));
     CHECK(T.relation("avraham") == ("grandfather"));
     CHECK(T.relation("soltana") == ("grandmother"));
	 CHECK(T.relation("beber") == ("great-grandfather")); 
     CHECK(T.relation("malca") == ("great-grandmother"));
     CHECK(T.relation("macluf") == ("great-grandfather"));
     CHECK(T.relation("mor") == ("great-grandmother"));
     CHECK(T.relation("david") == ("great-grandfather"));
     CHECK(T.relation("merav") == ("great-grandmother"));
	 CHECK(T.relation("ben") == ("great-grandfather"));
     CHECK(T.relation("lee") == ("great-grandmother"));


	 CHECK(T.relation("xyz") == ("unrelated"));
     CHECK(T.relation(" ") == ("unrelated"));
     CHECK(T.relation("zzzzz") == ("unrelated")); 
     CHECK(T.relation("   avi") == ("unrelated"));
     CHECK(T.relation("ha nan") == ("unrelated"));
     CHECK(T.relation("rac hel") == ("unrelated"));
	 CHECK(T.relation(" avi") == ("unrelated"));
     CHECK(T.relation("avi ") == ("unrelated"));
  


     CHECK(T.find("xyz") == ("unrelated"));
     CHECK(T.find("me") == ("eli"));
     CHECK(T.find("mother") == ("sima"));
     CHECK(T.find("father") == ("avi"));
	 CHECK((T.find("grandfather") == ("hanan")||T.find("grandfather") == ("avraham")));
     CHECK((T.find("grandmother") == ("rachel")||T.find("grandmother")==("soltana")));
	 CHECK((T.find("great-grandfather") == ("beber")||T.find("great-grandfather") == ("macluf")||T.find("great-grandfather") == ("david")||T.find("great-grandfather") == ("ben")));
     CHECK((T.find("great-grandmother") == ("malca")||T.find("great-grandfather") == ("mor")||T.find("great-grandfather") == ("merav")||T.find("great-grandfather") == ("lee")));


	CHECK_THROWS(T.remove("eil"));
	CHECK_THROWS(T.find("uncle"));
	CHECK_THROWS(T.find(""));
	CHECK_THROWS(T.find(" "));
	CHECK_THROWS(T.find("xyz"));
	CHECK_THROWS(T.relation("uncle"));
	CHECK_THROWS(T.relation(""));
	CHECK_THROWS(T.relation(" "));
	CHECK_THROWS(T.relation("xyz"));
	 
}



TEST_CASE("test like demo") {
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

	T.display();                        // displays the tree in a human-friendly format.

	cout << T.relation("Yaakov") << endl;  // prints "father"
	cout << T.relation("Rachel") << endl;  // prints "mother"
	cout << T.relation("Rivka") << endl;  // prints "grandmother"
	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
	cout << T.relation("xyz") << endl;  // prints "unrelated"
	cout << T.relation("Yosef") << endl;  // prints "me"

	cout << T.find("mother") << endl;  // prints "Rachel"
	cout << T.find("great-great-grandfather") << endl;  // prints "Terah"
	try {
		cout << T.find("uncle") << endl;  // throws an exception
	} catch (const exception& ex) {
	 	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
	}

	
	cout << T.relation("Terah") << endl;  // prints "unrelated"

     CHECK(T.relation("Yaakov") == ("father")); 
     CHECK(T.relation("Rachel") == ("mother"));
     CHECK(T.relation("Rivka") == ("grandmother"));
     CHECK(T.relation("Avraham") == ("great-grandfather"));
     CHECK(T.relation("Terah") == ("great-great-grandfather"));
     CHECK(T.relation("xyz") == ("unrelated"));
     CHECK(T.relation("Yosef") == ("me"));
     CHECK(T.relation("Isaac") == ("grandfather"));


     CHECK(T.find("mother") == ("Rachel"));
     CHECK(T.find("great-great-grandfather") == ("Terah"));

    T.remove("Avraham"); // removes Avraham and Terah

     CHECK(T.relation("Avraham") == ("unrelated"));
     CHECK(T.relation("Terah") == ("unrelated"));

   T.addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");

     CHECK(T.relation("Avraham") == ("great-grandfather"));
     CHECK(T.relation("Terah") == ("great-great-grandfather"));

	CHECK_THROWS(T.remove("Yosef"));
	CHECK_THROWS(T.find("uncle"));
	CHECK_THROWS(T.find(""));
	CHECK_THROWS(T.find(" "));
	CHECK_THROWS(T.find("xyz"));
	CHECK_THROWS(T.relation("uncle"));
	CHECK_THROWS(T.relation(""));
	CHECK_THROWS(T.relation(" "));
	CHECK_THROWS(T.relation("xyz"));
	 
}