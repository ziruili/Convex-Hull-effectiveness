#include <bits/stdc++.h>
#include "programs.hpp"
using namespace std;
using namespace std::chrono;
#define ll long long
#define f first
#define s second
#define algorithm monotoneChain
#define randomPoints randomSquare
void calculate(int x,int y){
  vector<vector<point>> vals;
  for (int i = 0; i < 10; i++) {
    if (y) {
      vals.push_back(setOutput(x,y));
    }
    else{
      vals.push_back(randomPoints(x));
    }
  }
  if (y) {
    cout<<x<<','<<y<<':'<<endl;
  }
  else{
    cout<<x<<':'<<endl;
  }
  auto start=high_resolution_clock::now();
  for(auto i:vals){
    cout<<algorithm(i).size()<<endl;
    //algorithm(i);
  }
  auto stop=high_resolution_clock::now();
  cout<<"time: "<<duration_cast<microseconds>(stop - start).count()/10<<endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  srand((unsigned int)time(NULL));
  cout<<setprecision(20);
  for (int i = 10; i <= 100; i+=10) {
    calculate(10000,i);
  }
  return 0;
}
