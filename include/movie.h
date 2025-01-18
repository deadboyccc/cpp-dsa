#pragma once
#include <iostream>
#include <string>
class movie {
 public:
  std::string title;
  int watched;
  movie(std::string title, int watched) {
    this->title = title;
    this->watched = watched;
  }
  std::string getTitle() const { return title; }
  void setTitle(std::string title) { this->title = title; }
  int getWatched() const { return watched; }
  void setWatched(int watched) { this->watched = watched; }
  ~movie() {}
};