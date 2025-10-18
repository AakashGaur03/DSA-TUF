#include <bits/stdc++.h>
using namespace std;

// Doubly LL
class Node {
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
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

Node *convertArr2DoublyLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }

  return head;
}

vector<pair<int, int>> bruteFindPairsWithSumSortedDLL(Node *head, int sum) {
  // TC O(N^2) approx
  // SC O(1)
  vector<pair<int, int>> pr;
  Node *temp1 = head;
  if (head == NULL) {
    return {};
  }

  while (temp1 != NULL && temp1->next != NULL) {
    Node *temp2 = temp1->next;
    while (temp2 != NULL) {

      if (temp1->data + temp2->data == sum) {
        pr.push_back({temp1->data, temp2->data});
      } else if (temp1->data + temp2->data > sum) {
        break;
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }

  return pr;
}
vector<pair<int, int>> optimzedFindPairsWithSumSortedDLL(Node *head, int sum) {
  // TC O(2N) N for find tail and N for while Loop
  // SC O(1)
  vector<pair<int, int>> pr;
  // We will use Two Pointer Approach
  // Fix left at 0
  // Right at last
  // if sum is > then right --
  // if sum is < then else left ++
  // else == then move both right --, left ++
  if (head == NULL)
    return {};
  Node *right = head;
  while (right->next != NULL) {
    right = right->next;
  }
  Node *left = head;
  // Now left stands at 0 index that is head
  // right stand at last index that is last Node in DLL

  // while (left <= right) {
  // while (left->data < right->data) {
  while (left != right && right->next != left) {

    if (left->data + right->data < sum) {
      left = left->next;
    } else if (left->data + right->data > sum) {
      right = right->back;
    } else {
      // means left + right == sum
      pr.push_back({left->data, right->data});
      left = left->next;
      right = right->back;
    }
  }
  return pr;
}

int main() {
  cout << "16 L19 Find Pairs with Given Sum in Sorted DLL" << endl;
  vector<int> arr = {1, 2, 3, 4, 9};
  int sum = 5;
  // DLL is in sorted order
  // Return All pairs that adds up to sum
  Node *head = convertArr2DoublyLL(arr);
  printLL(head);

  vector<pair<int, int>> ans = bruteFindPairsWithSumSortedDLL(head, sum);

  for (auto it : ans) {
    cout << it.first << "," << it.second << endl;
  }
  vector<pair<int, int>> ans2 = optimzedFindPairsWithSumSortedDLL(head, sum);

  for (auto it2 : ans2) {
    cout << "optimzed " << it2.first << "," << it2.second << endl;
  }

  return 0;
}
