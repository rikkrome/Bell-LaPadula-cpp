//
//  ReferenceMonitor.hpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//Users/rickyromero/Documents/Security4550/RR_Security_Project1/RR_Security_Project1/ReferenceMonitor.hpp/

#ifndef ReferenceMonitor_hpp
#define ReferenceMonitor_hpp
#include <stdio.h>
#include "subject.hpp"
#include "object.hpp"

using namespace std;

class ReferenceMonitor {
    
private:
    struct securityLevels{
        string name;
        string level;
    };

public:
    void runApp();
    void print();
    void createObject(string name,string level, int value);
    void createSubject(string name, string level, int value);
    void executeRead(string subj, string obj);
    void executeWrite(string subj, string obj, int value);
    int  checkLevel(string level);
    bool findSubjObj(string subj, string obj);
    
    vector< list<subject> > subjectsList;
    vector< list<securityLevels> > subjectsLevel;
    vector< list<object> > objectList;
    vector< list<securityLevels> > objectLevel;


    
};

#endif /* ReferenceMonitor_hpp */
