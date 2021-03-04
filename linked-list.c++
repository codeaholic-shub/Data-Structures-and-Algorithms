/*
1. Problems with Array Data Structures
2. Introduction to Linked List
3. Simple Linked List Representation on C++
4. Traversing a Linked List in C++
5. Recursive Traversal of Singly Linked List
6. Insert at begin and End of Singly Linked List
7. Delete First Node of Singly Linked List
8. Delete Last of Singly Linked List
9. Insert at given position in Singly Linked List
10. Search in a Linked List ( Iterative and Recursive )
11. Doubly Linked List in C++
12. Singly Vs Doubly Linked List ( Advantages and Disadvantages )
13. Insert at begin and End of Doubly Linked List 
14. Reverse a Doubly Linked List
15. Delete Head of a Doubly Linked List
16. Delete Last of a Doubly Linked List
17. Circular Linked List in C++
18. Circular Linked List ( Advantages and Disadvantages )
19. Circular Linked List Traversal in C++
20. Insert at begin of Circular Linked List
21. Insert at the end of Circular Linked List
22. Delete Head of Circular Linked List
23. Delete kth of a Circular Linked List
24. Circular Doubly Linked List
25. Sorted Insert in a Singly Linked List
26. Middle of Linked List
27. Nth Node from end of a Linked List
28. Reverse a Linked list iterative
29. Recursive Linked List (Part -1)
30. Recursive Linked List(Part-2)
31. Remove Duplicates from a sorted singly linked list
32. Reverse a Linked List in groups of size k
33. Detect Loop
34. Detect Loop using floyd cycle detection
35. Detect and remove loop in linked list
36. Delete node with only pointer given to it
37. Segregate even odd nodes of a linked list
38. Intersection of Two Linked List
39. Pairwise swap nodes of linked list
40. Clone a linked list using a random pointer
41. LRU Cache Design 
42. Merge two sorted linked lists
43. Palindrome linked list
*/


//1. Problems with Array Data Structures
// Linked List is a liner data structure , in which the elements aren't stored at contiguos at memory locations

// int arr[n]; (Stack)
// int arr[100] (Stack)
// int *arr=new int[n] (Dynamic Memory Allocation)
// vector <int> v (Dynamic Sized Allocation)

// Problems
1. Either Size is fixed and pre-allocated( in both fixed and variable sized arrays ), OR the worst case insertion
at the end Theta(N)
2. Insertion in the middle(or in the beginning) is costly
3. Deletion from the middle(or in the beginning) is costly
4. Implementation of data structures like queue and deque is complex with arrays


-> Implementation of Round Robin scheduling
-> Given a sequence of items , whenever we see an item(x) in the sequence, we need to replace
with 5 instances of another item y.
-> We have multiple sorted sequences and we need to merge them frequently


//2. Introduction to linked list
head -> 10 -> 5 -> 20 -> NULL
-> This idea is to drop the contiguos memory requirements so that insertions, deletions, can happen 
efficiently at the middle also. And, no need to pre-allocate the space( the extra node )


//3. Simple Linked List Representation in C++
head -> 10 -> 20 -> 30 -> NULL
// Memory( Array of Bytes )
struct node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
int main(){
    Node *head= new Node(10);
    Node *temp1= new Node(20);
    Node *temp2= new Node (30);
    temp1 -> next = temp2;
    head -> next= temp1;
    return 0;
}
// Alternate Method 
int main(){
    Node *head= new Node(10);
    head -> next= new Node(20);
    head -> next -> next= new Node(30);
    return 0;
}


// 4. Traversing a Linked List in C++
// I/p - head -> 10 -> 20 -> 30 -> 40 -> NULL , O/p - 10 20 30 40 
// I/p - head -> 10 -> NULL , O/p- 10
// I/p - NULL , O/p - 
// Time- O(n), Auxiliary - O(1)

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr -> data << " ";
        curr= curr -> next;
    }
}
int main(){
    Node *head= new Node(10);
    head ->next = new Node(20);
    head ->next ->next= new Node(30);
    head -> next -> next -> next = new Node(40);
    printlist(head);
    return 0;
}


// 5. Recursive traversal of linked list in C++
// head -> 10 -> 20 -> 30 -> 40 -> NULL
void rPrint(Node *head){
if(head==NULL)return ;
cout<<(head -> data)<<" ";
rPrint(head -> next);
}


// 6. Insertion at beginning of the linked list in C++
struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL:
    }
};
Node insertBegin(Node *head,int data){
    Node *temp=new Node(x);
    temp ->next= head;
    return temp;
}
int main(){
    Node *head=NULL;
    head= insertBegin(head,30);
    head -> next = insertBegin(head,20);
    head -> next -> next = insertBegin(head,10);
    return 0;
}


// 6. Insertion at End of Linked List in C++
Node *insertEnd(Node *head, int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr -> next !=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}


//7.Delete first Node of a Singly Linked List 
// Time Complexity - O(1)
Node *delHead(Node *head){
    if(head==NULL)return NULL;
    else{
        Node *temp=head -> next;
        delete(head);
        return temp;
    }
}


//8. Delete the Last Node in a Singly Linked List
// Time Complexity is Theta(N)
Node *delTail(Node *head){
if(head==NULL)return NULL;
if(head->next==NULL){
    delete(head);
    return NULL;
}
Node *curr=head;
while(curr -> next ->next !=NULL)
curr=curr->next;
delete(curr->next);
curr->next=NULL;
return head;
}


//9. Insertion at given position in singly linked list in C++
Node insertPos(Node *head,int pos,int data){
    Node *temp= new Node(data);
    if(pos==1){
        temp -> next =head;
        return temp;
    }
    Node *curr= head;
    for(int i=1;i<=pos-2 && curr !=NULL ;i++){
        curr=curr->next;
    }
    if(curr==NULL)return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}



// 11. Doubly Linked List in C++
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};
int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head -> next = temp1;
    temp1 -> prev= head;
    temp1 -> next = temp2;
    temp2 -> prev= temp1;
}


//

// 12. Singly Vs Doubly Linked List (Advantages Vs Disadvantages)
//Advantages :-
1. Can be Traversed in Both Directions.
2. A given delete a node in O(1) time with given refernce/pointer to it.
3. Insert/Delete before a given node.
4. Insert/Delete from both ends in O(1) time by maintaining tail.
// Disadvantages 
1. Extra Space for Previous. 
2. Code Becomes more complex.


//13.Insert at begin of a Doubly Linked List
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data=d;
        prev=next=NULL;
    }
};
Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    temp -> next=head;
    if(head!=NULL)
    head->prev=temp;
    return temp;
}


//13. Insert At End of  a Linked List
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data=d;
        prev=next=NULL:
    }
};
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL)
    cout<<curr->data<<" ";
    curr=curr->next;
}
cout<<endl;
}
Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->next=temp2;
    temp1->prev=head;
    temp2->prev=temp1;
    head=insertEnd(head,40);
    printlist(head);
    return 0;
}


//14. Reverse a Doubly Linked List
Node *reverseDll(Node *head){
if(head==NULL || head->next==NULL)return head;
Node *prev=NULL; curr=head;
while(curr != NULL ){
    prev=curr->prev;
    curr->prev=curr->next;
    curr->next=prev;
    curr=curr->prev;
}
return prev->prev;
}


// 15. Delete Head of a Doubly Linked List
// Time Complexity = Theta ( 1 )
Node *delHead(Node *head){
    if(head== NULL )return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return NULL;
}
}


//16. Delete Last of a Circular Linked List
// Time Complexity is Theta(N)
// If there is tail Pointer ,then there is Theta(1)
Node *delLast(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
    return head;
}


// 17. Circular Linked List in C++
struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
int main(){
    Node *head=new Node(10);
    head->next=new Node(5);
    head->next->next=new Node(15);
    head->next->next->next=new Node(20);
    head->next->next->next->next=head;
    return 0;
}


//18. Circular Linked List ( Advantages and Disadvantages )
// Advantages :-
1. We Can traverse the Whole list from any Node
2. Implementation of algorithms like round robin
3. We can insert at the beginning and end by just maintaining one tail pointer/refernce

// Disadvantages:-
1. Implementation of operations become complex


// 19. Circular Linked List Traversal in C++
// For Loop
void prinlList(Node *head){
    if(head==NULL)return ;
    cout<<head->data<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
    cout<<p->data<<" ";
}

//while Loop
void printList(Node *head){
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

//20. Insert At Begin of Circular Linked List in C++
// Naive Solution - O(N) , Efficient Solution - O(1)

// Naive Solution
Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        Node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
    }
    return temp;
}

// Efficient Solution
Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}


//21. Insert at End of Circular linked list in C++
// Naive - O(N) , Efficient - O(1)

// Naive 
Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        Node *curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp->next;
        temp->next=head;
        return head;
    }
}


// Efficient Solution
Node *insertEnd(Node *head,int data){
    Node *temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=temp->data;
        temp->data=head->data;
        head->data=t;
        return temp;
    }
}