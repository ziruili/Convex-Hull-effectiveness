#include "../functions.hpp"
vector<point> setOutput(int x,int y){
  vector<point> rtn;
  //cout<<pi<<endl;
  for (int i = 0; i < y; i++) {
    ldouble angle=(2*i*pi/y);
    rtn.push_back({(ll)(sin(angle)*LIMIT),(ll)(cos(angle)*LIMIT)});
  }
  ll radius=(ll)(sin(pi/(ldouble)y)*LIMIT);
  //cout<<radius<<endl;
  point temp;
  for (int i = 0; i < x-y; i++) {
    do {
      temp={llrand(),llrand()};
    } while(temp.x*temp.x+temp.y*temp.y>=radius*radius);
    rtn.push_back(temp);
  }
  //cout<<"finished"<<endl;
  return rtn;
}
