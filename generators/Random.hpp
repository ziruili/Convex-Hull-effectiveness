#include "../functions.hpp"
vector<point> randomSquare(int x){
  vector<point> rtn;
  for (int i = 0; i < x; i++) {
    rtn.push_back({llrand(),llrand()});
  }
  return rtn;
}
vector<point> randomCircle(int x){
  vector<point> rtn;
  point temp;
  for (int i = 0; i < x; i++) {
    do {
      temp={llrand(),llrand()};
    } while(temp.x*temp.x+temp.y*temp.y>(ll)LIMIT*LIMIT);
    rtn.push_back(temp);
  }
  return rtn;
}
