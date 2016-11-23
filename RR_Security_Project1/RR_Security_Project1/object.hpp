//
//  object.hpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <stdio.h>
#include <string>
using namespace std;


class object {
    
private:
    string name;
    int value;
    
public:
    object(string Name, int Value);
    ~object();
    string getName();
    int getValue();
    
};
#endif /* object_hpp */







