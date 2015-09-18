//
//  LinkedList.h
//  LinJ_Project4_CPP
//
//  Created by Jinwei Lin on 3/26/15.
//  Copyright (c) 2015 JL. All rights reserved.
//

class LinkedList{
    
private:
    Node* listHead;
    Node* dummyNode;
public:
    LinkedList(){
        dummyNode = new Node();
        listHead = dummyNode;
    }
    
    ~LinkedList(){}
    
    
    Node* get_listHead(){
        return listHead;
    }
    
    void set_listHead(Node* n){
        listHead = n;
    }
    
};
