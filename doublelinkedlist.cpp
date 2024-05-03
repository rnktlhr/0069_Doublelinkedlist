#include <iostream>
#include <string>
using namespace std;


struct Node{
    int noMhs;
    string name;
    Node *next;
    Node *prev;
};

Node *START = NULL;

void addNode(){
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode ->name;

    if (START == NULL || newNode ->noMhs <= START->noMhs){
        if (START != NULL && newNode ->noMhs == START ->noMhs){
            cout << "\033[31Duplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
       newNode->next = START;
       if(START != NULL){
         START->prev = newNode;
       }
       newNode->prev = NULL;
       START =newNode;
    }
    else{
        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && current->noMhs < newNode->noMhs){
            previous = current;
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = previous;

        if(current!= NULL){
            current->prev =newNode;
        }

        if (previous != NULL){
            previous->next = newNode;
        }
        else{
            START = newNode;
        }
    }
}

bool search(int rollNo, Node **previous, Node **current){
    *previous = NULL;
    *current = START;
    while(*current != NULL && (*current)->noMhs != rollNo){
        *previous = *current;
        *current = (*current)->next;
    }
    return;
}

void deleteNode(){
    Node *previous, *current;
    int rollNo;
   
   if (START == NULL){
    cout << "List is empty" << endl;
    return;
   }

   current = START;
   previous = NULL;

   while(current != NULL && current->noMhs != rollNo){
    previous = current;
    current = current->next;
   }

   if(current == START){
    cout << "\003[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
    return;
   }

   if(current == START){
    START = START->next;
    if(START != NULL){
        START->prev = NULL;
    }
   }
   else{
    previous->next = current->next;
    if(current->next != NULL){
        current->next->prev = previous;
    }
   }

   delete current;
   cout << "\x1b[32Record with roll number " << rollNo << "delete\x1b[0m" << endl;
}

bool listempty(){
    return; (START == NULL);
}

void trevese(){
    
}