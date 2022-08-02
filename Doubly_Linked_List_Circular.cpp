#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node *previous;
	
	Node(int d, Node *n=NULL, Node *p=NULL){
		data=d;
		next=n;
		previous=p;
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
        if(head==NULL){
			head=tail=new Node(d);
			tail->previous=tail->next=tail;
			head->previous=head->next=head;
		}

        else{
		    head=new Node(d,head,head->previous);
		    head->next->previous=head;
			tail->next=head;
        }
	}
	
	void AddNodeTail(int d){
		if(tail!=NULL){
			tail=new Node(d,head,tail);
			tail->previous->next=tail;
			head->previous=tail;
		}

		else{
			head=tail=new Node(d);
			tail->previous=tail->next=tail;
			head->previous=head->next=head;
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
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=head->data;
			if(head==tail)
				head=tail=NULL;
			else{
				head=head->next;
				delete head->previous;
				head->previous=tail;
				tail->next=head;
			}
		}
		return digit;
	}
	
	int Delete_From_Tail(){
		int digit;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=tail->data;
			if(head==tail)
				head=tail=NULL;
			else{
				tail=tail->previous;
				delete tail->next;
				head->previous=tail;
				tail->next=head;
			}
		}
		return digit;
	}
	
	int delete_Node_centre(int position){
		Node *i;
		int count;
		for(i=head,count=1;count!=position;i=i->next,count++);
			int e=i->data;
			i->previous->next=i->next;
			i->next->previous=i->previous;
			delete i;
		return e;
	}


	void insert_Node(int d, int position){
		Node *i;
		int count;
		for(i=head,count=1;count!=position;i=i->next,count++);
		i->next=new Node(d,i->next,NULL);
		i->next->previous=i;
		i->next->next->previous=i->next;

	}

	void show(){
		Node *i;
		for(i=head; i->next!=head; i=i->next){
			cout << i->data << ' ';
		}
		cout << i->data;
	}
};

int main()
{
	LinkedList list;
	list.AddNodeHead(22);
	list.AddNodeHead(23);
	list.AddNodeHead(24);
	list.AddNodeHead(25);
	list.AddNodeHead(26);
	list.AddNodeHead(27);
	list.show();
	cout << endl;
	list.AddNodeTail(1);
	list.AddNodeTail(2);
	list.AddNodeTail(3);
	list.show();

	int num=list.Delete_From_Head();
	cout << "\n\nDeleted digit from head is: " << num << endl;
	list.show();
	int num2=list.Delete_From_Tail();
	cout << "\n\nDeleted digit from tail is: " << num2 << endl;
	list.show();
	list.insert_Node(30,3);
	cout << endl;
	list.show();
	cout << "\n\nDeleting element\n";
	cout << "\nDeleted Element is: " << list.delete_Node_centre(2);
	cout << "\n\nNow the list is\n";
	list.show();
	return 0;
}
