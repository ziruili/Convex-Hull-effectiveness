#pragma once
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define LIMIT 1000000000
#define ldouble long double
const ldouble pi=acos(-1L);
struct point{
  ll x,y;
};
//keep x,y<=LIMIT
bool operator==(point a,point b){
  return a.x==b.x&&a.y==b.y;
}
bool operator!=(point a,point b){
  return !(a==b);//Hope this works
}
struct line{
  point a,b;
};
bool crossProduct(point a,point b,point c){//finds clockwise/counterclockwise of bac
  //true if clockwise
  return ((a.y-b.y)*(c.x-a.x)-
    (a.x-b.x)*(c.y-a.y))>0;
}
//My brain hurts, I hope the points being collinear doesn't fuck something up
//Is it larger or  smaller than 0? Does it even matter?
ll llrand(){
  return rand()%2?(rand()%LIMIT):(-(rand()%LIMIT));
}//I know this can't get to LIMIT, but I don't care
