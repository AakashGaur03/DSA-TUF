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

Node *reverse(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *newHead = reverse(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

Node *reverseIterative(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL) {
    Node *front = temp->next;
    temp->next = prev;

    prev = temp;
    temp = front;
  }
  return prev;
}

Node *findKthNode(Node *temp, int k) {
  k -= 1;
  while (temp != NULL && k > 0) {
    k--;
    temp = temp->next;
  }
  return temp;
}

Node *reverseKthGroup(Node *head, int k) {
  // TC O(N + N)
  // N for Traversing and N for reversal
  // SC O(1)
  Node *temp = head;
  Node *prevLast = NULL;
  while (temp != NULL) {
    Node *KthNode = findKthNode(temp, k);
    if (KthNode == NULL) {
      // handling for cases when no kth Group Like for 10 , 11
      // So we need to connect out prevLast to rest of the remaining ones that
      // is 10 and 11
      if (prevLast)
        prevLast->next = temp;
      break;
    }
    // Now we have Kth Group
    Node *nextNode = KthNode->next;
    // Disconnect it to reverse it
    KthNode->next = NULL;

    reverse(temp);
    // Now we need to check that do we need to update head
    // that is is it out first group
    if (temp == head) {
      head = KthNode;
    } else {
      // Here we need to connect prevLast to current KthNode
      prevLast->next = KthNode;
    }
    // we need to store prev
    prevLast = temp;
    // Now we will move to next Group
    temp = nextNode;
  }
  return head;
}
int main() {
  cout << "18 L21 Reverse Nodes in K Group Size of LL" << endl;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  Node *head = convertArr2LL(arr);
  printLL(head);
  // So acc to question we need to reverse in Group of K
  // In our case K = 3 so
  // 1 2 3 -> 3 2 1
  // 4 5 6 -> 6 5 4
  // 7 8 9 -> 9 8 7
  // 10 11 as it is
  // if a group is not of k then dont reverse so if here in last
  //  we had 10 11 we will keep it as it as, as it is not equal to 3

  // FINAL ANSWER 3 2 1 6 5 4 9 8 7 10 11
  // Refer to Images 1 and 2 to understand Problem

  // Approach
  // We will send K groups as single LL in reverse function
  // also we need to consider when to update head to get correct result
  // So refer to image 3 and 4 Notice when temp == head then we need to update
  // it And also see that kthNode will be at updated new head always

  // After this we will have 3 2 1 But if you Notice in Iamge 3 and 4 we have
  // pointed to Null to make it LL to reverse it so we have lost next pointer
  // thats why before reversing we wikll store next Pointer Refer Image 5
  // after reversal take temp to nextNode Refer to Image 6

  //   We will do this same for next ones

  // here comes one more Point to Node that we need to connect 1 -> 6 , 4 ->9

  // So also make sure to store prev Node so that we can point it again
  // Refer at Iamge 7 and 8
  int k = 3;
  head = reverseKthGroup(head, k);
  printLL(head);
  return 0;
}

// REVISITED