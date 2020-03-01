#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){

        this -> data = data;
        next = NULL;    
    }
};

/* insertBeginning() function takes two parameters, one is double pointer of Node type which will basically hold the reference of head
   and another one is the data in the node that will be pass directly to the constructor */

// Time Complexity: O(1)
void insertBeginning(Node **head, int x){
    
     Node *newNode = new Node(x);
     newNode -> next = (*head);
     (*head) = newNode; 

}

/* This function add the node at the end of the linked list */
// Time Complexity: O(n)
void insertEnd(Node **head, int x){

    Node *ptr = (*head);
    Node *newNode = new Node(x);

    while(ptr -> next != NULL)
        ptr = ptr -> next;

    ptr -> next = newNode;    

}

/* This Function delete the first nodeof the linked list*/
// Time Complexity: O(1)
void deleteBeginning(Node **head){

    if(*head == NULL)
        return;
    Node *ptr = (*head);

    (*head) = (*head) -> next;
    delete ptr;    
}

/*This function basically delete the last node of the linked list*/
// Time complexity : O(n)
void deleteEnd(Node **head){

    if(*head == NULL)
        return;

    Node *ptr = (*head);

    while(ptr -> next -> next != NULL)
        ptr = ptr -> next;

     Node *temp = ptr -> next;
     ptr -> next = NULL;
     delete temp;   

}

/*This function is used to display all the nodes in the LinkedList */
// Time Complexity: O(n)
void displayLinkedList(Node *head){

    while(head != NULL){

        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;

}


int main() {
    
    Node (*head) = NULL;

    insertBeginning(&head, 10);
    insertBeginning(&head, 20);
    insertBeginning(&head, 30);

    displayLinkedList(head);

    insertEnd(&head, 40);
    displayLinkedList(head);


    deleteBeginning(&head);
    displayLinkedList(head);

    deleteEnd(&head);
    displayLinkedList(head);

    return 0;
}