#include "../functions.hpp"
vector<point> QHhull;
void findhull(point a,point b, vector<point> input){
  if (input.empty()) {
    return;
  }
  point maximum=input[0];
  for (point i:input) {
    if (lineDistance({a,b},i)>lineDistance({a,b},maximum)) {
      maximum=i;
    }
  }
  QHhull.push_back(maximum);
  vector<point> p,q;
  for (point i:input) {
    if (i==maximum) {
      continue;
    }
    if (crossProduct(a,maximum,i)!=crossProduct(a,maximum,b)) {
      p.push_back(i);
    }
    if (crossProduct(b,maximum,i)!=crossProduct(b,maximum,a)) {
      q.push_back(i);
    }
  }
  findhull(a,maximum,p);
  findhull(b,maximum,q);
}
vector<point> quickhull(vector<point> input){
  QHhull.clear();
  point minimum=input[0],maximum=input[0];
  for (point i:input) {
    if (i.x<minimum.x||(i.x==minimum.x&&i.y<minimum.y)) {
      minimum=i;
    }
    if (i.x>maximum.x||(i.x==maximum.x&&i.y>maximum.y)) {
      maximum=i;
    }
  }
  QHhull.push_back(minimum);
  QHhull.push_back(maximum);
  vector<point> a,b;
  for (auto i:input) {
    if (i==minimum||i==maximum) {
      continue;
    }
    if (crossProduct(minimum,maximum,i)) {
      a.push_back(i);
    }
    else{
      b.push_back(i);
    }
  }
  findhull(minimum,maximum,a);
  findhull(minimum,maximum,b);
  return QHhull;
}
