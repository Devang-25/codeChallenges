// https://www.educative.io/courses/grokking-the-coding-interview/N7pvEn86YrN

using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycleStart {
 public:
  static ListNode *findCycleStart(ListNode *head) {
    // TODO: Write your code here
    if(!head || !head->next) {
      return NULL;
    }
    ListNode *p1=head, *p2=head;
    while(p1 && p2) {
      p1 = p1->next;
      p2 = p2->next? p2->next->next : NULL;
      if(p1 == p2) break;
    }
    if(p1 != p2) {
      return NULL;
    }
    p1 = head;
    while(p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

  head->next->next->next->next->next->next = head;
  cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
