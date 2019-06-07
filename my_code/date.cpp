//
//  date.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 6/7/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//
#include <iostream>
#include <string>

#include "date.h"
using namespace std;


Date::Date(int m, int d, int y):month(m),day(d),year(y) {
    if ((d<1)||(d>31)) throw (d);
    if ((m<1)||(m>12)) throw (m);
    if ((y<1800)||(y>2200)) throw (y);
}

ostream& operator <<(ostream& os,const Date& date ) {
    os<<date.month<<"/"<<date.day<<"/"<<date.year<<endl;
    return os;
}
