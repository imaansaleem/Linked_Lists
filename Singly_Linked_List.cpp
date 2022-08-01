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
	Node *tail;
	
	public:
	LinkedList(){ 
		head=NULL;
		tail=NULL; 
	}
	
	void AddNodeHead(int d){
		Node* node = new Node(d);
		node->next=head;
		head=node;
		//or head=new Node(d,head)
		if(tail==NULL)
			tail=head;
	}
	
	void AddNodeTail(int d){
		if(tail!=NULL){
			tail->next=new Node(d);
			tail=tail->next;
		}
		else
			head=tail=new Node(d);	
	}
	
	bool IsEmpty(){
		if(head==NULL)
			return 1;
		else
			return 0;
	}
	
	int Delete_From_Head(){
		int digit;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=head->data;
			Node* temp=head;
			if(head==tail)
				head=tail=NULL;
			else{
				head=head->next;
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
			digit=tail->data;
			if(head==tail)
				head=tail=NULL;
			else{
				for(i=head; i->next!=tail; i=i->next);
				delete tail;
				tail=i;
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
			if(i->next==tail)
				Delete_From_Tail(); //deleting last node

			else{
				Node *temp = i->next;
				i->next=i->next->next; //deleting center node
				delete temp;
			}
		}
	}

	void show(){
		for(Node *i=head; i!=tail->next; i=i->next)
			cout << i->data << ' ';
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
