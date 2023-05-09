#include <string>
#include <iostream>
using namespace std;
class Video{
  int date_uploaded;
  int viewcount;
  string title;
  string description;
  public:
  int get_date_uploaded() {
    return date_uploaded;
  } 
  int get_viewcount() {
    return viewcount;
  }
  string get_title() {
    return title;
  }
  string get_description() {
    return description;
  }

  void set_date_uploaded(int date){
    date_uploaded = date;
  }
void set_viewcount(int views){
    viewcount = views;
  }
void set_title(string t){
    title = t;
  }
void set_description(string d){
    description = d;
  }

  void display_record() {
    cout << title << endl << "views: " << viewcount << endl << "date_uploaded: " << date_uploaded;
    cout << endl << "description: " << description << endl << endl;
  }
};

bool compare_description(Video a, Video b) {
  return b.get_description() > a.get_description();
};

bool compare_title(Video a, Video b) {
  return b.get_title() > a.get_title();
};

bool rev_compare_description(Video a, Video b) {
  return a.get_description() > b.get_description();
};

bool rev_compare_title(Video a, Video b) {
  return a.get_title() > b.get_title();
};

bool compare_viewcount(Video a, Video b) {
  return b.get_viewcount() > a.get_viewcount();
};

bool compare_date_uploaded(Video a, Video b) {
  return b.get_date_uploaded() > a.get_date_uploaded();
};

bool rev_compare_viewcount(Video a, Video b) {
  return a.get_viewcount() > b.get_viewcount();
};

bool rev_compare_date_uploaded(Video a, Video b) {
  return a.get_date_uploaded() > b.get_date_uploaded();
};