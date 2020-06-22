#include "../functions.hpp"
list<point> giftWrapping(vector<point> input){
  point newPoint=input[0];
  list<point> rtn;
  for (point i:input) {
    if (i.x<newPoint.x||(i.x==newPoint.x&&i.y<newPoint.y)) {
      newPoint=i;
    }
  }
  rtn.push_back(newPoint);
  //cout<<newPoint<<endl;
  do {
    if (newPoint==input[0]) {
      newPoint=input[1];
    }
    else{
      newPoint=input[0];
    }
    for (point i:input){
      if (i==*rtn.rbegin()) {
        continue;
      }
      if (crossProduct(*rtn.rbegin(),newPoint,i)) {
        newPoint=i;
      }
    }
    rtn.push_back(newPoint);
    //cout<<newPoint<<endl;
  } while(*rtn.begin()!=*rtn.rbegin());
  rtn.pop_back();
  return rtn;
}
