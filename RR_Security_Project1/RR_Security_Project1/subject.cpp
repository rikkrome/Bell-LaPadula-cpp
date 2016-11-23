//
//  subject.cpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//

#include "subject.hpp"

subject::subject(string Name, int Temp){
    name = Name;
    temp = Temp;
    
}
subject::~subject(){
    name = "";
    temp = 0;
}
string subject::getName(){
    
    return name;
}
int subject::getValue(){
    
    return temp;
}

