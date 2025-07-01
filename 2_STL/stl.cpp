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
  // cout << "Vectors" << endl;
  // vector<int> v;
  // v.push_back(2);
  // v.emplace_back(3);
  // // But for simple types like int, both behave exactly the same.

  // // push_back(obj)	Requires an object to already exist → copy or move into
  // // the container emplace_back(args...)	Constructs the object in-place
  // // in the container using the arguments

  // vector<pair<int, int>> vec;
  // vec.push_back({1, 2});
  // vec.emplace_back(3, 4);

  // vector<int> ve2(5, 100); //{100,100,100,100,100}
  // // It means vector of 5 size containing 5 instances of 100 is defined
  // vector<int> ve3(5);
  // // It means vector of 5 size containing 5 instances of 0 or any garbage
  // value
  // // is defined

  // vector<int> vect(5, 20); //{20,20,20,20,20}
  // vector<int> vect2(vect); // Copy of above vector not same

  // // Accessing the array
  // cout << "vect[0] : " << vect[0];
  // using iterator

  // datatype::iterator variableName = v.begin()

  vector<int> v = {10, 20, 30, 40};

  // v.begin()       → points to the first element (10)
  // *(v.begin())    → value at that address, i.e., 10

  vector<int>::iterator it1 = v.begin(); // Points to 10
  vector<int>::iterator it2 = v.end();
  // Points just after 40 (invalid to dereference)

  // v.rbegin()      → points to the last element (40) [used for reverse
  // iteration]
  // v.rend()        → points just before the first element (invalid
  // to dereference) reverse order becomes: 40 30 20 10

  vector<int>::reverse_iterator rit1 = v.rbegin(); // Points to 40
  vector<int>::reverse_iterator rit2 = v.rend();   // Points before 10

  cout << "Gives Last element:" << v.back() << endl;
  cout << "NEW " << endl;

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *(it) << endl;
  }
  cout << "Again with auto :" << endl;
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *(it) << " ";
  }

  // For each Loop
  cout << endl << "For Each" << endl;
  for (auto it : v) {
    cout << it << " ";
  }

  // Delete from vector

  //{10,20,30,40}
  v.erase(v.begin() + 1); // Deletes the second element
  cout << endl << "After Deletion" << endl;
  for (auto it : v) {
    cout << it << " ";
  }
  v.push_back(1);
  v.push_back(2);
  cout << endl << "After Push Back" << endl;
  for (auto it : v) {
    cout << it << " ";
  }
  // {10 30 40 1 2 }
  // Delete multiple
  // starting address and address till which you want to delete, means value
  // before second address will be deleted
  // start is included end is not
  // like if we want to delete  30 40 so v.begin() + 1, v.begin() + 3
  v.erase(v.begin() + 1, v.begin() + 3);
  cout << endl << "After Deletion" << endl;
  for (auto it : v) {
    cout << it << " ";
  }

  // Insert Function

  vector<int> someV(2, 100);        //{100,100}
  someV.insert(someV.begin(), 300); //{300,100,100}
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }
  // (index,value that need to be inserted)
  someV.insert(someV.begin() + 1, 50); //{300,50,100,100}
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }

  // (index,how many values,value that need to be inserted)
  someV.insert(someV.begin() + 2, 2, 40); //{300,50,40,40,100,100}
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }

  vector<int> someV2(2, 70);
  someV.insert(someV.begin(), someV2.begin(), someV2.end());
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }
  vector<int> someV3 = {1, 2, 3, 4, 5, 6, 7};

  // can also give limited  someV3.begin() + 1 is 2 and someV3.begin() + 3 is 4
  // so 2 is included and 4 is not
  someV.insert(someV.begin(), someV3.begin() + 1, someV3.begin() + 3);
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }
  cout << endl;
  cout << "Size is: " << someV.size();

  // Removes last element
  someV.pop_back();
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }

  vector<int> sV1 = {2, 70};
  vector<int> sV2 = {45, 65, 56545, 34, 32};

  // Swaps two vector also works if uneven size
  sV1.swap(sV2);
  cout << endl << "SV1 :";

  for (auto it : sV1) {
    cout << it << " ";
  }

  cout << endl << "SV2 :";
  for (auto it : sV2) {
    cout << it << " ";
  }

  sV2.clear();
  cout << endl << "Clears SV2 :";
  for (auto it : sV2) {
    cout << it << " ";
  }
  cout << endl;
  // Gives 1 or 0 if empty then 1 otherwise 0
  cout << "SV2 : " << sV2.empty();
  cout << endl;
  cout << "SV1: " << sV1.empty();
}
int main() {
  cout << "Hi" << endl;
  explainPair();
  explainVector();
  return 0;
}