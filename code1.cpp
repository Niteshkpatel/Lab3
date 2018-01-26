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
        temp->next = NULL;
        if(head==NULL){//Checks if the node is empty
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->previous=tail;
            tail=temp;
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
        while(n!=NULL){//loop to count the number of elements
            number++;
            n=n->next;
        }
        if(position>(number+1)){
            cout<<"Linked List does not have that many elements.";
        }
        else if(position==1){
            temp->next=head;
            temp->previous=NULL;
            head->previous=temp;
            head=temp;
        }
        else if(position==number+1){
            temp->next=NULL;
            temp->previous=tail;
            tail->next=temp;
            temp=tail;
        }
        else{
        for(int i=1;i<position-1;i++){
            current=current->next;
        }
        temp->next=current->next;
        temp->previous=current;
        (temp->next)->previous=temp;
        current->next=temp;

    }}

    void display(){//function to display the elements i the linked list
        node *temp=new node;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;

        }
    }
    void deletex(){//Function to delete the last  element in the linked list
        //node *before=new node;
        node *temp=new node;
        temp=tail;
        delete temp;
        tail=tail->previous;
        tail->next=NULL;
        /*before=tail->previous;
        before->next=NULL;*/

    }


    void deleteat(int position){//Function to delete the element at a given position in the linked list
        node *temp=new node;
        node *previous=new node;
        node *next=new node;
        temp=head;
        node *n=new node;
        n=head;
        int number=0;
        while(n!=NULL){//loop to count the number of elements
            number++;
            n=n->next;
        }
        if(position>number){
            cout<<"Deletion not possible";
        }
        else if(position==1){
            head=head->next;
            delete head->previous;
            head->previous=NULL;
        }
        else if(position==number){
            deletex();
        }
       else{ for(int i=1;i<position;i++){
            previous=temp;
            temp=temp->next;
        }
        next=temp->next;
        previous->next=next;
        next->previous=previous;
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

