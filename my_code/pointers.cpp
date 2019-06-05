//
//  pointers.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 6/4/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//

#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
    ++n;
}


void inc_with_pointer(int* iptr) {
    ++(*iptr);
}


void inc_with_reference(int& n) {
    ++n;
}


Thing** create_array_of_things(int n) {
    Thing** array=new Thing* [n];
    for (int i=0;i<n;++i) {
        array[i]=new Thing(i);
    }
    return array;
}

void print_all_things(Thing** things, int n) {
    for (int i=0;i<n;++i) {
        cout<<things[i]->val<<" ";
    }
    cout<<endl;
}

void double_all_things(Thing** things, int n) {
    for (int i=0;i<n;++i) {
        things[i]->val*=2;
    }
}

void delete_all_things(Thing** things, int n) {
    for (int i=0; i<n;++i) {
        delete things[i];
    }
    delete[] things;
}


void assignTA(Student* s, Student* ta) {
    s->ta=ta;
}

void printTAs(vector<Student*>& students) {
    for (size_t i=0; i<students.size();++i) {
        if (students[i]->ta==nullptr) {
            cout<<students[i]->name<< " has no TA"<<endl;
        }
        else {
        cout<<students[i]->name<<" has TA " <<students[i]->ta->name<<endl;
        }
    }
}
