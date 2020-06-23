#include "../functions.hpp"
vector<point> monotoneChain(vector<point> input){
  vector<point> rtn;
  sort(input.begin(),input.end(),[](const point& lhs,const point& rhs){
    return lhs.x<rhs.x||(lhs.x==rhs.x&&lhs.y<rhs.y);
  });
  for (auto i:input) {
    while (rtn.size()>=2&&crossProduct(*rtn.rbegin(),*(++rtn.rbegin()),i)) {
      rtn.pop_back();
    }
    rtn.push_back(i);
  }
  for (auto i = ++input.rbegin(); i != input.rend(); i++) {
    while (rtn.size()>=2&&crossProduct(*rtn.rbegin(),*(++rtn.rbegin()),*i)) {
      rtn.pop_back();
    }
    rtn.push_back(*i);
  }
  rtn.pop_back();
  return rtn;
}
