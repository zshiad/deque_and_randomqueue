#ifndef RANDOMIZEDQUEUE
#define RANDOMIZEDQUEUE
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename Item>
class RandIterator{
public:
  RandIterator(){
    i_array= new Item[1];
    newarray= new Item[1];
  }
  RandIterator(Item* array,int num):randsize(num),i_array(array),index(0){
    newarray=new Item[randsize];
    for(int i=0;i<randsize;++i){
      newarray[i]=array[i];
    } 
    for(int i=0;i<randsize;i++){
      int j= rand()%(randsize-i);
      Item temp=newarray[j];
      newarray[j]=newarray[randsize-i-1];
      newarray[randsize-i-1]=temp; 
    }
  }
  RandIterator(const RandIterator& iterator):randsize(iterator.get_randsize()){
    i_array=iterator.get_arrayptr();
    index=iterator.get_index();
    Item* temp=iterator.get_newarrayptr();
    newarray=new Item[randsize];
    for(int i=0;i<randsize;++i){
      newarray[i]=temp[i];
    } 
  };
  ~RandIterator(){delete []newarray;};
  int get_randsize()const{return randsize;}
  int get_index()const{return index;}
  Item* get_arrayptr()const{return i_array;}
  Item* get_newarrayptr()const{return newarray;}
  RandIterator& operator=(const RandIterator& iterator){
    Item * del_original= this->newarray;
    randsize=iterator.get_randsize();
    i_array=iterator.get_arrayptr();
    index=iterator.get_index();
    Item* temp=iterator.get_newarrayptr();
    newarray=new Item[randsize];
    for(int i=0;i<randsize;++i){
      newarray[i]=temp[i];
    }
    delete []del_original; 
    return *this;
  }
  
  RandIterator& operator++(){
    if(index<randsize-1){index++;}
    return *this;
  }
  RandIterator operator++(int){
    RandIterator temp(*this);
    if(index<randsize-1){index++;}
    return temp;
  }
  RandIterator& operator--(){
    if(index>0){index--;}
    return *this;
  }
  RandIterator operator--(int){
    RandIterator temp(*this);
    if(index>0){index--;}
    return temp;
  }
  Item& operator *(){return newarray[index];}
  Item* operator-> ()const {return &newarray[index];}
  
private:
  Item *i_array;
  int randsize;
  Item* newarray;
  int index;
};

template <typename Item> 
class RandomizedQueue {
 public: 
   typedef RandIterator<Item> Iterator;
   RandomizedQueue();          // construct an empty randomized queue
   bool isEmpty();             // is the queue empty?
   int size();                 // return the number of items on the queue
   void enqueue(Item item);    // add the item
   Item dequeue();             // delete and return a random item
   Item sample();              // return (but do not delete) a random item
   Iterator iterator();        // return an iterator that returns the items in random order
   ~RandomizedQueue();
private:
  Item* array;
  int randsize;
  int maxsize;
};


template <typename Item> 
RandomizedQueue<Item>::RandomizedQueue(){
  maxsize=1;
  array=new Item[maxsize];
  randsize=0;
  
}

template <typename Item> 
bool RandomizedQueue<Item>::isEmpty(){
  if(randsize==0){return 1;}
  else{return 0;}
}

template <typename Item> 
int RandomizedQueue<Item>::size(){
  return randsize;
}

template <typename Item> 
void RandomizedQueue<Item>::enqueue(Item item){
  if(randsize>=maxsize){
    maxsize=maxsize*2;
    Item* temp1=array;
    Item* temp2=new Item[maxsize];
    for(int i=0;i<randsize;++i){
      temp2[i]=temp1[i];
    }
    array=temp2;
    delete []temp1;
  }
  array[randsize]=item;
  randsize++;
}


template <typename Item> 
Item RandomizedQueue<Item>::dequeue(){
  Item item;
  if(randsize>=1){
    int index=rand()%randsize;
    item=array[index];
    array[index]=array[randsize-1];
    randsize--;
  }
  else{
    cout<<"the RandomizedQueue is empty"<<endl;
  }
  if(2*randsize<=maxsize){
    maxsize=maxsize/2;
    Item* temp1=array;
    Item* temp2=new Item[maxsize];
    for(int i=0;i<randsize;++i){
      temp2[i]=temp1[i];
    }
    array=temp2;
    delete []temp1; 
  }
  return item;
}

template <typename Item> 
Item RandomizedQueue<Item>::sample(){
  Item item;
  if(randsize>=1){
    int index=rand()%randsize;
    item=array[index];
  }
  else{
    cout<<"the RandomizedQueue is empty"<<endl;
  }
  return item;
}

template <typename Item>
typename RandomizedQueue<Item>::Iterator RandomizedQueue<Item>::iterator(){
  RandomizedQueue<Item>::Iterator itr(array,randsize);
  return itr;
}

template <typename Item> 
RandomizedQueue<Item>::~RandomizedQueue(){
delete []array;
}
#endif 
