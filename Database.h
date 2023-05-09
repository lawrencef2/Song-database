#include "Video.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Database{
  vector<Video> videos;
  public:

  void upload_video(int date, int view, string title, string description){
    Video v;
    v.set_date_uploaded(date);
    v.set_viewcount(view);
    v.set_title(title);
    v.set_description(description);
    videos.push_back(v);
  }

  void delete_video(Video v){
    int position;
    for(int i = 0; i < videos.size(); i++){
      if(v.get_date_uploaded() == videos[i].get_date_uploaded()
        && v.get_description() == videos[i].get_description()
        && v.get_title() == videos[i].get_title()
        && v.get_viewcount() == videos[i].get_viewcount()){
        position = i;
        }
    }
    videos.erase(videos.begin() + position);
  } 
  void list_by_description() {
    sort(videos.begin(), videos.end(), compare_description);
    for(Video x : videos) {
      x.display_record();
    }
  }

  void list_by_title() {
    sort(videos.begin(), videos.end(), compare_title);
    for(Video x : videos) {
      x.display_record();
    }
  }

   void rev_list_by_description() {
    sort(videos.begin(), videos.end(), rev_compare_description);
    for(Video x : videos) {
      x.display_record();
    }
  }

   void rev_list_by_title() {
    sort(videos.begin(), videos.end(), rev_compare_title);
    for(Video x : videos) {
      x.display_record();
    }
  }
  void list_by_viewcount() {
    sort(videos.begin(), videos.end(), compare_viewcount);
    for(Video x : videos) {
      x.display_record();
    }
  }

  void list_by_date_uploaded() {
    sort(videos.begin(), videos.end(), compare_date_uploaded);
    for(Video x : videos) {
      x.display_record();
    }
  }

   void rev_list_by_viewcount() {
    sort(videos.begin(), videos.end(), rev_compare_viewcount);
    for(Video x : videos) {
      x.display_record();
    }
  }

   void rev_list_by_date_uploaded() {
    sort(videos.begin(), videos.end(), rev_compare_date_uploaded);
    for(Video x : videos) {
      x.display_record();
    }
  }

void search_by_exact_description(string x) {
  for(Video a : videos) {
    if (x == a.get_description()) a.display_record();
  }
}

void search_by_exact_title(string x) {
  for(Video a : videos) {
    if (x == a.get_title()) a.display_record();
  }
}

void search_by_sub_description(string x) {
  for(Video a : videos) {
    if (a.get_description().find(x) != string::npos) a.display_record();
  }
}

void search_by_sub_title(string x) {
  for(Video a : videos) {
    if (a.get_title().find(x) != string::npos) a.display_record();
  }
}

void search_by_exact_viewcount(int x) {
  for(Video a : videos) {
    if (x == a.get_viewcount()) a.display_record();
  }
}  

void search_by_range_date(int start, int end) {
  for(Video x : videos) {
    if(x.get_date_uploaded() >= start && x.get_date_uploaded() <= end) {
      x.display_record();
    }   
  }
} 


void search_by_range_viewcount(int start, int end) {
  for(Video x : videos) {
    if(x.get_viewcount() >= start && x.get_viewcount() <= end) {
      x.display_record();
    }   
  }
} 

bool delete_exact_title(string x) {
  for(Video a : videos) {
    if (x == a.get_title()) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

bool delete_exact_description(string x) {
  for(Video a : videos) {
    if (x == a.get_description()) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

bool delete_sub_title(string x) {
  for(Video a : videos) {
    if (a.get_title().find(x) != string::npos) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

bool delete_sub_description(string x) {
  for(Video a : videos) {
    if (a.get_description().find(x) != string::npos) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

bool delete_exact_date(int x) {
  for(Video a : videos) {
    if (x == a.get_date_uploaded()) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

bool delete_exact_viewcount(int x) {
  for(Video a : videos) {
    if (x == a.get_viewcount()) {
      delete_video(a);
      return true;
    }
    
  }
  return false;
}

void delete_range_viewcount(int start, int end) {
  for(Video a : videos) {
    if (a.get_viewcount() >= start && a.get_viewcount() <= end) delete_video(a);
  }
}

void delete_range_date(int start, int end) {
  for(Video a : videos) {
    if (a.get_date_uploaded() >= start && a.get_date_uploaded() <= end) delete_video(a);
  }
}




  void save_to_file(){
    ofstream file;
    file.open("database.txt");
    for(Video v : videos){
      file << v.get_date_uploaded() << endl;
      file << v.get_description() << endl;
      file << v.get_title() << endl;
      file << v.get_viewcount() << endl;
      file << endl;
    }
    file.close();
  }
  void upload(Video v){
    videos.push_back(v);
  }
};