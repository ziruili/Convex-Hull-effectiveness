#include "../functions.hpp"
list<point> grahamScan(vector<point> input){
  auto firstPoint=input.begin();
  list<point> rtn;
  for (auto i=input.begin();i!=input.end();i++) {
    if (i->x<firstPoint->x||(i->x==firstPoint->x&&i->y<firstPoint->y)) {
      firstPoint=i;
    }
  }
  point firstPointval=*firstPoint;
  input.erase(firstPoint);
  rtn.push_back(firstPointval);
  sort(input.begin(),input.end(),[firstPointval](const point& lhs, const point& rhs){
    return crossProduct(firstPointval,lhs,rhs);
  });
  for (auto i:input) {
    while (rtn.size()>=2&&crossProduct(*rtn.rbegin(),*(++rtn.rbegin()),i)) {
      rtn.pop_back();
    }
    rtn.push_back(i);
  }
  return rtn;
}
