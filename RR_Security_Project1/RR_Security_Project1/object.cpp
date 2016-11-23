//
//  object.cpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//

#include "object.hpp"

object::object(string Name, int Value){
    name = Name;
    value = Value;
    
}
object::~object(){
    name = "";
    value = 0;
}
string object::getName(){
    
    return name;
}
int object::getValue(){
    
    return value;
}
