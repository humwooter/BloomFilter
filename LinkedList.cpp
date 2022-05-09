#include "LinkedList.h"

void LinkedList::insert_node(string data) { //inserts node to end of linked list                                                                                                                                      
  Node* newNode = new Node(data);
  if (head == NULL) head = newNode;
  else if (head != NULL && tail == NULL) tail = newNode;
  else if (head != NULL && tail != NULL) tail->next = newNode;

}

void LinkedList::remove_node(string data) {
  Node* temp1 = head, *temp2 = NULL;

  if (temp1 == NULL) return;
  if (temp1->data == data) { //head is the node to be deleted                                                                                                                                             
    head = temp1->next;
    delete temp1;
  }
  while (temp1 != NULL) {
    temp2 = temp1;
    temp1 = temp1->next;
    if (temp1 != NULL && temp1->data == data) {
      temp2->next = temp1->next;
      delete temp1;
      return;
    }
  }

}

bool LinkedList::find_node(string data) {
  Node* curr = head;
  while (curr != NULL) {
    if (curr->data == data) return true;
    else curr = curr->next;
  }
  return false;
}
