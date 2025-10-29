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

Node *bruteSort(Node *head) {
  // TC O(N + N log N + N)
  // SC O(N)
  Node *temp = head;
  vector<int> arr;
  while (temp != NULL) {
    arr.push_back(temp->data);
    temp = temp->next;
  }
  sort(arr.begin(), arr.end());
  temp = head;
  for (int i = 0; i < arr.size(); i++) {
    temp->data = arr[i];
    temp = temp->next;
  }
  return head;
}

// Optimal Approach

Node *findMiddle(Node *head) {
  Node *fast = head->next; // we want first middle in case of even number
  Node *slow = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *mergeTwoLL(Node *temp1, Node *temp2) {
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
  if (temp1) {
    temp->next = temp1;
  } else {
    temp->next = temp2;
  }
  return dummyNode->next;
}

Node *optimalMergeSort(Node *head) {
  // TC O(N/2 * logN * N)
  // N/2 for finding middle
  // log N for splitting and * for merging two LL
  // SC O(log N) Recursive Stack Space
  Node *temp = head;
  // WE will apply merge Sort in LL

  // Step 1
  // Divide from middle and then break into two LL
  // Repeat till Single element
  // Merge them in sorted way using merge2LL

  if (head == NULL || head->next == NULL) {
    return head;
  }

  // We will divide with help of totoise and Hare Algorithm
  Node *middle = findMiddle(head);
  Node *leftHead = head;
  Node *righthead = middle->next;
  middle->next = NULL; // to make sure they are two different LL's

  leftHead = optimalMergeSort(leftHead);
  righthead = optimalMergeSort(righthead);

  return mergeTwoLL(leftHead, righthead);
}
int main() {
  cout << "22 L25 Merge K sorted Linked List" << endl;
  vector<int> arr = {1, 8, 7, 12, 3};
  Node *head = convertArr2LL(arr);
  printLL(head);
  // head = bruteSort(head);
  // printLL(head);
  head = optimalMergeSort(head);
  printLL(head);

  return 0;
}
