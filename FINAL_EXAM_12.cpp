#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
  
//A B E H I

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
int size = 0; 


int getSize(Node* head)  
{  
    int count = 0;   
    Node* current = head;
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  


Node* getNode(int data) 
{ 
    Node* newNode = new Node(); 
  
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 




void insertFront(Node** current, int data) 
{ 
	int pos = 1;
	
    if (pos < 1 || pos > size + 1) 
        cout << "Invalid position!" << endl; 
    else { 
  
        while (pos--) { 
  
            if (pos == 0) { 
  
                Node* temp = getNode(data); 
  
                temp->next = *current; 

                *current = temp; 
            } 
            else
              current = &(*current)->next; 
        } 
        size++; 
    } 
}


void deleteSecFront(struct Node **head_ref) 
{ 
	int position = 1;
	
   if (*head_ref == NULL) 
      return; 
  
   struct Node* temp = *head_ref; 
  
    if (position == 0) 
    { 
        *head_ref = temp->next;  
        free(temp);               
        return; 
    } 
  
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct Node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
} 
void insertMid(Node** current, int length, int data) 
{ 
	int pos = (length / 2) + 1;
	
    if (pos < 1 || pos > size + 1) 
        cout << "Invalid position!" << endl; 
    else { 
  
        while (pos--) { 
  
            if (pos == 0) { 
  
                Node* temp = getNode(data); 
  
                temp->next = *current; 

                *current = temp; 
            } 
            else
              current = &(*current)->next; 
        } 
        size++; 
    } 
}

//void deleteMid(struct Node *head) 
//{  
//    if (head == NULL) 
//        return; 
//    if (head->next == NULL) { 
//        delete head; 
//        return; 
//    } 
//    struct Node* copyHead = head; 
//   
//    int count = getSize(head); 
//  
//    int mid = count / 2; 
//  
//    while (mid-- > 1) { 
//        head = head->next; 
//    } 
//  
//    head->next = head->next->next; 
//  
//    return copyHead;  
//}

void add(Node** current, int length, int data) 
{ 
	int pos = length + 1;
	
    if (pos < 1 || pos > size + 1) 
        cout << "Invalid position!" << endl; 
    else { 
  
        while (pos--) { 
  
            if (pos == 0) { 
  
                Node* temp = getNode(data); 
  
                temp->next = *current; 

                *current = temp; 
            } 
            else
              current = &(*current)->next; 
        } 
        size++; 
    } 
}



void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        cout << " " << head->data; 
        head = head->next; 
    } 
    cout << endl; 
}


struct Node* middle(Node* begin, Node* end) 
{ 
    if (begin == NULL) 
        return NULL; 
  
    struct Node* slow = begin; 
    struct Node* fast = begin -> next; 
  
    while (fast != end) 
    { 
        fast = fast -> next; 
        if (fast != end) 
        { 
            slow = slow -> next; 
            fast = fast -> next; 
        } 
    } 
  
    return slow; 
} 

void sorted(struct Node**, struct Node*); 

void insertion(struct Node **head_ref) 
{ 
    struct Node *sort = NULL; 
  
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        struct Node *next = current->next; 
  
        sorted(&sort, current); 
  
        current = next; 
    } 
  
    *head_ref = sort; 
}


bool linear(Node* head, int x)  
{  
    Node* current = head;   
    
    while (current != NULL)  
    {  
        if (current->data == x){
        cout << "Current data: " << current->data << endl;
            return true;
        }
        cout << "Current data: " << current->data << endl;
        current = current->next; 
    }  
    return false;  
}

void sorted(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
}



  

struct Node* binary(Node *head, int value) 
{ 
    struct Node* begin = head; 
    struct Node* end = NULL; 
  
    do
    { 
        
        Node* mid = middle(begin, end); 
        
        cout << "Current data: " << mid->data << endl;
        
    
        if (mid == NULL) 
            return NULL; 
  
        
        if (mid -> data == value) 
            return mid; 
  
        
        else if (mid -> data < value) 
            begin = mid -> next; 
  
       
        else
            end = mid; 
  
    } while (end == NULL || 
             end != begin); 
  
     
    return NULL; 
} 
  
// Driver Code 
int main() 
{ 
    
    Node* head = NULL; 
    
    add(&head, getSize(head), 2);
    add(&head, getSize(head), 5);
    add(&head, getSize(head), 33);
    add(&head, getSize(head), 67);
    add(&head, getSize(head), 12);
    add(&head, getSize(head), 4);
    add(&head, getSize(head), 8);
    add(&head, getSize(head), 1);
    add(&head, getSize(head), 23);
    add(&head, getSize(head), 10);
    
    cout << "Linked list: " << endl;
    printList(head);
    
    cout << endl;
    
    cout << "Linear Search " << endl;
    if (linear(head, 23) == false){
    	cout << "The valueis unpresent" << endl;
	}
	else{
		cout << "The Data is Present" << endl;
	}
    
    cout << endl;
    
    insertion(&head);
    cout << "Sorted list: " << endl;
    printList(head);
    
    cout << "Binary Search " << endl;
    if (binary(head, 23) == NULL){
        cout << "Value Unpresent" << endl;
    }
    else{
        cout << "The Data is Present" << endl;
    }
  
    return 0; 
} 
