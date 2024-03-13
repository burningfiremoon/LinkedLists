/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
   OSULL(){

      // set the node capacity  
      nodeCapacity = initNodeCapacity ;

      // make the front and back dummy nodes 
      front = new Node( nullptr, nullptr, nodeCapacity );
      back = new Node( front, nullptr, nodeCapacity );
      front->next = back;

      size = 0 ;
      nodeCount = 0 ; 
   }
   ~OSULL(){
      Node * cursor = front ;
      while( cursor != nullptr ){
         Node * current = cursor ;
         cursor = cursor-> next ;
         delete  current ;
      }
   }
   bool isEmpty(){ return size==0 ;}
   int get_size(){ return size ;}

   bool insert(T item){
      // inserts item into the list, if it is not there already
      // returns true if inserted; false if it was already there
      //
      // IMPLEMENT THIS
      //
      return false;
   ; }

   bool find(T item){ 
      // searches for item in the list
      // returns true if found; false otherwise 
      //
      // IMPLEMENT THIS 
      //
      return false;
   ; }

   bool remove(T item){
      // removes item from the list 
      // returns false if the item was not there; true if it was
      //
      // IMPLEMENT THIS
      //
      return true;
   ; }

   T getMin(){ //Done
      // returns the minimum item in the lise
      // requires: size not 0 
      //
      // IMPLEMENT THIS 
      //
      return front->next->getMin();
    ; } 

   T getMax(){ // Done
      // returns the maximum item in the list
      // requires: size not 0 
      //
      // IMPLEMENT THIS
      //
      return back->prev->getMax();
   ;}

   void display(){
      // prints out the list contents 
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){

         cursor -> display() ; 
         cursor = cursor-> next ;
      }
      cout << " >" ;
   }
      
private:

   class Node{
      public: 
      Node( Node* prev, Node* next, int capacity ){
         // notice that we can use the constructor arguments to 
         // do most o the work of inserting a new node into the list 
         this->prev = prev ;
         this->next = next ;
         this->capacity = capacity ;
         data = new T[capacity] ;
         size = 0 ;
      }


      Node * prev ; // pointer to the previous nodes
      Node * next ; // pointer to the next nodes
      int capacity ; // capacity of this node 
      T * data ; // array of data items in this node 
      int size ; // current number of items in this node 


      int getCapacity(){// return the capacity of this node 
         return capacity; 
      }
      int getSize(){// return the number of items in this node
         return size; 
      }
      T getMin(){// return the smallest item in this node
         // requires: this->size not 0
         if (size != 0){
            return data[0] ; 
         } else{
            return -1;
         }

      }
      T getMax(){// return the largest item in this node 
         // requires: this->size not 0
         if (size != 0){
            return data[size -1] ; 
         } else{
            return -1;
         } 
      }

      bool insert(T item){ //semi finished

         // missing case if array is full!!
         // might not be needed if arrays are never fully full


         // inserts item into this node if it was not already there 
         // returns true if the item was inserted, false otherwise 
	      //
         // IMPLEMENT THIS 
	      //
         // size check is done in the outside insert

         // corner case empty array check
         if (size == 0){
            data[0] == item;
            size++;
            return true;
         }

         int index = size-1; // start from the end index
         // sequential search and insert
         // shift larger data 1 to the right
         while (item < data[index]){
            data[index + 1] = data[index];
            index--;
         }
         // current value is > or = to item

         // if equal
         if (item == data[index]){
            index++;
            while(index < size){
               data[index] = data[index + 1];
               index++;
            }
            return false;
         } else{ // if item is greater than data[index]
            // insert 1 to the right of index
            data[index + 1] = item;
            size++;
            return true;
         }
         return false;
      ;}
      bool find(T item){ //Done
         // searches for item in this node 
         // returns true if found, false otherwise 
	      //
         // IMPLEMENT THIS
	      //
         int left = 0;
         int right = size -1;
         while(left <= right){
            int middle = (right - left)/2 + left;

            if (data[middle] == item){
               return true;
            }

            if (data[middle] < item){
               left = middle + 1;
            } else{
               right = middle -1;
            }
         }
         // number not present
         return false;
      ;}
      bool remove(T item){ //Done
         // remove item from this node
         // returns true if the item was removed, false otherwise 
	      //
         // IMLEMENT THIS
	      //
         int left = 0;
         int right = size -1;
         int index = -1;

         // binary search to find location
         while(left <= right){
            int middle = (right - left)/2 + left;

            if (data[middle] == item){
               index = middle;
               break;
            }

            if (data[middle] < item){
               left = middle + 1;
            } else{
               right = middle -1;
            }
         }
         // if doesn't exist exit return false (not removed);
         if (index == -1){
            return false;
         }
         // move all elements 1 to the left deleting the element in the process
         for (int i = index; i < size-1; i++){
            data[index] = data[index+1];
         }
         size--;
         return true;
      ;}
      void display(){ // Done
         // print the contents of this list 
	      // 
         // IMPLEMENT THIS
	      //
	      //
         cout << "< ";
         for (int i = 0; i<size; i++){
            cout << data[i];
            if (i != size-1){
               cout << ", ";
            }
         }
         cout << " >";
      ;}
   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};
