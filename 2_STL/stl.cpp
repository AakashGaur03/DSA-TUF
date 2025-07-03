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

  // vector<int> ve2(5, 100); // {100,100,100,100,100}
  // // It means vector of 5 size containing 5 instances of 100 is defined
  // vector<int> ve3(5);
  // // It means vector of 5 size containing 5 instances of 0 or any garbage
  // value
  // // is defined

  // vector<int> vect(5, 20); // {20,20,20,20,20}
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

  // {10,20,30,40}
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

  vector<int> someV(2, 100);        // {100,100}
  someV.insert(someV.begin(), 300); // {300,100,100}
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }
  // (index,value that need to be inserted)
  someV.insert(someV.begin() + 1, 50); // {300,50,100,100}
  cout << endl;
  for (auto it : someV) {
    cout << it << " ";
  }

  // (index,how many values,value that need to be inserted)
  someV.insert(someV.begin() + 2, 2, 40); // {300,50,40,40,100,100}
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

void explainList() {
  // Same as Vector but it gives front operation too
  // In Vector we need to do insert that it is costly takes high time
  list<int> ls;
  ls.push_back(4);
  ls.emplace_back(4);
  ls.push_front(5);
  ls.emplace_front(7);
  // rest functions are same as vector
  //  begin, end, rbegin, rend, clear, insert, size, swap
}
void explainDeque() {
  // Same as Vector but it gives front operation too
  // In Vector we need to do insert that it is costly takes high time
  deque<int> dq;
  dq.push_back(4);
  dq.emplace_back(4);
  dq.push_front(5);
  dq.emplace_front(7);
  dq.pop_back();
  dq.pop_front();
  cout << dq.back() << endl;
  cout << dq.front() << endl;
  // rest functions are same as vector
  //  begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack() {
  // LIFO
  stack<int> st;
  // index is not allowed st[2]
  st.push(1);         // {1}
  st.push(2);         // {2,1}
  st.push(3);         // {3,2,1}
  st.push(4);         // {4,3,2,1}
  st.emplace(5);      // {5,4,3,2,1}
  cout << st.top();   // 5
  st.pop();           // {4,3,2,1}
  st.size();          // 4
  cout << st.empty(); // 1 or 0
  stack<int> st1, st2;
  st1.swap(st2);
}

void explainQueue() {
  // FIFO
  queue<int> qu;
  // index is not allowed st[2]
  qu.push(1);     // {1}
  qu.push(2);     // {1,2}
  qu.push(3);     // {1,2,3}
  qu.emplace(4);  // {1,2,3,4}
  qu.back() += 5; // 4+5
  // {1,2,3,9}
  cout << qu.back();  // 9
  cout << qu.front(); // 1
  cout << qu.front(); // 1
  // {1,2,3,9}
  qu.pop();
  // {2,3,9}
  qu.pop();
  // {3,9}
  cout << qu.front(); // 3
  cout << qu.empty(); // 1 or 0
  // {3,9}
  cout << qu.size(); // 2
  stack<int> qu1, qu2;
  qu1.swap(qu2);
}
void explainPriorityQueue() {
  cout << endl << "Priority Queue PQ" << endl;
  // push and pop happens in log(n) as it is not linear DS
  // Maximum Heap (Max Heap)
  priority_queue<int> pq;
  // index is not allowed st[2]
  pq.push(5);       // {5}
  pq.push(2);       // {5,2}
  pq.push(8);       // {8,5,2}
  pq.emplace(10);   // {10,8,5,2}
  cout << pq.top(); // 10
  // {10,8,5,2}
  pq.pop();
  // {8,5,2}
  cout << pq.top();   // 8
  cout << pq.empty(); // 1 or 0
                      // {8,5,2}
  cout << pq.size();  // 3
  stack<int> pq1, pq2;
  pq1.swap(pq2);

  // Minimum Heap (Min Heap)
  priority_queue<int, vector<int>, greater<int>> somePq;
  pq.push(5);       // {5}
  pq.push(2);       // {2,5}
  pq.push(8);       // {2,5,8}
  pq.emplace(10);   // {2,5,8,10}
  cout << pq.top(); // 2
}

void explainSet() {
  // Stores everything in sorted order and unique
  // insert erase happens in log(n)
  cout << endl << "Set" << endl;
  set<int> st;
  st.insert(1);  // {1}
  st.emplace(2); // {1,2}
  st.insert(2);  // {1,2}
  st.insert(4);  // {1,2,4}
  st.insert(3);  // {1,2,3,4}
  st.insert(3);  // {1,2,3,4}
  // Functionality of insert in vector can be used also,that only increases
  // effeciency
  // begin,end,rbegin,rend,empty,size,swap same as of above
  // {1,2,3,4}
  auto it = st.find(3); // It returns an itertor that points to 3
  // cout << it;
  auto it2 = st.find(6); // It returns an itertor that points to 6 as it is not
                         // present so it results at end()
  // cout << it2;
  st.erase(4); // erase 4 takes logarithmic of time
  int cnt = st.count(1);
  cout << cnt;
  cout << endl;
  for (int val : st) {
    cout << val << " ";
  }

  auto someIt = st.find(2);
  st.erase(someIt);
  int cnt2 = st.count(2);
  cout << endl << "Does 2 Exist :" << cnt2;

  // st={1, 2, 3, 4, 5, 6}
  auto someIt1 = st.find(2);
  auto someIt2 = st.find(4);
  st.erase(someIt1, someIt2);
  // so it erases 2 ,3
  // First index is inclusive means gets deleted second is exclusive means
  // deletes till before it
  // After Erase {1,4,5,6}

  auto someOtherit1 = st.lower_bound(2);
  auto someOtherit2 = st.upper_bound(3);
}

int main() {
  cout << "Hi" << endl;
  explainPair();
  explainVector();
  explainStack();
  explainQueue();
  explainPriorityQueue();
  explainSet();
  return 0;
}