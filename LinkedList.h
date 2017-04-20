//
//  LinkedList.h
//  LinkedList
//
//  Created by Chris Cushman on 3/17/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;
template <class T> class LinkedList
{
    
private:
    //Node struct used to store each element in the LinkedList
    struct Node
    {

        
        /* Basic Constructor of Node*/
        Node(T newElement, Node* node):next(node),element(newElement){
            
           // element;
            
           // next = node;
            
           // element = newElement;
            
        }
        
        Node* next;//node that the current node points to
        
        T element;//data the current node has stored

        
    };
    
    Node* head; //reference to first node in the linked list
    
    int sizeOfList; //int representing number of nodes in linked list
    
public:
    
    
    /* Default constructor
     * Returns new instance of LinkedList
     */
    LinkedList(){
        
        head = 0;
        
        sizeOfList = 0;
        
    }
    
    /* Constructor using LinkedList instance
     * Takes an instane of LinkedList and copies its values.
     * Parameters: LinkedList other
     * Returns LinkedList instance
     */
    LinkedList(const LinkedList& other){
        
        sizeOfList = 0;
        head = 0;
        
        Node* node = other.head;
        
        
        
        /*Iterates through all of other's nodes and appends the element at each node to this*/
        while((node) != 0){
            
            *this += ((*node).element);
            
            node = node->next;
            
        }
        
        
    }
    
    /* Destructor
     * Deallocates LinkedList instance
     */
    ~LinkedList(){
        
        while(sizeOfList > 0){
            
            removeFirst();//Removes all nodes so that there are no memory leaks
            
        }
        
    }
    
    /* Returns size of LinkedList*/
    int size() const{
        
        return sizeOfList;
        
    }
    
    
    /* Gets the first element from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty
     * Returns: The first element within the LinkedList
     */
    T getFirst() const{
        
        
        if(!head) throw std::runtime_error("LinkedList is empty");
        
        return head->element;
        
        
        
        
    }
    
    /* Gets the last element from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty
     * Returns: The last element within the LinkedList
     */
    T getLast() const{
        
        if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
        
        
        Node* node = head;
        
        while((*node).next != 0){
            //iterate until Node* node is the last node

            node = node->next;
            
        }
        
        return node->element;
        
    }
    
    /* Gets the element at 'index' from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty or if the index is out of bounds
     * Parameters: int index
     * Returns: The element of LinkedList at index
     */
    T get(int index) const{
        
        
        if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
        
        if(index >= sizeOfList || index < 0){
            
            std::ostringstream stm ;
            
            stm <<  "Index " << index << " is out of bounds     size: " << sizeOfList;
            
            throw std::runtime_error(stm.str());
            
        }
        
        
        
        Node* node = head;
        
        for(int x = 0; x < index; x++){
            //iterate until Node* node is the node at 'index'
            node = node->next;
            
        }
        
        return node->element;
        
    }
    /* Adds an element to the front of the current LinkedList instance */
    void add(T element){

        Node* tmp = new Node(element, 0);
        
        Node* node = head;
        
        if(node == 0){
            
            head = tmp;
            
        }else{
            
            for(int x = 0; x < sizeOfList-1; x ++){

                node = node->next;
                
            }
            
            node->next = tmp;
            
        }
        
        sizeOfList++;

    }
    
    /* Removes the first element from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty
     * Returns: The element removed from LinkedList
     */
    T removeFirst(){
        
        if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
        
        
        if(sizeOfList>1){
            //remove head when there are more than one elements in the LinkedList
            Node* node = (*head).next;
            
            T temp = head->element;
            
            delete head;
            
            head = node;
            
            sizeOfList --;
            
            return temp;
            
        }else{
            //remove head when there is one element in the LinkedList
            T temp = head->element;
            
            delete head;
            
            head = 0;
            
            sizeOfList = 0;
            
            return temp;
            
        }
        
    }
    
    /* Removes the last element from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty
     * Returns: The element removed from LinkedList
     */
    T removeLast(){
        

            if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
            

        
        
        Node* node = head;
        
        for(int x = 0; x< sizeOfList-1; x++){
            // iterates until Node *node is the last node
            node = node->next;
            
        }
        
        T temp = node->element;
        
        delete node;
        
        sizeOfList--;
        
        return temp;
        
    }
    
    /* Removes the element at 'index' from the current LinkedList instance
     * Throws runtime error if the LinkedList is empty or if the index is out of bounds
     * Parameters: int index
     * Returns: The element of LinkedList removed
     */
    T remove(int index){
        
        
        if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
        
        if(index >= sizeOfList || index < 0){
            
            std::ostringstream stm ;
            
            stm <<  "Index " << index << " is out of bounds     size: "<< sizeOfList;
            
            throw std::runtime_error(stm.str());
            
        }
        
        
        T temp = get(index);
        
        Node* node = head;
        
        if(index == 0){
            //if the index is 0, remove the head
            node = node->next;
            
            delete head;
            
            head = node;
            
            sizeOfList--;
            
            return temp;
            
        }else{
            // if the index isn't 0, iterate to the desired node and link the node before it with the node after it, while deleting the desired node
            for(int x = 0; x < index-1; x++){
                
                node = node->next;
                
            }
            
            Node* newNext = (node->next)->next;
            
            delete node->next;
            
            node->next = newNext;
            
            sizeOfList--;
            
            return temp;
            
        }
        
    }
    
    /* Sets the element at 'index' to 'newElement' in the current LinkedList instance
     * Throws runtime error if the LinkedList is empty or if the index is out of bounds
     * Parameters: int index, T newElement
     */
    void set(int index, T newElement){
        
        
        if(sizeOfList == 0) throw std::runtime_error("LinkedList is empty");
        
        if(index >= sizeOfList || index < 0){
            
            std::ostringstream stm ;
            
            stm <<  "Index " << index << " is out of bounds     size: "<< sizeOfList;
            
            throw std::runtime_error(stm.str());
            
        }
        
        cout << "got this far" << endl;
        
        Node* node = head;
        

        if(index == 0){
            //if the index is 0, set the head
            node->element = newElement;
            
        }else{
            // if the index isn't 0, iterate to the desired node and set its value to newElement
            for(int x = 0; x < index; x++){
                cout << "node element " << node->element << endl;
                node = node->next;
                
            }
            
            node->element = newElement;

            
        }
        
    }

    
    
    /* Converts the LinkedList to a vector of the LinkedList's type
     * Returns: The vector made from this instance of LinkedList
     */
    vector<T> toArray() const{
        
        vector<T> vector(sizeOfList);
        
        Node* node = head;
        
        for(int x = 0; x< sizeOfList; x++){
            
            vector[x] = node->element;
            
            node = node->next;
            
        }
        
        return vector;
        
    }
    
    /* Returns whether or not this instance of LinkedList is equal to another instance of LinkedList
     * Iterates throught the LinkedList, compares it to other and returns true if every element is the same and in the same order
     * Parameters: LinkedList other
     * Returns: true if they are the same, otherwise false
     */
    bool operator ==(const LinkedList<T>& other) const{
        
        if(sizeOfList!= other.sizeOfList){
            
            return false;
            
        }
        
        Node *thisNode = head;
        
        Node *otherNode = other.head;
        
        for(int x = 0; x < sizeOfList;x++){
            
            if(thisNode->element != otherNode->element){
                
                return false;
                
            }
            
            thisNode = thisNode->next;
            
            otherNode = otherNode->next;
            
            
        }
        
        return true;
        
    }
    
    /* Returns whether or not this instance of LinkedList is not equal to another instance of LinkedList
     * Iterates throught the LinkedList, compares it to other and returns false if every element is the same and in the same order
     * Parameters: LinkedList other
     * Returns: true if they are not the same, otherwise false
     */
    bool operator !=(const LinkedList<T>& other) const{
        
        if(sizeOfList!= other.sizeOfList){
            
            return true;
            
        }
        
        Node *thisNode = head;
        
        Node *otherNode = other.head;
        
        for(int x = 0; x < sizeOfList;x++){
            
            if(thisNode->element != otherNode->element){
                
                return true;
                
            }
            
            thisNode = thisNode->next;
            
            otherNode = otherNode->next;
            
            
        }
        
        return false;
        
        
    }
    
    /* Adds an Element item to the end of the LinkedList
     * Iterates throught the LinkedLIst and adds the element at the end
     * Parameters: T& item
     * Returns: *this
     */
    LinkedList<T>& operator += (const T& item){
        
        Node* tmp = new Node(item, 0);
        
        Node* node = head;
        
        if(node == 0){
            
            head = tmp;
            
        }else{
            
            for(int x = 0; x < sizeOfList-1; x ++){
                node = node->next;
                
            }
            
            node->next = tmp;
            
        }
        
        sizeOfList++;
        
        return *this;
        
        
    }
    
    
    
};

#endif /* LinkedList_h */
