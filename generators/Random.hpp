#include "../functions.hpp"
vector<point> randomPoints(int x){
  vector<point> rtn;
  for (int i = 0; i < x; i++) {
    rtn.push_back({llrand(),llrand()});
  }
  return rtn;
}
