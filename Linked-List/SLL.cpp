#include<iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

void addAtTail(int data, Node* &head){
    Node * n = new Node(data);
    if(head == NULL){
        head = n;
        return;
    }

    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void addAtHead(int data, Node* &head){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

int lengthList(Node* &head){
    Node* temp = head;
    int count(0);
    while (temp!= NULL)
    {
        temp= temp ->next;
        count++;
    }
    return count;
}

void addAnyWhere(int data,int at, Node* &head){
    Node* n = new Node(data);
    Node* temp = head;
    int now = 1;
    while(now != at - 1){
        temp = temp->next;
        now++;
    }
    Node* store = temp -> next;
    temp -> next = n;
    n->next = store;
}

void displayAll(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
bool searchElement(Node* &head, int value){

    Node* temp = head;
    while (temp!= NULL)
    {
        if(temp->data == value){
            return true;
        }
        temp= temp ->next;
    }
    
    return false;
}



void deleteNode(Node* &head, int key){
    Node* temp = head;

    //1st Case if ll in empty
    if(temp == NULL){
        cout<<"LinkedList is Empty"<<endl;
        return;
    }

    //2nd Case if deleting the head Node
    if(head -> data == key){
        temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    //3rd Case Deleting the Key node

    while (temp != NULL)
    {
        //4th Case if key element not present
        if(temp -> next == NULL){
            cout<<endl<<"key element is not Present";
            return;
        }

        if(temp -> next -> data == key){
            Node* tempD = temp -> next;
            temp -> next = tempD-> next;
            delete tempD;
            return;
        }
        temp = temp -> next;
    }
    



}

int main(){

    Node* head = NULL;
    cout<<"Enter how many nodes you want to create: ";
    int numberOfNodes;
    cin>>numberOfNodes;
    for(int i = 0; i < numberOfNodes; i++){
        cout<<"Where do you want to add t:tail, h:head, a:atapos"<<endl;
        char where;
        cin>>where;
        if(where == 't'){
            int data;
            cout<<"Enter your value at tail : ";
            cin>>data;
            addAtTail(data, head);
        }
        else if(where == 'h'){
            int data;
            cout<<"Enter your value at head : ";
            cin>>data;
            addAtHead(data, head);
        }
        else{
            int at;
            cout<<"At what place: ";
            cin>>at;
            if(at > lengthList(head)){
                cout<<"You cannot insert at " <<at<<" place in ll:: Bad LinkedList";
            }
            else{
                int data;
                cout<<"Enter your value at "<<at<<" place : ";
                cin>>data;
                addAnyWhere(data, at, head);
            }
        }

    }
    displayAll(head);
    char test;
    cout<<"Want to try other operations ? Press y: yes and n: no"<<endl;
    cin>>test;
    if(test == 'y'){
        cout<<"Enter element you want to search"<<endl;
        int ele ;
        cin>> ele;
        if(searchElement(head, ele))cout<<"Element is present"<<endl;
        else cout<<"Element is not present"<<endl;

        cout<<"Lenght of list is : ";
        cout<<lengthList(head)<<endl;

        cout<<"Want to delete a node? Press y:yes and n:no ->";
        char nodeDel;
        cin>>nodeDel;
        if(nodeDel == 'y'){
            cout<<"Enter element you want to delete:";
            int key;
            cin>>key;

            deleteNode(head,key);
            displayAll(head);
        }
    }
    return 0;
}