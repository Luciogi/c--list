#pragma once

#include <iostream>
#include <list>
struct Entry {
  std::string us;
  std::string pass;
  std::string web;
};
void show_list(std::list<Entry> &lst);
void show_list_sr(std::list<Entry> &lst);
void get_entry(Entry &T, std::list<Entry> &lst);
void delete_entry(std::list<Entry> &lst, int entryNumber);
void clear_list(std::list<Entry> &lst);
bool comp_usrname_nocase(const Entry &s1, const Entry &s2);
void sort_list(std::list<Entry> &lst);
void welcome();
void help();
