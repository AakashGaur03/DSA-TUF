#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  string data;
  Node *next;
  Node *back;

public:
  Node(string data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(string data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

class Browser {
  Node *currentPage;

public:
  Browser(string &homepage) { // TC O(1)
    //
    currentPage = new Node(homepage);
  }
  void visit(string &url) { // TC O(1)
    Node *newNode = new Node(url);
    currentPage->next = newNode;
    newNode->back = currentPage;
    newNode->next = NULL;
    currentPage = currentPage->next;
  }

  string back(int steps) { // TC O(steps)
    while (steps) {
      if (currentPage->back) {
        currentPage = currentPage->back;
      } else {
        break;
      }
      steps--;
    }
    return currentPage->data;
  }
  string forward(int steps) { // TC O(steps)
    while (steps) {
      if (currentPage->next) {
        currentPage = currentPage->next;
      } else {
        break;
      }
      steps--;
    }
    return currentPage->data;
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

int main() {
  cout << "25 L28 Design a Browser History LinkedList Implementation" << endl;

  string homepage = "github.com";
  Browser browser(homepage);

  string url1 = "google.com", url2 = "linkedin.com", url3 = "youtube.com";
  string url4 = "twitter.com";

  browser.visit(url1);
  cout << browser.back(1) << endl; // github.com
  browser.visit(url2);
  browser.visit(url3);
  cout << browser.back(1) << endl;    // linkedin.com
  cout << browser.back(1) << endl;    // google.com
  cout << browser.forward(1) << endl; // linkedin.com
  browser.visit(url4);                // clears forward history
  cout << browser.forward(2) << endl; // twitter.com
  cout << browser.back(3) << endl;    // github.com

  return 0;
}

// We need to design acc to queries
// There will be a homepage always
// then we ca visit urls
// we can go forward
// we can go backward

// homepage(github.com)
// visit(google.com)
// visit(linkedin.com)
// visit(youtube.com)
// back(1)
// back(1)
// forward(1)
// visit(linkedin.com)
// forward(5)
// back(3)
// back(7)