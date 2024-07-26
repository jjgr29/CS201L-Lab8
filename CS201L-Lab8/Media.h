#pragma once
#include <string>
#include <iostream>
using namespace std;

class Media {

private :
  char type;
  string title;
  string name;
  int rating;
  string genre;
  int length;
  int yearReleased;

public:
  Media();

  /*
  Media (char, string, string, int, string, int, int);
  void setType  (char c);
  void setTitle (string t);
  void setName  (string n);
  void setRating (int r);
  void setGenre(string g);
  void setLength(int l);
  void setYearReleased (int yr);


  char   getType();
  string getTitle();
  string getName();
  int    getRating();
  string getGenre();
  int    getLength();
  int    getYearReleased();

  */
 
};
