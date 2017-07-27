#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Solve(vector<int> );

bool Rotate(vector<int> &, int );


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
  int questions;
  cin >> questions;

    
  for (int j = 0; j < questions; j++) {
    int n;
    cin >> n;
    //cout << endl;
    vector<int> num;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      num.push_back(temp);
    }
      
    bool ans = Solve(num);
    if (ans == true) {
      cout << "YES" << endl;
    }
    else if (ans == false) {
      cout << "NO" << endl;
    }
  }
  
  
  return 0;
}


bool Solve(vector<int> d)
{   
 while (d.size() > 0) {
    
     // Find lowest value in array.
    int max = 9999;
    int max_i = -1;
    for (int j = 0; j < d.size(); j++) {
      if (d[j] < max) {
        max = d[j];
        max_i = j;
        //cout << "New Min i is " << max << endl;
      }
    }
    
    //cout << "min i is " << max_i << " and number " << max << endl;
    while (max_i > 0) {
      bool status;
      if (max_i == d.size()-1) {
        status = Rotate(d, max_i-1);
      } else {
        status = Rotate(d, max_i);
      }
      if (status == false) {
        //cout << "Failed Rotate" << endl << endl;
        return false;
      } else {
          max_i -= 1;
          //cout << "min i is " << max_i << endl;
      }
    }
    //cout << "Rotated array so min i is now " << max_i << endl;
    // Sanity check. If not needed.
    if (max_i == 0) {
      d.erase(d.begin());
      //cout << "Erased min i " << endl;
    }
  }
  return true;
}


// Used to rotate selection where i is the middle.
bool Rotate(vector<int> &d, int i)
{
  if ( (i+1 < d.size()) && (i-1 >= 0)) {
    int temp0 = d[i-1];
    d[i-1] = d[i];
    d[i] = d[i+1];
    d[i+1] = temp0;
      
    return true;
  } else {
    return false;
  } 
}
