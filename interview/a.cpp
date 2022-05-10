/*
Autox.ai coding test.

Problem 1: Simulate where car will go when given an input.

Problem 2: Design a controller to have it follow said path.

Problem 3: Design a controller to have car go from A to B where
A = 0, 0, PI/2
B = X, 0, PI/2

d(x) = v0 * cos(theta)
d(y) = v0 * sin(theta)
d(theta) = v0 * tan(u)/L

L = 2
v0 = 1
u = [-0.5, 0.5]

*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

#define PI 3.1415926


// Car configuration
struct Configuration{
  double x;
  double y;
  double theta; // heading angle of the car; theta=0 if the car heads towards x axis and PI/2 if the car heads towards y axis.
};

// Problem 1
// Input: an initial configuration of the car
// Input: total time
// Output: final configuration
// Output: a path
vector<Configuration> GenPath(const Configuration init, double T, Configuration &final, double u = -0.3){
  vector<Configuration> out;
  Configuration state = init;
  double L = 2.0; // m
  double v0 = 1.0; // m/s
  out.push_back(state);
  double dt = 0.01; // s
  for (double t = 0.0; t <= T; t += dt) {
      state.theta += v0*tan(u)/L * dt;
      state.x += v0 * cos(state.theta) * dt;
      state.y += v0 * sin(state.theta) * dt;
      state.theta = fmod(state.theta, 2*PI);
      out.push_back(state);
  }
  final = state;

  return out;
}

// Problem 2
// Input: reference path. To test your implementation, you can use problem #1's solution to generate reference paths
// Input: an initial configuration
// Output: u: a sequence of control
void Tracking(const vector<Configuration> &reference_path, const Configuration &init_conf, vector<double> &u)
{
  // Simulation settings.
  double dt = 0.1;
  double L = 2; // m
  double v0 = 1; // m/s

  /* Start with simple P controller on car heading
   just so I can move to next problem.
   Even the simple P controller with works well since
   all parameters are known to calculate an ideal kp.
   Tan(x) when x is small is approx = x. So knowing current
   speeed along with L and dt you can calculate kp.
   This is only possible because there is no dynamics when
   steering.
  */
  double kp = 20.0;
  double e = 0; // error.
  double controller_output = 0;

  Configuration state = init_conf;
  // + u == + theta (careful around 2pi, nonlinear)

  for (int i = 1; i < reference_path.size(); i++) {
      // Run reference path at 10x speed of controller just to make things
      // a bit more realistic.
      if ((i % 10) != 0) continue;

      e = reference_path[i].theta - state.theta;
      controller_output = e * kp;

      // limits
      if (controller_output > 0.5) controller_output = 0.5;
      if (controller_output < -0.5) controller_output = -0.5;
      u.push_back(controller_output);

      state.theta += v0*tan(controller_output)/L * dt;
      state.x += v0 * cos(state.theta) * dt;
      state.y += v0 * sin(state.theta) * dt;
      if ((i % 1) != 0 ) continue;
      //cout << "ref   " << reference_path[i].x << " " << reference_path[i].y << " " << reference_path[i].theta << endl;
      //cout << "state " << state.x << " " << state.y << " "<< state.theta <<" "<<controller_output<< endl << endl;
  }

  //cout << "final state " << state.x << " " << state.y << " "<< state.theta << endl << endl;
  return;
}

// Problem 3
void ReachTarget(const double x, vector<double> &u)
{
  /* This is where things get interesting. I can either use my P control to follow a generated
  reference path (some sort of jerk minimization trajectory or hybrid A*).
  Or I can do both things at once by doing everything in an MPC.
  Normally I'd want to do everything in an MPC but the only solver I'm used to CppAD isn't supported by Hackerrank.
  Even if it was I wouldn't feel comfortable implementing MPC or hybrid A* from scratch in less than 4 hours without copying
  a large amount of code I've already written.

  I'm going to implement a FSM that will move through a number of preplanned states inorder to get the car to final
  destination. Won't be pretty or automatic but it will atleast work for 100. Won't work for the really close ones since
  you can't just follow the preplanned routes.
  */

  Configuration A, B;
  A.x = 0, A.y = 0, A.theta = PI/2;
  B.x = x, B.y = 0, B.theta = PI/2;

  Configuration state = A;
  double controller_output = 0;
  double e = 0;
  double kp = 5.0;
  double kd = 0;
  double prev_e = 0;

  double dt = 0.1; // s
  double v0 = 1; // m/s
  double L = 2; // m
  double r = 0; // Reference
  int i = 0;

  bool close = false;
  if (B.x < 15) close = true;

  for (double t = 0.1; t < 100; t += dt) {
      // Stop the car.
      if (abs(B.y - state.y) < 0.1 && abs(B.x - state.x) < 0.5) {
          cout << "state " << state.x << " " << state.y << " "<< state.theta;
          cout <<" "<<controller_output<<" t: "<< t << endl << endl;
          break;
      }


      // Change states x not close.
      // Path is to U turn to get below the ending point then turn upwards into it.
      // Only works for positive x.
      if (state.y >= 0) {
          // U turn state.
          r = -PI/2;
      } else if ((B.x - state.x) > 3.65) {// Found number by turning hard as possible and seeing results.
          /// Drive along X axis the while below y axis to get closer to final state.
          r = 0;
      } else {
          // Turn left to reach final state.
          r = PI/2;
      }

      e = r - state.theta;
      controller_output = e * kp;
      controller_output += (e - prev_e)/dt * kd;
      prev_e = e;

      if (controller_output > 0.5) controller_output = 0.5;
      if (controller_output < -0.5) controller_output = -0.5;

      state.theta += v0*tan(controller_output)/L * dt;
      state.x += v0 * cos(state.theta) * dt;
      state.y += v0 * sin(state.theta) * dt;
      u.push_back(controller_output);
      i += 1;
      if (i % 10 != 0) continue;
      cout << "state " << state.x << " " << state.y << " "<< state.theta <<" "<<controller_output<<" t: "<< t << endl;
  }


  // Compute a sequence of control so that the car can move from A and reach target B as closely as possible

  return;
}


// To execute C++, please define "int main()"
int main() {
  Configuration init, final;
  vector<Configuration> ref;
  vector<double> u;

  cout<<"Problem 1: "<<endl;
  init.x = 2.0, init.y = 2.0, init.theta = PI/2;
  ref = GenPath(init, 2.0, final);
  /*
  for (int i = 0; i < ref.size(); i++) {
      if (i % 10 != 0) continue;
      cout << ref[i].x << " " << ref[i].y << " " << ref[i].theta <<" t: "<< i*0.1 << endl;
  }*/

  cout<<"Problem 2: "<<endl;
  init.x = 2.0, init.y = 2.0, init.theta = PI/2;
  Tracking(ref, init, u);


  cout<<"Problem 3: "<<endl;
  ReachTarget(1, u);
  //ReachTarget(50, u);
  //ReachTarget(1, u);

  return 0;
}
