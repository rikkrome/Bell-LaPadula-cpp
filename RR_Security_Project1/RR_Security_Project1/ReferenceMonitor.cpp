//
//  ReferenceMonitor.cpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include "ReferenceMonitor.h"

/*
 create subject
 */
void ReferenceMonitor::createSubject(string name, string level, int value){
    
    /* 
        class Subjects:
                name , value
     */
    list<subject> temp;
    temp.push_back(subject(name,value));
    subjectsList.push_back(temp);
    
    /*
            saving the levels
            class ReferenceMonitor:
                    struct subjectsLevel { name , temp }
     
     */
    list<securityLevels> tempLevel;
    securityLevels sLevel;
    sLevel.name = name;
    sLevel.level = level;

    tempLevel.push_back(sLevel);
    subjectsLevel.push_back(tempLevel);
}

/*
 create object
 */
void ReferenceMonitor::createObject(string name, string level, int value){
    //saving object data
    list<object> temp;
    temp.push_back(object(name,value));
    objectList.push_back(temp);
    
    //save the security Level
    list<securityLevels> tempLevel;
    securityLevels oLevel;
    oLevel.name = name;
    oLevel.level = level;
    
    tempLevel.push_back(oLevel);
    objectLevel.push_back(tempLevel);
    
}




void ReferenceMonitor::print(){

    //printing out the subjects List
    cout << "+------------------------The current state is-------------------------+ " << endl;
    cout << "subjects: " << '\t';
    for (int i = 0; i < subjectsList.size(); i++) {
        
        for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
            cout << setw(5) <<  it->getName() << " |";
        }
    }
    cout << endl;
    cout << "value: " << '\t' << '\t';
    for (int i = 0; i < subjectsList.size(); i++) {
        for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
            cout <<  setw(5) << it->getValue() << " |";
        }
    }
    cout << "\n+---------------------------------------------------------------------+ " << endl;

    //printing out the object List
    cout << "object: " << '\t';
    for (int i = 0; i < objectList.size(); i++) {
        
        for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
            cout << setw(5) <<  it->getName() << " |";
            
        }
    }
    cout << endl;
    cout << "value: " << '\t' << '\t';
    for (int i = 0; i < objectList.size(); i++) {
        
        for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
            cout <<  setw(5) << it->getValue() << " |";
            
        }
    }
    cout << "\n+---------------------------------------------------------------------+ \n" << endl;

}

/*
 CheckLevel
     returns level as an int
         low = 1
         medium = 2
         high = 3
 */
int ReferenceMonitor::checkLevel(string level){

    if(level == "LOW"){
        return 1;
    }else if(level == "MEDIUM"){
        return 2;
    }else if(level == "HIGH"){
        return 3;
    }
    


    return 0;
}


void ReferenceMonitor::executeRead(string subj, string obj){
    /*  high: no
        same: yes
        low: yes
     */
    
    string subjLevel;
    int subjValue = 0;
    
    string objLevel;
    int objValue = 0;
    
    /*subject: find name, get level, get value
     getting subjects level and value then saving it.
     */
    for (int i = 0; i < subjectsList.size(); i++) {
        
        for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
            if(it->getName() == subj){
                subjValue = it->getValue();
                break;
            }
        }
    }
    //get Subj security Level
    for (int i = 0; i < subjectsLevel.size(); i++){
        if(subjectsLevel[i].front().name == subj){
            subjLevel = subjectsLevel[i].front().level;
            break;
        }
    }
    
    /*object: find name, get level, get value
     getting object level and value then saving it.
     */
    for (int i = 0; i < objectList.size(); i++) {
        
        for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
            if(it->getName() == obj){
                objValue = it->getValue();
                break;
            }
        }
    }
    //get Obj security Level
    for (int i = 0; i < objectLevel.size(); i++){
        if(objectLevel[i].front().name == subj){
            objLevel = objectLevel[i].front().level;
            break;
        }
    }
    
    //check levels
    /*
        returns level as an int
        low = 1
        medium = 2
        high = 3
     */
    int sLevel = checkLevel(subjLevel);
    int oLevel = checkLevel(objLevel);
    
    
    
    
    /*
        NO READ UP
     
        subj < obj
        if subj is less (lower) and obj then you can access it. anything else works.
     
        ex: read up == no
            subj = M obj = H
            subj = 2 obj = 3
            
            read same == yes
            subj = M obj = M
            subj = 2 obj = 2
     
            read down == yes
            subj = M obj = L
            subj = 2 obj = 1
     */
//    cout << subjValue <<  " " <<  objValue << " " << endl;
    if(sLevel < oLevel){
        cout << "Access Denied \t: read " <<  subj << " " << obj << endl;
    }else{
        cout << "Access Granted \t: " <<  subj << " reads " << obj << endl;
        
        list<subject> temp;
        temp.push_back(subject(subj,objValue)); // change back to objValue **********************$$

        for (int i = 0; i < subjectsList.size(); i++) {
            for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
                if(it->getName() == subj){
                    subjectsList[i] = temp;
                    break;
                }
            }
        }
        print();
    }
    
    
    
}

void ReferenceMonitor::executeWrite(string subj, string obj, int value){
    /*  write
        high: yes
        same: yes
        low: no
     */
    
    string subjLevel;
    int subjValue;
    
    string objLevel;
    int objValue;
    
    
    
    //subject: find name, get level, get value
    for (int i = 0; i < subjectsList.size(); i++) {
        
        for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
            if(it->getName() == subj){
                subjValue = it->getValue();

                break;
            }
        }
    }
    //get Subj security Level
    for (int i = 0; i < subjectsLevel.size(); i++){
        if(subjectsLevel[i].front().name == subj){
            subjLevel = subjectsLevel[i].front().level;
            break;
        }
    }
    
    //objectList: find objName, get level, get value
    for (int i = 0; i < objectList.size(); i++) {
        
        for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
            if(it->getName() == obj){
                objValue = it->getValue();
                break;
            }
        }
    }
    //get Obj security Level
    for (int i = 0; i < objectLevel.size(); i++){
        if(objectLevel[i].front().name == obj){
            objLevel = objectLevel[i].front().level;
            break;
        }
    }

    
    //check levels
    int sLevel = checkLevel(subjLevel);
    int oLevel = checkLevel(objLevel);
    
    /*
     no write down
     subj > obj
     if subj is greater (higher) and obj then you can access it. anything else works.
     
     ex:    write up == YES
            subj = M obj = H
            subj = 2 obj = 3
     
            write same == YES
            subj = M obj = M
            subj = 2 obj = 2
     
            write down == NO
            subj = M obj = L
            subj = 2 obj = 1
     */
    if(sLevel > oLevel){
        cout << "Access Denied \t: write " <<  subj << " " << obj << " " <<  value << endl;
        
    }else{
        //Access Granted : sara writes value 10 to sobj
        cout << "Access Granted \t: " <<  subj << " writes value " << value << " to "<< obj << endl;
        //change the object value
        list<object> temp;
        temp.push_back(object(obj,value));
        for (int i = 0; i < objectList.size(); i++) {
            for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
                if(it->getName() == obj){
                    objectList[i] = temp;
                }
            }
        }
        print();
    }
    
}

/* 
    find out if Subject and object are real
 */
bool ReferenceMonitor::findSubjObj(string subj, string obj){
    
    bool foundSubj = false, foundObj = false;
    
    //subject: find subj
    for (int i = 0; i < subjectsList.size(); i++) {
        
        for (list<subject>::iterator it = subjectsList[i].begin(); it != subjectsList[i].end(); ++it) {
            if(it->getName() == subj){
                foundSubj = true;
                break;
            }
        }
    }
    
    //objectList: find obj
    for (int i = 0; i < objectList.size(); i++) {
        
        for (list<object>::iterator it = objectList[i].begin(); it != objectList[i].end(); ++it) {
            if(it->getName() == obj){
                foundObj = true;
                break;
            }
        }
    }
    if(foundSubj == true && foundObj == true){
        return true;
    }

    return false;
}
