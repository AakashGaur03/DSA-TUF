#include <bits/stdc++.h>
using namespace std;

// STL : Standard Template Library
// Containers
// Interators
// Algorithms
// Functions

// Pairs
void explainPair() {
  pair<int, int> p = {1, 3};
  cout << p.first << endl;
  cout << p.second << endl;

  pair<int, pair<int, int>> p2 = {1, {2, 3}};
  cout << p2.first << endl;
  cout << p2.second.first << endl;
  cout << p2.second.second << endl;

  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  cout << " arr[1].second : " << arr[1].second << endl;
}

// Vectors
// Need of vector like when we declare the size of array it cant be updated or
// redeclared so vectors comes in play they are dunamic in size
void explainVector() {
  cout << "Vectors" << endl;
  vector<int> v;
  v.push_back(2);
  v.emplace_back(3);
  // But for simple types like int, both behave exactly the same.

  // push_back(obj)	Requires an object to already exist → copy or move into
  // the container emplace_back(args...)	Constructs the object in-place
  // in the container using the arguments

  vector<pair<int, int>> vec;
  vec.push_back({1, 2});
  vec.emplace_back(3, 4);

  vector<int> ve2(5, 100); //{100,100,100,100,100}
  // It means vector of 5 size containing 5 instances of 100 is defined
  vector<int> ve3(5);
  // It means vector of 5 size containing 5 instances of 0 or any garbage value
  // is defined

  vector<int> vect(5, 20); //{20,20,20,20,20}
  vector<int> vect2(vect); // Copy of above vector not same
}
int main() {
  cout << "Hi" << endl;
  explainPair();
  explainVector();
  return 0;
}