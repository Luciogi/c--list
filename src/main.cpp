#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include "../include/utils.h"
using std::cin;
using std::cout;
using std::endl;
using std::list;

int main(int argc, char *argv[]) {
  // Create struct object
  Entry t;

  // Create list
  list<Entry> l;

  // Enter Data in t
  t.us = "2us2";
  t.pass = "pass2";
  t.web = "google2.com";
  l.push_back(t);

  // Command line arguments 
  // TODO: 
  /* std::string insert
   std::vector<std::string> cmdLineArgs(argv, argv+argc);

    for(auto& arg  : cmdLineArgs)
    {
        
        if(arg == "--menu" || arg == "-m")
        {
          // Call switch function
          welcome();
          std::cout << "menu using switch\n";
        }
        else if (arg == "--insert" || arg == "-i")
        {
            // call get_data()
        }
        else if (arg == "--list" || arg == "-l")
        {
            // call show_list_sr()
        }
        else if (arg == "--sort" || arg == "-s")
        {
            // call sort_list()
        }
        else if (arg == "--delete" || arg == "-d")
        {
            // call delete_entry()
        }
        else if (arg == "--clear" || arg == "-c")
        {
            // call clear_list()
        }
        else if (arg == "--help" || arg == "-help")
        {
            help();
        }
        else
        {
            help();
        }
    }
  */
  welcome();
  START:
  int exp=0;
  cout << "Choose Option: ";
  cout << " 1. Insert \t 2. List \t3. Sort \t4. Delete \t5. Clear all \t0. Exit" << endl;
  cin >> exp;
  switch (exp) {
    case 1:
      get_entry(t,l);
      goto START;
    case 2:
      show_list_sr(l);
       goto START;
    case 3:
      sort_list(l);
       goto START;
    case 4:
    {
       int sr_no=0;
       cout << "Enter Sr.No: ";
       cin >> sr_no;
      delete_entry(l, sr_no-1);
       goto START;
    }
    case 5:
      clear_list(l);
       goto START;
    case 0:
        return 0;
  }
}