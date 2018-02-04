#include<iostream>
using namespace std;

class node{ //Declaring a class of node containing two pointers and data
    public:
    int data;
    node *next;
    node *previous;

};

class linkedlist{
node *head,*tail;
public:
    linkedlist(){//Default constructor
    head=NULL;
    tail=NULL;
    }
    void addnode(int n){//Insert node with data at the end of the linked list
        node*temp=new node;
        temp->data = n;
        temp->next = head;
        if(head==NULL){//Checks if the node is empty
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->previous=tail;
            tail=temp;
            tail->next=head;
        }
    }


    void insertn(int position,int value){//Insert node with data at the given position of the linked list with the given value
        node *current =new node;
        node *previous = new node;
        node *temp = new node;
        temp->data=value;
        current= head;
        node *n=new node;
        n=head;
        int number=0;
        while(n->next!=head){//loop to count the number of elements
            number++;
            n=n->next;
        }number++;

        if(position>(number+1)){
            cout<<"Linked List does not have that many elements.";
        }
        else if(position==1){
            temp->next=head;
            temp->previous=tail;
            head->previous=temp;
            head=temp;
            tail->next=temp;
        }
        else if(position==number+1){
            addnode(value);
        }
        else{
        for(int i=1;i<position-1;i++){
            current=current->next;
        }
        temp->next=current->next;
        temp->previous=current;
        (temp->next)->previous=temp;
        current->next=temp;

    }
    }

    void display(){//function to display the elements i the linked list
        node *temp=new node;
        temp=head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;

        }cout<<tail->data;
    }
    void deletex(){//Function to delete the last  element in the linked list
        //node *before=new node;
        node *temp=tail;
        tail=tail->previous;
        tail->next=head;
        head->previous=tail;
        delete temp;

        /*before=tail->previous;
        before->next=NULL;*/

    }


    void deleteat(int position){//Function to delete the element at a given position in the linked list
        node *temp=new node;
        node *prev=new node;
        node *nxt=new node;
        temp=head;
        node *n=new node;
        n=head;
        int number=0;
        while(n->next!=head){//loop to count the number of elements
            number++;
            n=n->next;
        }number++;
        if(position>number){
            cout<<"Deletion not possible";
        }
        else if(position==1){
            node* x=head;
            head=head->next;
            head->previous=tail;
            tail->next=head;
            delete x;
        }
        else if(position==number){
            deletex();
        }
       else{ for(int i=1;i<position;i++){
            prev=temp;
            temp=temp->next;
        }
        nxt=temp->next;
        prev->next=nxt;
        nxt->previous=prev;
        delete temp;
        }
    }
};
int main(){
    int a,b,c,d,e,f;
    linkedlist n;
    cout<<"Add node";
    cin>>a;
    n.addnode(a);
    cout<<"Add node";
    cin>>d;
    n.addnode(d);
    cout<<"Add node";
    cin>>e;
    n.addnode(e);
    n.display();
    cout<<"Insert at with data";
    cin>>b>>c;
    n.insertn(b,c);
    n.display();
    cout<<"Delete at ";
    cin>>f;
    n.deleteat(f);
    n.display();
    cout<<endl;
    n.deletex();
    n.display();
    return 0;
}

