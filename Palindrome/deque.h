#ifndef DEQUE
#define DEQUE
#include <iostream>
using namespace std;

template <typename Item>
struct Node{
public:
  Item item;
  Node* next;
  Node* prev;
};

template <typename Item>
class DequeIterator{
  typedef Node<Item>* Nodeptr;
public:
  DequeIterator(){
    Nodeptr node=new Node<Item>;
    ptr=node;
  }
  DequeIterator(Nodeptr ptr):ptr(ptr){}
  DequeIterator(const DequeIterator& iterator):ptr(iterator.getNoteptr()){};
  ~DequeIterator(){delete node;};
  Nodeptr getNoteptr()const{return ptr;}
  DequeIterator& operator=(const DequeIterator& iterator){
    ptr=iterator.getNoteptr();
    return *this;
  }
  
  DequeIterator& operator++(){
    if(!ptr->next==NULL){ptr=ptr->next;}
    return *this;
  }
  DequeIterator operator++(int){
    DequeIterator temp(ptr);
    if(!ptr->next==NULL){ptr=ptr->next;}
    return temp;
  }
  DequeIterator& operator--(){
    if(!ptr->prev==NULL){ptr=ptr->prev;}
    return *this;
  }
  DequeIterator operator--(int){
    DequeIterator temp(ptr);
    if(!ptr->prev==NULL){ptr=ptr->prev;}
    return temp;
  }
  bool  operator==(const DequeIterator& iterator)const{
    if(ptr==iterator.getNoteptr()){return 1;}
    else{return 0;}
  }
  bool  operator!=(const DequeIterator& iterator)const{
    if(ptr==iterator.getNoteptr()){return 0;}
    else{return 1;}
  }
  Item& operator *(){return ptr->item;}
  Nodeptr operator-> ()const {return ptr;}
  
private:
  Nodeptr ptr; 
  Nodeptr node;
};

template <typename Item> 
class Deque {
  typedef Node<Item>* Nodeptr;
 public: 
   typedef DequeIterator<Item> Iterator;
   Deque();                    // construct an empty deque
   bool isEmpty();             // is the deque empty?
   int size();                 // return the number of items on the deque
   void addFirst(Item item);   // insert the item at the front of the queue
   void addLast(Item item);    // insert the item at the end of the queue
   Item removeFirst();         // delete and return the first item in queue
   Item removeLast();          // delete and return the last item in queue
   Iterator iterator();        // return an iterator that examines the 
                               // items in order from front to back
   ~Deque();
private:
  Nodeptr head;
  Nodeptr rear;
  int dequesize;
  Nodeptr sentinel;
};



template <typename Item> 
Deque<Item>::Deque(){
  dequesize=0;
  Nodeptr sentinel=new Node<Item>;
  sentinel->next=NULL;
  sentinel->prev=NULL;
  head=sentinel;
  rear=sentinel;
}

template <typename Item> 
bool Deque<Item>::isEmpty(){
  if(dequesize==0){return 1;}
  else{return 0;}
}

template <typename Item> 
int Deque<Item>::size(){
  return dequesize;
}

template <typename Item> 
void Deque<Item>::addFirst(Item item){
  Nodeptr newptr =new Node<Item>;
  newptr->item=item;
  if(dequesize==0){
     newptr->next=NULL;
     newptr->prev=NULL;
     head=newptr;
     rear=newptr;
  }
  else{
  newptr->next=head;
  newptr->prev=NULL;
  head->prev=newptr;
  head=newptr;
  }
  dequesize++;
}

template <typename Item> 
void Deque<Item>::addLast(Item item){
  Nodeptr newptr =new Node<Item>;
  newptr->item=item;
  if(dequesize==0){
     newptr->next=NULL;
     newptr->prev=NULL;
     head=newptr;
     rear=newptr;
  }
  else{
  newptr->next=NULL;
  newptr->prev=rear;
  rear->next=newptr;
  rear=newptr;
  }
  dequesize++;
}

template <typename Item> 
Item Deque<Item>::removeFirst(){
  Item item;
  if(dequesize>=2){
  Nodeptr newptr =head;
  item=head->item;
  (head->next)->prev=NULL;
  head=head->next;
  delete newptr;
  dequesize--;}
  else if(dequesize==1){
  Nodeptr newptr =head;
  item=head->item;
  head=sentinel;
  rear=sentinel;
  delete newptr;
  dequesize--;
  }
  else{
    cout<<"the deque is empty"<<endl;
  }
  return item;
}

template <typename Item> 
Item Deque<Item>::removeLast(){
  Item item;
  if(dequesize>=2){
  Nodeptr newptr =rear;
  item=rear->item;
  (rear->prev)->next=NULL;
  rear=rear->prev;
  delete newptr;
  dequesize--;}
  else if(dequesize==1){
  Nodeptr newptr =rear;
  item=rear->item;
  head=sentinel;
  rear=sentinel;
  delete newptr;
  dequesize--;
  }
  else{
    cout<<"the deque is empty"<<endl;
  }
  return item;
}

template <typename Item>
typename Deque<Item>::Iterator Deque<Item>::iterator(){
  Deque<Item>::Iterator itr(head);
  return itr;
}

template <typename Item> 
Deque<Item>::~Deque(){
  while(!isEmpty()){
    Nodeptr temp=head;
    head=head->next;
    delete temp;
    dequesize--;
  }
  delete sentinel;
}
#endif 

