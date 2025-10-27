#include <bits/stdc++.h>
using namespace std;

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

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

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

Node *mergeKSortedList(vector<Node *> list) {
  // TC O((N*K) + (N*K log N*K) + (N*k))
  // (N*K) First iteration and storing
  // (N*K log N*K) for sorting
  // (N*k) for converting
  // SC O((N*K) + (N*k)) 1 for storing in arr and second for ans
  vector<int> arr;
  for (int i = 0; i < list.size(); i++) {
    Node *temp = list[i];
    while (temp != NULL) {
      arr.push_back(temp->data);
      temp = temp->next;
    }
  }

  // Now we have all elements in arr
  sort(arr.begin(), arr.end());

  Node *head = convertArr2LL(arr);

  return head;
}

Node *merge2LL(Node *temp1, Node *temp2) {
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      temp->next = temp1;
      temp1 = temp1->next;
    } else {
      temp->next = temp2;
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
  if (temp1)
    temp->next = temp1;
  if (temp2)
    temp->next = temp2;
  return dummyNode->next;
}

Node *bettermergeKSortedList(vector<Node *> list) {
  // TC O(N * (k * K+1)/2) // explained in Image Attached
  // approx in power of cube
  // SC O(1)
  Node *head = list[0];

  for (int i = 1; i < list.size(); i++) {
    head = merge2LL(head, list[i]);
  }

  return head;
}

int main() {
  cout << "22 L25 Merge K sorted Linked List" << endl;
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr2 = {1, 3, 3, 6, 11, 15};
  vector<int> arr3 = {1, 5, 6, 23, 67};
  Node *head = convertArr2LL(arr);
  Node *head2 = convertArr2LL(arr2);
  Node *head3 = convertArr2LL(arr3);
  vector<Node *> list = {head, head2, head3};
  head = mergeKSortedList(list);
  printLL(head);
  head2 = bettermergeKSortedList(list);
  printLL(head2);

  // For optimal we will be using concept of min-heap
  // min-heap is simply that gives us minimum value
  // in C++ Java we have Priority Queue Data Structure that implements min heap
  return 0;
}
