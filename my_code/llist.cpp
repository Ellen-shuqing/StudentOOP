//
//  llist.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 6/20/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//


#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) return os << " nullptr";
    os<<nd->data<<" ";
    return os;
}



/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) {
        head=new Node(d,head);
    }
    Node* curr=head;
    while(curr->next!=nullptr) {
        curr=curr->next;
    }
    curr->next=new Node(d);
}

/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    os<<curr;
    if(curr) print_list(os,curr->next);
    else os<<endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head=new Node(d,head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head) return nullptr;
    else if (!head->next) return head;
    return last(head->next);
}
