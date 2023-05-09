#include "Database.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Menu{
  public:
  //displays the menu at the start
  void initialize(Database d){
    char c;
    cout << "Welcome to the Song Database!" << endl;
    cout << "----------------------------" << endl << endl;
    cout << "(U)pload a video" << endl;
    cout << "(F)ind a video" << endl;
    cout << "(D)elete a video" << endl;
    cout << "(L)ist all videos" << endl;
    cout << "(Q)uit" << endl << endl;
    cout << "Enter the letter of your choice:" << endl;
    cin >> c;
    c = toupper(c);
    while(c != 'U' && c != 'F' && c!= 'D' && c != 'L' && c!= 'Q'){
      cout << "Please only enter U, F, D, L, or Q" << endl;
      cin >> c;
      c = toupper(c);
    }
    if(c == 'U'){
      upload(d);
    }
    if(c == 'F'){
      search(d);
    }
    if(c == 'L'){
      list(d);
    }
    if(c == 'Q'){
      return;
    }
  };
  void list(Database d){
    char c;
    cout << "List the videos in:" << endl;
    cout << "(A): By title, alphabetical order" << endl;
    cout << "(B): By title, reverse alphabetical order" << endl;
    cout << "(C): By description, alphabetical order" << endl;
    cout << "(D): By description, reverse alphabetical order" << endl;
    cout << "(E): By viewcount, lowest to highest" << endl;
    cout << "(F): By viewcount, highest to lowest" << endl;
    cout << "(G): By date uploaded, earliest to latest" << endl;
    cout << "(H): By date uploaded, latest to earliest" << endl;
    cin >> c;
    //ASCII values fo A - H and a - h
    while((((c < 65 && c> 72) && (c < 97 && c > 104)) && c!= 'r' && c!= 'R') || cin.fail()){
      cin.clear();
      cin.ignore(10000);
      cout << "Please enter a valid character" << endl;
      cin >> c;
    }
    c = toupper(c);
    if(c == 'A'){
      d.list_by_title();
    }
    if(c == 'B'){
      d.rev_list_by_title();
    }
    if(c == 'C'){
      d.list_by_description();
      }
    if(c == 'D'){
      d.rev_list_by_description();
    }
    if(c == 'E'){
      d.list_by_viewcount();
    }
    if(c == 'F'){
      d.rev_list_by_viewcount();
    }
    if(c == 'G'){
      d.list_by_date_uploaded();
    }
    if(c == 'H'){
      d.rev_list_by_date_uploaded();
    }
    if(c == 'R'){
      cout << "Returning to main menu..." << endl;
      initialize(d);
    }
  }
  //add restrictions
  void upload(Database d){
    int date, views;
    string title, description;
    Video v;
    cout << "Enter the title of the video:" << endl;
    cin >> title;
    cout << "Enter the number of views:" << endl;
    cin >> views;
    while(views < 0 || cin.fail()){
      cin.clear();
      cout << "Number of views must be positive. Please enter the number of views again:" << endl;
      cin >> views;
    }
    cout << "Enter the description:" << endl;
    cin >> description;
    cout << "Enter the date uploaded, in yymmdd format:" << endl;
    cin >> date;
    //earliest YouTube video was uploaded on April 23rd, 2005
    while(date < 050423){
      cin.clear();
      cin.ignore(10000);
      cout << "Please enter a valid date, using yymmdd format:" << endl;
      cin >> date;
    }
    v.set_date_uploaded(date);
    v.set_description(description);
    v.set_title(title);
    v.set_viewcount(views);
    d.upload(v);
  }
  void search(Database d){
    char input;
    cout << "Choose your method of searching:" << endl << endl;
    cout << "(A): Search by exact title" << endl;
    cout << "(B): Search by substring of the title" << endl;
    cout << "(C): Search by exact description" << endl;
    cout << "(D): Search by substring of the description" << endl;
    cout << "(E): Search by range of dates" << endl;
    cout << "(F): Search by exact viewcount" << endl;
    cin >> input;
    while(cin.fail() || ((input < 65 || input > 70) 
      && (input < 97 || input > 102))){
      cout << "Please enter a valid character:" << endl;
        }
    input = toupper(input);
    if(input == 'A'){
      cout << "Enter title to search:" << endl;
      string str;
      cin >> str;
      cout << "List of videos titled \"" << str << "\":";
      d.search_by_exact_title(str);
    }
    if(input == 'B'){
      cout << "Enter substring (of title) to search:" << endl;
    }
    if(input == 'C'){
      string str;
      cout << "Enter description to search:" << endl;
    }
    if(input == 'D'){
      string str;
      cout << "Enter substring (of description) to search:" << endl;
      cin >> str;
    }
    if(input == 'E'){
      int date1, date2;
      cout << "Enter start date:" << endl;
      while(date1 < 050423 || date1/1000 > 22 
      || date1%100 > 31 || date1%100 == 0 
      || ((date1 / 100) % 100) < 0 || ((date1 / 100) % 100) > 31
      || cin.fail()){
      cin.clear();
      cout << "Please enter a valid date, using yy/mm/dd format:" << endl;
      cin >> date1;
        }
      cout << "Enter end date:" << endl;
      while(date2 < 050423 || date2/1000 > 22 
      || date2%100 > 31 || date2%100 == 0 
      || ((date2 / 100) % 100) < 0 || ((date2 / 100) % 100) > 31
      || cin.fail()){
      cin.clear();
      cout << "Please enter a valid date, using yy/mm/dd format:" << endl;
      cin >> date2;
        }
      d.search_by_range_date(date1, date2);
    }
    if(input == 'F'){
      int input;
      cout << "Enter the date you want to search:" << endl;
      cin >> input;
      if(cin.fail() || input < 0){
        cout << "Please enter a valid viewcount." << endl;
        cin.clear();
        cin >> input;
      }
      d.search_by_exact_viewcount(input);
    }
    
  }
  void delete_video(Database d){
    char input;
    cout << "How do you want to find videos to delete?" << endl << endl;
    cout << "(A): Delete by exact title" << endl;
    cout << "(B): Delete by substring of title" << endl;
    cout << "(C): Delete by exact description" << endl;
    cout << "(D): Delete by substring of description" << endl;
    cout << "(E): Delete by exact date" << endl;
    cout << "(F): Delete by exact viewcount" << endl;
    cout << "(R): Return to main menu" << endl;
    cin >> input;
    if(cin.fail() || (((input < 65 || input > 70) 
      && (input < 97 || input > 102)) && input != 'R' && input != 'r')){
        cin.clear();
        cout << "Please enter a valid character:" << endl;
        cin >> input;
      }  
    input = toupper(input);
    if(input == 'A'){
        string title;
        char confirmation;
        cout << "Enter title to be deleted";
        cin >> title;
        cout << "Are you sure you want to delete \"" << title << "\"?" << endl;
        cout << "Enter Y to confirm, all other characters to cancel." << endl;
        cin >> confirmation;
        if(confirmation == 'Y' || confirmation == 'y'){
          d.delete_exact_title(title);
        }
    }
    if(input == 'B'){
      string subtitle;
      char confirmation;
      cout << "Enter substring of title to be deleted";
      cin >> subtitle;
      cout << "Are you sure you want to delete titles containing " << subtitle << "?" << endl;
      cout << "Enter Y to confirm, all other characters to cancel." << endl;
      cin >> confirmation;
      if(confirmation == 'Y' || confirmation == 'y'){
        d.delete_sub_title(subtitle);
      }
    }
    if(input == 'C'){
      string description;
      char confirmation;
      cout << "Enter description of video to be deleted";
      cin >> description;
      cout << "Are you sure you want to delete the video with description" << description << "?" << endl;
      cout << "Enter Y to confirm, all other characters to cancel." << endl;
      cin >> confirmation;
      if(confirmation == 'Y' || confirmation == 'y'){
        d.delete_exact_description(description);
      }
    }
    if(input == 'D'){
      string description;
      char confirmation;
      cout << "Enter substring of description to be deleted" << endl;
      cin >> description;
      cout << "Are you sure you want to delete the video with substring of description" << description << "?" << endl;
      cout << "Enter Y to confirm, all other characters to cancel." << endl;
      cin >> confirmation;
      if(confirmation == 'Y' || confirmation == 'y'){
        d.delete_sub_description(description);
      }
    }
    if(input == 'E'){
      int date;
      char confirmation;
      cout << "Enter the date of video to be deleted";
      cin >> date;
      cout << "Are you sure you want to delete the video with date" << date << "?" << endl;
      cout << "Enter Y to confirm, all other characters to cancel." << endl;
      cin >> confirmation;
      if(confirmation == 'Y' || confirmation == 'y'){
        d.delete_exact_date(date);
      }
    }
    if(input == 'F'){
      int viewcount;
      char confirmation;
      cout << "Enter substring of title to be deleted";
      cin >> viewcount;
      cout << "Are you sure you want to delete the video with viewcount" << viewcount << "?" << endl;
      cout << "Enter Y to confirm, all other characters to cancel." << endl;
      cin >> confirmation;
      if(confirmation == 'Y' || confirmation == 'y'){
        d.delete_exact_viewcount(viewcount);
      }
    }
    initialize(d);
    }
};