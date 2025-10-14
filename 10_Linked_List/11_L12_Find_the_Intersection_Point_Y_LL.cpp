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
// utility function to insert Node at the end of the linked list
void insertNode(Node *&head, int data) {
  Node *newNode = new Node(data);

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  return;
}

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *bruteIntersectionYLL(Node *head1, Node *head2) {
  // TC -> O(N1 + N2)
  // SC -> O(N1)

  // Use a map (or unordered_map) to store all nodes of first list
  unordered_map<Node *, int> mpp; // store address of each node
  Node *temp = head1;

  while (temp != NULL) {
    mpp[temp] = 1; // mark that we have seen this node
    temp = temp->next;
  }

  // traverse 2nd list and check if any node is already in map
  temp = head2;
  while (temp != NULL) {
    if (mpp.find(temp) != mpp.end()) {
      // Found intersection point
      return temp;
    }
    temp = temp->next;
  }

  // If no intersection found
  return NULL;
}

Node *collisionPoint(Node *smallTemp, Node *bigTemp, int d) {
  // TC O(max(N1,N2))

  // Move the longer list 'd' steps ahead
  while (d) {
    d--;
    bigTemp = bigTemp->next;
  }

  // Traverse both lists together
  while (bigTemp != smallTemp) {
    bigTemp = bigTemp->next;
    smallTemp = smallTemp->next;
  }
  // Will be equal at colliding node or will be equal at NULL
  return bigTemp;
}

Node *betterIntersectionYLL(Node *head1, Node *head2) {
  // TC O(N1) + O(N2) + O(max(N1,N2))
  // SC O(1)
  Node *temp1 = head1;
  int n1 = 0;
  // Find length of first list
  while (temp1 != NULL) { // O(N1)
    n1++;
    temp1 = temp1->next;
  }
  Node *temp2 = head2;
  int n2 = 0;
  // Find length of second list
  while (temp2 != NULL) { // O(N2)
    n2++;
    temp2 = temp2->next;
  }

  // Move the longer list ahead by |n1 - n2| nodes
  if (n1 < n2) {
    return collisionPoint(head1, head2, n2 - n1);
  } else {
    return collisionPoint(head2, head1, n1 - n2);
  }
}

Node *optimzedIntersectionYLL(Node *head1, Node *head2) {

  // TC O(N1+N2) N1+N2 for traversing all nodes
  // SC O(1)

  // we will iterate both the LL simultaneously
  // When one LL reaches to end to start it from start of another LL
  // same for both

  // Like if LL1 gets exhausted we will start it from LL2 , LL2's orginal
  // traversal will be its placed

  // Likewise if LL2 gets exhausted we will start it from LL1 , LL1's orginal
  // traversal will be its placed

  // temp1 reaches to null take to head2
  // temp2 reaches to null take to head1

  // When both temp1 and temp2 if swapped once then if there is no common
  // intersection they both will collide at same time to NULL so means
  // NO INTERSECTION

  if (head1 == NULL || head2 == NULL) {
    return NULL;
  }
  Node *temp1 = head1;
  Node *temp2 = head2;

  while (temp1 != temp2) { // also checks for the first time
    temp1 = temp1->next;
    temp2 = temp2->next;

    if (temp1 == temp2) {
      return temp1;
    }
    // Below one will be covered in temp1==temp2 only
    // if (temp1 == NULL && temp2 == NULL) {
    //   return NULL;
    // }
    if (temp1 == NULL) {
      temp1 = head2;
    }
    if (temp2 == NULL) {
      temp2 = head1;
    }
  }
  return temp1;
}

int main() {
  // creation of both lists
  Node *head = NULL;
  insertNode(head, 1);
  insertNode(head, 3);
  insertNode(head, 1);
  insertNode(head, 2);
  insertNode(head, 4);
  Node *head1 = head;
  head = head->next->next->next;
  Node *headSec = NULL;
  insertNode(headSec, 3);
  Node *head2 = headSec;
  headSec->next = head;
  // printing of the lists
  cout << "List1: ";
  printLL(head1);
  cout << "List2: ";
  printLL(head2);
  Node *interSection = bruteIntersectionYLL(head1, head2);
  if (interSection != NULL)
    cout << "Intersection at node with data: " << interSection->data << endl;
  else
    cout << "No intersection found" << endl;
  Node *interSection2 = betterIntersectionYLL(head1, head2);
  if (interSection2 != NULL)
    cout << "Intersection at node with data: " << interSection2->data << endl;
  else
    cout << "No intersection found" << endl;
}
