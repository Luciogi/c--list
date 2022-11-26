#include "../include/utils.h"
#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::list;

void show_list(list<Entry> &lst) {
  for (std::list<Entry>::iterator it = lst.begin(); it != lst.end(); it++) {
    cout << "__________________________________________________________\n";
    cout << "| username: " << it->us << " | password: " << it->pass
         << " | website: " << it->web << std::endl;
    cout << "----------------------------------------------------------\n";
  }
}

void show_list_sr(list<Entry> &lst) {
  int i = 0;
  list<Entry>::iterator it = lst.begin();
  while (i < lst.size() && it != lst.end()) {
    cout
        << "__________________________________________________________________"
           "____________________________________________________________________\n";
    cout << " Sr.No:" << i + 1 << " | username: " << it->us
              << " | password: " << it->pass << " | website: " << it->web
              << std::endl;
    cout << "-------------------------------------------------------------------"
            "-------------------------------------------------------------------\n";
    i++;
    it++;
  }
}

void get_entry(Entry &T,
               list<Entry> &lst) { // take list as input (referenced)
  // FIXME: Add for loop which takes as perameter number of iterations
  cout << "Enter Data[Username, Password, Website]: ";
  cin >> T.us >> T.pass >> T.web;
  lst.push_back(T);
}

void delete_entry(list<Entry> &lst, int entryNumber) {
  // initialize iterator for list l
  std::list<Entry>::iterator it;
  it = lst.begin();
  // increment of iterator
  advance(it, entryNumber);
  // Delete
  lst.erase(it);
}

void clear_list(list<Entry> &lst) { lst.clear(); }

bool comp_usrname_nocase(const Entry &s1, const Entry &s2) {
  unsigned int i = 0;
  while ((i < s1.us.length()) && (i < s2.us.length())) {
    if (tolower(s1.us[i]) < tolower(s2.us[i]))
      return true;
    else if (tolower(s1.us[i]) > tolower(s2.us[i]))
      return false;
    i++;
  }
  return (s1.us.length() < s2.us.length());
}

void sort_list(std::list<Entry> &lst) {
  lst.sort(comp_usrname_nocase);
}

void welcome(void) {
 cout << R"(
  ____                                                      _ 
 |  _ \    __ _   ___   ___  __      __   ___    _ __    __| |
 | |_) |  / _` | / __| / __| \ \ /\ / /  / _ \  | '__|  / _` |
 |  __/  | (_| | \__ \ \__ \  \ V  V /  | (_) | | |    | (_| |
 |_|      \__,_| |___/ |___/   \_/\_/    \___/  |_|     \__,_|
                                                              
  __  __                                                 
 |  \/  |   __ _   _ __     __ _    __ _    ___   _ __   
 | |\/| |  / _` | | '_ \   / _` |  / _` |  / _ \ | '__|  
 | |  | | | (_| | | | | | | (_| | | (_| | |  __/ | |     
 |_|  |_|  \__,_| |_| |_|  \__,_|  \__, |  \___| |_|     
                                   |___/                 
 )" << endl;
} 

void help() {
    cout << R"( 
  Usage:
        -m   Run in Menu mode
        -i   Insert password entry
        -l   Show list of entries
        -s   Sort entries (according to usernames)
        -d   Delete entry
        -c   Clear all entries
        -h   Display this page
    )" << endl;
}