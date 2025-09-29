// If there is arr[4] = [1,2,3,5]
// We cant add more element now
// as array is stored in Heap memory
// Array stores value in contigious memory Location

// Linked List is similar Data Structure
// It doesnt store in contigious location
// There size can be increased at any moment
// How to do store it
// It store data and next at each element

// Let in Linked List have          1  3  2   5
// Lets assume they are stored at  m1 m2 m3   m4

// So It store data and next
// Starting of Linked List is called head of the Linked List
// End is called Tail of Linked List

// head = m1 it has next = m2
// m2 has 2 it has next m3
// m3 has 2 , next has m4
// m4 has 5, next has nullptr
// it is also caled tail of the Linked list

// -------------------------------------------
// How do we add element

// we simply go to tail we point tail to location m5
// and a data  and then m5 points to nullptr

// Where it is used
// Stack and Queue

// In Real Life
// It is used in Browser

// In Browser it has 2D Linked List
// that has pointer to next and previous both

// --------------------------------------------
// Struct and Class

// int x = 2;  // Decalares int in heap memory
// int *y = &x;  // here x gives the memory location
// In more detail &x gives the memory location
// In c++ we cant store a memory location so that why
// int *y so now it stores pointer to the memory location

// cout << y;  // It gives pointer pointing to memory location of x

// int arr[10]; // In arrays

// In Linked List we are stoing two things
// One Data itself and second Pointer to the next Data

// So we dont have a Data type to store Both

// So here we have to define Self Defined Data Type

// struct Node {
//   int data;
//   Node *next;
//   Node(data1, next1) {
//     data = data1;
//     next = next1;
//   }
// }

// EXPLANATION

// int data is for data
// after this we have a pointer
// and the self defined Data type that we are storing
// is called Node so
//  Node* next;
// Pointert to the next

// So in order to initilaize these values we need an construcutor
// Node(data1, next1) {
//   data = data1;
//   next = next1;
// }

// Constructor is special Type of member Function
// which is used to initialize the objects of the class

// In struct we dont get OOPS concept that is
// Abstrcation Encapsulation

// So instead of struct use class it is same thing

// ---------------------------------
// How to Initialize the Value

// Method 1

// Node x = Node(2,nullptr) // This is variable
// Node *y = &x; // Pointer to above variable

// Method 2

// Node *y = new Node(2, nullptr)
// It automatically stores pointer to memory location of 2
// new keyword gives us directly pointer to the memory location
#include <bits/stdc++.h>
using namespace std;

// struct Node {
class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

// See thif function when appears in code
Node *convertArr2LL(vector<int> arr) {
  // TC O(N)

  // Step 1: Create the first node (head) using the first element of the array
  // 'new Node(arr[0])' creates a node with 'data = arr[0]' and 'next = nullptr'
  Node *head = new Node(arr[0]);

  // Step 2: Keep a pointer 'mover' to traverse the list while building it
  Node *mover = head;

  // Step 3: Loop through the rest of the array elements (starting from index 1)
  for (int i = 1; i < arr.size(); i++) {
    // Step 4: Create a new node for the current element
    Node *temp = new Node(arr[i]);

    // Step 5: Link the previous node (mover) to this new node
    mover->next = temp;

    // Step 6: Move the 'mover' pointer ahead to the newly created node
    // This ensures the next new node will be attached to the current tail
    mover = temp;
    // mover = mover->next;  // both do the same thing
  }

  // Step 7: Return the head of the linked list (starting point)
  return head;
}

int lengthofLL(Node *head) {
  // TC O(N)

  int cnt = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

int checkIfPresent(Node *head, int val) {
  // TC O(N)

  Node *temp = head;
  while (temp) {
    if (temp->data == val)
      return 1;
    temp = temp->next;
  }
  return 0;
}

int main() {
  cout << "1 Linked List" << endl;
  vector<int> arr = {2, 5, 8, 7};
  Node *y = new Node(arr[0], nullptr);
  cout << y << endl;
  cout << y->data << endl;
  cout << y->next << endl;

  // It basically gives us an object
  Node z = Node(arr[0], nullptr);
  cout << z.data << endl; // Data
  cout << z.next << endl; // Points to Null

  // It uses second construcutor
  Node *a = new Node(arr[0]);
  cout << a->data << endl; // Data
  cout << a->next << endl; // Points to Null

  // Convert Array into LL
  // arr[] = [ 2, 1, 3, 8 ];
  // We dont return the entire LL as we do in array
  // We return the Head as it always point to start of LL
  // RULE FOR LL NEVER TAMPER THE HEAD
  vector<int> arr12 = {2, 1, 5, 8};
  Node *head = convertArr2LL(arr12);
  cout << head << endl;
  cout << head->data << endl;

  // RULE FOR LL NEVER TAMPER THE HEAD
  // Traversal in LL
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;

  // Length of  LL
  // we do traversal with a coutner variable and then reutrn count
  int res = lengthofLL(head);
  cout << res << endl;

  // Search in LL
  cout << checkIfPresent(head, 23) << endl;
  cout << checkIfPresent(head, 8) << endl;
  return 0;
}