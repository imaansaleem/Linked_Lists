#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node(int d, Node *n=NULL){
		data=d;
		next=n;
	}
};

class LinkedList{
	Node *head;
	
	public:
	LinkedList(){ 
		head=NULL; 
	}
	
	void AddNodeHead(int d){
		Node *i;
		if(head==NULL){
			head=new Node(d);
			head->next=head;
		}
		else{
			for(i=head;i->next!=head;i=i->next);
			i->next=new Node(d,head);
			head=i->next;
		}
	}
	
	void AddNodeTail(int d){
		Node *i;
		if(head==NULL){
			head=new Node(d);
			head->next=head;
		}
		else{
			for(i=head;i->next!=head;i=i->next);
			i->next=new Node(d,head);
		}
	}
	
	bool IsEmpty(){
		if(head==NULL)
			return 1;
		else
			return 0;
	}
	
	int Delete_From_Head(){
		int digit;
		Node *i;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=head->data;
			Node* temp=head;
			if(head->next==head)
				head=NULL;
			else{
				for(i=head;i->next!=head;i=i->next);
				head=head->next;
				i->next=head;
				delete temp;
			}
		}
		return digit;
	}
	
	int Delete_From_Tail(){
		Node *i;
		int digit;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			if(head->next==head)
				head=NULL;
			else{
				for(i=head; i->next->next!=head; i=i->next);
				digit=i->next->data;
				i->next=head;
			}
		}
		return digit;
	}
	
	void deleteNode(int d){
		Node *i;
		if(head->data==d)  //deleting first node
			Delete_From_Head();
			
		else{
			for(i=head; i->next!=NULL && i->next->data!=d ; i=i->next);
			if(i->next==head)
				Delete_From_Tail(); //deleting last node

			else{
				Node *temp = i->next;
				i->next=i->next->next; //deleting center node
				delete temp;
			}
		}
	}

	void show(){
		Node *i;
		for(i=head; i->next!=head; i=i->next)
			cout << i->data << ' ';
		cout << i->data;
	}
};

int main()
{
	LinkedList list;
	if(list.IsEmpty())
		cout << "List is Empty\n\n";
	list.AddNodeHead(23);
	list.AddNodeHead(24);
	list.AddNodeHead(25);
	list.AddNodeHead(26);
	list.AddNodeHead(27);
	list.AddNodeTail(1);
	list.AddNodeTail(2);
	list.AddNodeTail(3);
	list.AddNodeTail(4);
	list.AddNodeTail(5);
	cout << "Whole List is: \n";
	list.show();
	cout << "\n\nDeleting 1st ,last and center element\n";
	list.deleteNode(27);
	list.deleteNode(5);
	list.deleteNode(3);
	cout << "\n\nNow the list is\n";
	list.show();
	int num=list.Delete_From_Head();
	cout << "\n\nDeleted digit from head is: " << num << endl;
	int num2=list.Delete_From_Tail();
	cout << "\n\nDeleted digit from tail is: " << num2 << endl;
	list.show();

	return 0;
}
