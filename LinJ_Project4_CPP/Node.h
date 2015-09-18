//
//  Node.h
//  LinJ_Project4_CPP
//
//  Created by Jinwei Lin on 3/26/15.
//  Copyright (c) 2015 JL. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
    
private:
    string letter;
    int prob;
    string code;
    Node* left;
    Node* right;
    Node* next;
    
public:
    Node(){
        letter = "dummy";
        prob = 0.0;
        code = "";
        left = NULL;
        right = NULL;
        next = NULL;
    }
    
    Node(string l, int p){
        letter = l;
        prob = p;
        code = "";
        left = NULL;
        right = NULL;
        next = NULL;
    }
    
    void setLetter(string l){
        letter = l;
    }
    
    string getLetter(){
        return letter;
    }
    
    void setProb(int p){
        prob = p;
    }
    
    int getProb(){
        return prob;
    }
    
    void setCode(string c){
        code = c;
    }
    
    string getCode(){
        return code;
    }
    
    void setLeft(Node* l){
        left = l;
    }
    
    Node* getLeft(){
        return left;
    }
    
    void setRight(Node* r){
        right = r;
    }
    
    Node* getRight(){
        return right;
    }
    
    void setNext(Node* n){
        next = n;
    }
    
    Node* getNext(){
        return next;
    }
    
};