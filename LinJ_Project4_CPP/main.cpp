//
//  main.cpp
//  LinJ_Project4_CPP
//
//  Created by Jinwei Lin on 3/26/15.
//  Copyright (c) 2015 JL. All rights reserved.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/* 
 */
LinkedList* list = new LinkedList();
LinkedList* btree = new LinkedList();
int countPair=0;
string* charArray;
int* probArray;
string* codeArray;
int* bitArray;
int* entropyArray;

void insert(LinkedList* lst, string l, int p){
    Node* newNode = new Node(l,p);
    Node* walker = lst->get_listHead();
    while (walker->getNext() != NULL && newNode->getProb() > walker->getNext()->getProb()) {
        walker = walker->getNext();
    }
    newNode->setNext(walker->getNext());
    walker->setNext(newNode);
}

string print(LinkedList* lst, int count){
    ostringstream os;
    Node* walker = lst->get_listHead();
    if (count==0){
        os<<"Iteration 0: listHead->("<<walker->getLetter()<<","<<walker->getProb()<<","<<"next)->NULL"<<endl<<endl;
        return os.str();
    }
    else{
        os<<"Iteration "<<count<<": listHead->("<<walker->getLetter()<<","<<walker->getProb()<<",";
        walker = walker->getNext();
        while (walker!=NULL) {
            
            os<<walker->getLetter()<<")->("<<walker->getLetter() <<"," <<walker->getProb() <<",";
            walker = walker->getNext();
            
        }
        os<<"NULL)->NULL"<<endl;
        return os.str();
    }
}

void print_sorted_file(LinkedList* lst, string fileName){
    ofstream outfile2;
    outfile2.open(fileName);
    Node* walker = lst->get_listHead()->getNext();
    while (walker!=NULL) {
        outfile2<< walker->getLetter() <<" "<< walker->getProb()<< endl;
        walker = walker->getNext();
    }
    outfile2.close();
}

void HuffmanLinkedList(string iFile, string oFile1, string oFile2){
    int prob=0;
    string letter;
    
    ifstream infile;
    infile.open(iFile);
    ofstream outfile1;
    //outfile1.open(oFile1);
    string result1;
    
    outfile1<<print(list,countPair);
    while (! infile.eof()) {
        countPair++;
        infile >> letter;
        infile >> prob;
        insert(list,letter, prob);
        result1 = print(list, countPair);
       // outfile1 << result1<<endl;
    }
   
    infile.close();
    outfile1.close();
    
   // print_sorted_file(list,oFile2);
}

string conc_letter_string(LinkedList* btree){
    Node* walker = btree->get_listHead()->getNext();
    return walker->getLetter()+walker->getNext()->getLetter();
}

int conc_prob(LinkedList* btree){
    Node* walker = btree->get_listHead()->getNext();
    return walker->getProb()+walker->getNext()->getProb();
}

void newInsert(LinkedList* btree,string l, int p){
    Node* newNode = new Node(l,p);
    newNode->setLeft(btree->get_listHead()->getNext());
    newNode->setRight(btree->get_listHead()->getNext()->getNext());
    btree->get_listHead()->setNext(btree->get_listHead()->getNext()->getNext()->getNext());
    
    Node* walker = btree->get_listHead();
    while (walker->getNext() != NULL && newNode->getProb() > walker->getNext()->getProb()) {
        walker = walker->getNext();
    }
    newNode->setNext(walker->getNext());
    walker->setNext(newNode);
}

void HuffmanBinaryTree(string oFile){
    btree->get_listHead()->setNext(list->get_listHead()->getNext());
    
    string leString;
    int newProb=0;
    int bCountPair=0;
    string result2;
    
    ofstream outfile3;
    //outfile3.open(oFile);
    
    while (btree->get_listHead()->getNext()->getNext() != NULL) {
        bCountPair++;
        leString = conc_letter_string(btree);
        newProb =  conc_prob(btree);
        newInsert(btree,leString, newProb);
        result2= print(btree,bCountPair);
        //outfile3 << result2<<endl;
    }
    outfile3.close();
}

string printLinkedList(Node* n){
    ostringstream os;
    Node* walker = n;
    os<<"listHead->("<<walker->getLetter()<<","<<walker->getProb()<<","<<walker->getCode()<<",";
    walker = n->getNext();
    while (walker!=NULL) {
        os<<walker->getLetter()<<")->("<<walker->getLetter() <<"," <<walker->getProb() <<","<<walker->getCode()<<",";
        walker = walker->getNext();
    }
    os<<"NULL)->NULL"<<endl;
    return os.str();
}

void HuffmanCode(Node* T, string code){
    Node* walker = T;
    if (walker==NULL) {
        return;
    }
    else if(walker->getLeft()==NULL && walker->getRight()==NULL){
        walker->setCode(code);
        return;
    }
    else{
        HuffmanCode(walker->getLeft(),code+"0");
        HuffmanCode(walker->getRight(), code+"1");
    }
}

void EntropyTable(Node* n){
    Node* walker = n->getNext();
    charArray = new string[countPair+1];
    probArray = new int[countPair+1];
    codeArray= new string[countPair+1];
    bitArray = new int[countPair+1];
    entropyArray = new int[countPair+1];

    int i=0;
    while (walker!=NULL) {
        if(walker->getLetter().length() == 1){
            
            charArray[i] = walker->getLetter();
            probArray[i] = walker->getProb();
            codeArray[i] = walker->getCode();
            bitArray[i] = walker->getCode().length();
            entropyArray[i] = walker->getCode().length()*walker->getProb();
            i++;
        }
        walker = walker->getNext();
    }
}

void printEntropyTable(string oFile){
    ofstream outfile5;
    outfile5.open(oFile);
    double totalEntropy=0;
    outfile5<<"Char Prob Code #bits Entropy"<<endl;
    for (int i=0; i<countPair; i++) {
        outfile5<<charArray[i]<<"    "<<probArray[i]<<"   "<<codeArray[i]<<"   "<<bitArray[i]<<"   "<<entropyArray[i]<<endl;
        totalEntropy+=entropyArray[i];
    }
    outfile5<<"Total entropy:"<<totalEntropy/100;
}

void computeProb(string iFile, string oFile){
    ifstream infile;
    infile.open(iFile);
    ofstream outfile;
    outfile.open(oFile);
    int size = 256;
    int* Hist = new int[size];
    int index=0, totalChar=0;
    char charStr;

    while (!infile.eof()) {
        infile >> charStr;
        index = (unsigned)charStr;
        Hist[index]++;
        totalChar++;
    }
    infile.close();
    int charCount=0;
    int prob=0;
    index=0;
   
    while (index<size) {
        charStr = static_cast<char>(index);
        charCount = Hist[index];
        prob=(double(charCount)/totalChar)*100;
        if (charCount != 0)
            outfile << charStr <<" "<<prob<<endl;
        index++;
    }
    outfile.close();
}

void encodeText(string iFile, string oFile,string charArray[], string codeArray[]){
    ifstream infile;
    infile.open(iFile);
    ofstream outfile;
    outfile.open(oFile);
    char charStr;
    int i=0;
    while (!infile.eof()) {
        infile >> charStr;
        i=0;
        while (charArray[i][0] != charStr ) {
            i++;
        }
        outfile<<codeArray[i];
    }
    infile.close();
    outfile.close();
    
}

void decodeText(Node* root, string iFile, string oFile, string charArray[], string codeArray[]){
    Node* walker = root;
    ifstream infile;
    infile.open(iFile);
    ofstream outfile;
    outfile.open(oFile);
    string code;
    string codeStr="";
    infile >> code;
    int i=0;
    
    while (i<code.size()){
        while(walker != NULL && walker->getLeft() != NULL && walker->getRight() != NULL ) {
            if (code[i] =='0') {
                walker=walker->getLeft();
                codeStr += "0";
            }
            else{
                walker=walker->getRight();
                codeStr += "1";
            }
            i++;
        }
        int j=0;
        while (codeArray[j] != codeStr && j<countPair+1) {
            j++;
        }
        outfile << charArray[j];
        codeStr ="";
        walker = root;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char* argv[]) {
    computeProb(argv[1], argv[2]);
    HuffmanLinkedList(argv[2], argv[3], argv[4]);
    HuffmanBinaryTree(argv[5]);
    Node* root;
    root = btree->get_listHead()->getNext();
    btree->set_listHead(list->get_listHead());
    string printList,printListWithCode;
    ofstream outfile4;
    outfile4.open(argv[6]);
    
    printList = printLinkedList(list->get_listHead());
    outfile4 << printList <<endl;
    HuffmanCode(root, "");
    printListWithCode = printLinkedList(list->get_listHead());
    outfile4 << printListWithCode <<endl;
    
    

    EntropyTable(list->get_listHead());
    printEntropyTable(argv[7]);
    
    encodeText(argv[8], argv[9],charArray,codeArray);
    decodeText(root, argv[9], argv[10], charArray, codeArray);
    
    return 0;
}