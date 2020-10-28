
#include <bits/stdc++.h>
#include<iostream>
using namespace std; 
  
//ABEHI

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
int size = 0; 

int getSize(Node* head)  
{  
    int count = 0;
    Node* currentNode = head;  
    while (currentNode != NULL)  
    {  
        count++;  
        currentNode = currentNode->next;  
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




void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        cout << " " << head->data; 
        head = head->next; 
    } 
    cout << endl; 
} 
  
// Driver Code 
int main() 
{ 
    Node* head = NULL; 
    head = getNode(5); 
    head->next = getNode(4); 
    head->next->next = getNode(3); 
    head->next->next->next = getNode(2); 
  
    size = 4; 
  
    cout << "Linked list before editted: "; 
    printList(head); 
    
    insertFront(&head, 20);
    cout << "Insert front: ";
    printList(head); 
    
    cout << "Delete second data from front: ";
    deleteSecFront(&head);
    printList(head);

    
    insertMid(&head, getSize(head), 20);
    cout << "Insert mid: ";
    printList(head);
    
//    cout << "Delete MId: ";
//    head = deleteMid(head); 
  
//    cout << "Linked List after deletion of middle\n"; 
//    printList(head); 
    
    
  
    return 0; 
} 
