#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          //Complete this method
          Node * start = head;
          Node *tmp = new Node(data);
          if(head==NULL){
              start = tmp;
              head = tmp;
          }
          else {
              int i=1;
              while(i){
                  if(start->next == NULL){
                    cout << "Start st: " << start<< endl;
                    start->next = tmp;
                    i=0;
                    cout << "Start en: " << start<< endl;
              }
              else{
                  start = start->next;
              }
              
          }
          }

         
        //   cout << "Start: " << start<< endl;
        //   cout << " Start Data: " << start->data << endl;
        //   cout << "Start next: " << start->next <<endl;
          return head;
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}