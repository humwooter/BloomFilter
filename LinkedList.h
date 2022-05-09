
#include <iostream>
#include <string>

using namespace std;

struct Node
{
  string data;
  Node *next;

  Node(string data) {
    this->data = data;
    this->next = NULL;
    
  }
};

class LinkedList
{
 private:
  Node *head;
  Node *tail;
 public:
  
  LinkedList()
    {
      head = NULL;
      tail = NULL;
    }

   ~LinkedList() {
     Node* temp1 = head, *temp2 = NULL;
     while (temp1 != NULL) {
       temp2 = temp1;
       temp1 = temp1->next;
       delete temp2;
       
     }
     
   }

  void insert_node(string data);
  void remove_node(string data);
  bool find_node(string data);
};
