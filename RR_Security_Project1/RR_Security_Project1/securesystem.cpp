//
//  main.cpp
//  RR_Security_Project1
//
//  Created by Ricky Romero on 10/27/16.
//  Copyright © 2016 Ricky Romero. All rights reserved.
//

/*
    RICKY ROMERO 
    CSCE 4550 
    Project 1
    Bell-LaPadula system rules
 
    files needed: 
        securesystem.cpp
        ReferenceMonitor.cpp
        ReferenceMonitor.h
        subject.cpp
        subject.hpp
        object.cpp
        object.hpp
 */

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "ReferenceMonitor.h"




using namespace std;


//string filename = "file.txt";



void readfile(ReferenceMonitor& refMon, string filename){
    
    string line, job, subj, obj, value;

    ifstream myfile(filename.c_str());
    
    if (myfile.is_open()){
//        cout << "file opean\n";
        //read file until the end
        while (!myfile.eof()){
            
            //get the first line in the txt file
            getline(myfile, line,'\n'); //rick read sobj
//            cout << "# " << line << endl;
            
            //split the line into single words and save them to a vector
            istringstream iss(line);
            vector<string> lineWord;
            
            copy(istream_iterator<string>(iss),
                 istream_iterator<string>(),
                 back_inserter(lineWord));
            
            
            //make sure the vector is not empty
            if(!lineWord.empty()){
                //first check if it is read or write. the [0] should hold it.
                if(lineWord[0] == "read"){
//                    cout << "read" << endl;
                    
                    /* 
                     loop to see how many words are in the line. Read = 3 (read = 1 subj =2 obj = 3)
                     */
                    int x = 0;
                    for (int i = 0; i < lineWord.size(); i++) {
                        x = x + 1;
                    }
                
                    if (x == 3){
                        //check if subj and obj are real.
                        bool chackRead = refMon.findSubjObj(lineWord[1], lineWord[2]);
                        
                        if(chackRead){
                            refMon.executeRead(lineWord[1],lineWord[2]);
                        }else{
                            //if subj or obj are not real
                            cout << "Bad Instruction\t: " << line << endl;
                        }
                    }else{
                        // if the line does not = 3
                        cout << "Bad Instruction\t: " << line << endl;
                    }
                    
                }else if(lineWord[0] == "write"){
//                    cout << "write" << endl;
                    int x = 0;
                    for (int i = 0; i < lineWord.size(); i++) {
                        x = x + 1;
//                        cout << x << lineWord[i] << endl;
                    }
                    if (x == 4){
//                        cout << "Access Granted" << endl;
                        
                        bool chackWrite = refMon.findSubjObj(lineWord[1], lineWord[2]);
                        if(chackWrite){
                            int objValue = 0;
                            try {
                                //make sure the value is not 0
                                if(lineWord[3] != "0"){
                                    //if it returns 0 then the value is not a number
                                    if(atoi(lineWord[3].c_str()) != 0){
                                        int value = atoi(lineWord[3].c_str());
    //                                  int value = std::stoi( lineWord[3] );
                                       // cout << "\n$ value: " << objValue << endl;
                                        refMon.executeWrite(lineWord[1], lineWord[2], value);
                                    }else{
                                        cout << "Bad Instruction\t: " << line << endl;
                                    }
                                }else{
                                    //value is 0
                                    int value = atoi(lineWord[3].c_str());
                                    //int value = std::stoi( lineWord[3] );
                                    //cout << "\n$ value: " << objValue << endl;
                                    refMon.executeWrite(lineWord[1], lineWord[2], value);
                                }
                                
                            }
                            catch(int e){
                                // if no conversion could be performed
                                cout << "BBad Instruction\t: " << line << endl;
                            }
                            
                        }else{
                            //if subj or obj are not real
                            cout << "Bad Instruction\t: " << line << endl;
                        }
                    }else{
                        // if the line does not = 3
                        cout << "Bad Instruction\t: " << line << endl;
                    }
                }else {
                    //if command does not start with read or write
                    cout << "Bad Instruction\t: " << line << endl;
                }
            
            } // end of
            
            

        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    string filename = "";
    
    if(argc == 2){
        if(argv[1] != NULL){
            string filenameInput(argv[1]);
            filename = filenameInput;
        }
        
    }else{
        cout << "\033[1;31m\t***************\033[0m\n";
        cout << "\033[1;31m\t*** WARNING ***\033[0m\n";
        cout << "\tCommand line error" << endl;
        cout << "\tExample:" << endl;
        cout << "\t./securesystem fileName.txt" << endl;
        cout << "\033[1;31m\t***************\033[0m\n";
        return 0;
//        filename = "/Users/rickyromero/Documents/Security4550/Bell-LaPadula-C-/RR_Security_Project1/RR_Security_Project1/file.txt";
    }
    
    cout << "filename: " << filename << endl;

    
    
    ReferenceMonitor refMon;
    
    /*
        Make Subjects and Objects
     */
    refMon.createSubject("adam", "LOW", 0);
    refMon.createSubject("james", "MEDIUM", 0);
    refMon.createSubject("tim", "HIGH", 0);
    refMon.createSubject("sara", "LOW", 0);
    refMon.createSubject("kristy", "MEDIUM", 0);
    refMon.createSubject("liz", "HIGH", 0);
    
    refMon.createObject("aobj", "LOW", 0);
    refMon.createObject("jobj", "MEDIUM", 0);
    refMon.createObject("tobj", "HIGH", 0);
    refMon.createObject("sobj", "LOW", 0);
    refMon.createObject("kobj", "MEDIUM", 0);
    refMon.createObject("lobj", "HIGH", 0);
    
//    refMon.print();
    
    
    /*
        read file
     */
    readfile(refMon,filename);
    
    
    return 0;
}




/*
 
 write adam aobj 80
 read adam
 write adam aobj 40 80
 read adam aobj 50
 write sara sobj 10
 read tim sobjwrite kristy jobj 40
 write liz kobj 20
 read sara tobj
 write james lobj 30
 read tim lobj
 write sara kobj 50
 write adam tobj 20
 read liz kobj
 read adam sobj
 read james jobj
 read kristy tobj
 write james about
 write tim kobj
 write john jobj
 read sara zobj
 exec adam aobj
 Hi Sara, This is liz
 The missile launch code is 1234567
 
 
 */
