//
//  subject.hpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//

#ifndef subject_hpp
#define subject_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class subject {
    
private:
        string name;
        int temp;
    
public:
    subject(string Name, int temp);
    ~subject();
    string getName();
    int getValue();
};
#endif /* subject_hpp */
