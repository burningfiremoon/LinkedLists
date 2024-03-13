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
      // Node(prev, next, capacity)
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
         delete  current;
      }
   }
   bool isEmpty(){ return size==0 ;}
   int get_size(){ return size ;}

   // my own method, not needed for class
   void connectionTest(){
      Node * cursor = front;
      while(cursor != back){
         cursor = cursor->next;
         cout << "tally ";
      }
      cout << "front connected to back" <<endl;
      while(cursor != front){
         cursor = cursor->prev;
         cout << "tally ";
      }
      cout << "back connected front" << endl;
   }

   bool insert(T item){ //Done
      // inserts item into the list, if it is not there already
      // returns true if inserted; false if it was already there
      //
      // IMPLEMENT THIS
      //

      if (nodeCount == 0){
         Node* temp = new Node(front, back, nodeCapacity);
         front->next = temp;
         back->prev = temp;
         nodeCount++;
         size++;
         return temp->insert(item);
      }

      bool returnValue;
      Node * cursor = front-> next;

      while(cursor != back && cursor->getMax() < item){
         cursor = cursor->next;
      }

      if ((item < cursor->getMin() && cursor->prev != front) || cursor == back){
         cursor = cursor->prev;
      }

      returnValue = cursor->insert(item);

      // split node into 2 if full
      // add the node to the right b/c less movement
      // if returnValue is true then size increases by 1 and split full node
      if (returnValue){
         size++;
      }

      if (cursor->getSize() == cursor->getCapacity()){
         // create new node to the right
         Node* temp = new Node(cursor, cursor->next, nodeCapacity);
         temp->prev->next = temp;
         temp->next->prev = temp;
         nodeCount++;

         // move bottom half of cursor to temp
         for (int i = 0; i < nodeCapacity/2; i++){
            T movedItem = cursor->getMax();
            temp->insert(movedItem);
            cursor->remove(movedItem);
         }

      }

      return returnValue;
   ; }

   bool find(T item){ //Done
      // searches for item in the list
      // returns true if found; false otherwise 
      //
      // IMPLEMENT THIS 
      //
      Node * cursor = front-> next;
      while(cursor != back && cursor->getMax() < item){
         cursor = cursor->next;
      }

      return cursor->find(item);
   ; }

   bool remove(T item){ // Done
      // removes item from the list 
      // returns false if the item was not there; true if it was
      //
      // IMPLEMENT THIS
      //
      bool returnValue;
      Node * cursor = front-> next;
      while(cursor != back && cursor->getMax() < item){
         cursor = cursor->next;
      }
      // corner case removed value is greater than greatest value
      if (cursor == back){
         return false;
      }

      returnValue = cursor->remove(item);

      if (returnValue){
         size--;
      }

      

      // remove repeated checks to reduce resused conditions
      if (cursor->getSize() >= nodeCapacity/2 || cursor->prev == front){
         return returnValue;
      }

      if (cursor->prev->getSize() > nodeCapacity/2){
         int temp = cursor->prev->getSize();
         for (int i = 0; i < ((temp - nodeCapacity/2)/2); i++){
            // move cursor->prev to cursor
            T moving = cursor->prev->getMax();
            cursor->insert(moving);
            cursor->prev->remove(moving);
         }
      } else if (cursor->prev->getSize() <= nodeCapacity/2 ){
         // move all cursor to cursor->prev
         int tempNum = cursor->getSize();
         for (int i = 0; i < tempNum; i++){
            T moving = cursor->getMax();
            cursor->prev->insert(moving);
            cursor->remove(moving);
         }
         // connect cursor->prev to cursor->next and vice versa
         cursor->next->prev = cursor->prev;
         cursor->prev->next = cursor->next;
         // delete cursor
         delete cursor;
         nodeCount--;
      }


      return returnValue;
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
      cout << " >" << endl;
   }

   void ddisplay(){
      cout << "This is ddisplay(): \n";
      cout << "size: " << size << " nodeCount: " << nodeCount << endl;
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){
         cout << " <";
         cursor -> display() ; 
         cursor = cursor-> next ;
         cout <<" > ";
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
            return data[size - 1] ; 
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
            data[0] = item;
            size++;
            return true;
         }

         int index = size-1; // start from the end index
         // sequential search and insert
         // shift larger data 1 to the right
         while (item < data[index] && index >= 0){
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
         // quick max check for transfer removal
         if (item == data[size-1]){
            size--;
            return true;
         }

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
            data[i] = data[i+1];
         }
         size--;
         return true;
      ;}
      void display(){ // Done
         // print the contents of this list 
	      // 
         // IMPLEMENT THIS
	      //
         for (int i = 0; i < size; i++){
            cout << " " << data[i] << ",";
         }
      ;}
   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};
