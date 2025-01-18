#pragma once
#include <vector>

#include "movie.h"
class movies {
 public:
  std::vector<movie> list;
  void add_movie(movie m) { list.push_back(m); };
  void print_movies() {
    for (auto &movie : list) {
      std::cout << movie.title << " has been watched " << movie.watched
                << std::endl;
    }
  }
};
