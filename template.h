//
// Created by nabee on 10/23/2022.
//

#ifndef ASSIGNMENT3_BRACKETS_TEMPLATE_H
#define ASSIGNMENT3_BRACKETS_TEMPLATE_H

#endif //ASSIGNMENT3_BRACKETS_TEMPLATE_H
#include <string.h>
#include <iostream>
#include <fstream>
#include "DSStack.h"
#include "DSList.h"
#include "DSStackVector.h"
using namespace std;

int check_brackets (string inputfile)
{
    //parsing through the input file and getting each line
    ifstream file_input(inputfile);
    string line ="";
    int counter = 0;
    if(file_input.is_open())
    {
        cout<<"File is open"<<endl;
    }
    else
    {
        cout<<"Error, file is not opening"<<endl;
    }
     DSStack<char> temp;
//getting each line till the end of the file
    while(getline(file_input, line) && !file_input.eof()) {
        counter++;

        char x;

//iterating through each character in the file
       for(int i =0; i<line.length(); i++)
       {
           //checking if the line is a comment and to ignore the bracket found inside it
           if(i < line.length() - 1 && line[i] == '/' && line[i+1] =='/')
           {
               break;
           }
           //checking for open brackets
            if(line[i] == '(' || line[i] == '[' || line[i] == '{')
           {
                //pushing the open brackets onto the stack
               temp.push(line[i]);

           }
            //checking for close brackets if it is not open
          else if(line[i] == ')')
           {
              //if it is empty, and a open bracket is not pushed then there is a error
              if (temp.empty())
              {
                  cout<< "Error is on line " << counter << endl;
                  cout<< "The message with the issue: "<< line <<endl;
                  return 1;
              }
              //storing the first value in the stack
               x = temp.top();
              //deleting it off the stack
               temp.pop();
               //if the value is not a open bracket, prints a error
               if(x != '(')
               {
                   cout<< "Error is on line " << counter << endl;
                   cout<< "The message with the issue: "<< line <<endl;
                   cout<<" Either add " << '(' << " or delete " << ')' << endl;
                   return 1;
               }
           }
          //the above process is repeated for each bracket below
           else if(line[i] == ']')
           {
               if (temp.empty())
               {
                   cout<< "Error is on line " << counter << endl;
                   cout<< "The message with the issue: "<< line <<endl;
                   return 1;
               }
               x = temp.top();
               temp.pop();
               if(x !='[')
               {
                   cout<< "Error is on line " << counter << endl;
                   cout<< "The message with the issue: "<< line <<endl;
                   cout<<" Either add " << '[' << " or delete " << ']' << endl;

                   return 1;
               }
           }
           else if(line[i] == '}')
           {
               if (temp.empty())
               {
                   cout<< "Error is on line " << counter << endl;
                   cout<< "The message with the issue: "<< line <<endl;
                   return 1;
               }
               x = temp.top();

               temp.pop();
               if(x != '{' )
               {
                   cout<< "Error is on line " << counter << endl;
                   cout<< "The message with the issue: "<< line <<endl;
                   cout<<" Either add " << '{' << " or delete " << '}' << endl;
                   return 1;
               }
           }

       }
    }
   file_input.close();
    cout<<"OK"<<endl;
    return 0;
}

