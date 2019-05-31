//
//  pointers.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 5/31/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//
#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
    ++n;
}


void inc_with_pointer(int* n) {
    ++(*n);
}


void inc_with_reference(int& n) {
    ++n;
}

