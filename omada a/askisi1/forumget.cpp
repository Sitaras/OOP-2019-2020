#include <iostream>
#include "forum.h"
using namespace std;

string forum::get_title() const{
  return title;
}

int forum::get_threads() const{
  return threads;
}

/////////////////////////////////////////////////

string thread::get_theme() const{
  return theme;
}

string thread::get_creator() const{
  return creator;
}

date thread::get_x() const{
  return x;
}
int thread::get_numposts() const{
  return numposts;
}

post* thread::get_po_array() const {
  return po_array;
}

/////////////////////////////////////////////////

int post::get_id() const {
  return id;
}

int post::get_num()  {
  return number;
}

date post::get_x() const{
  return x;
}

string post::get_title() const{
  return title;

}
string post::get_creator() const{
  return creator;
}
string post::get_text() const{
  return text;
}
