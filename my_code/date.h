//
//  date.h
//  OOPsummer
//
//  Created by Shuqing Li on 6/7/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//
#include <string>
#include <vector>

#ifndef date_h
#define date_h

class Date{
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int m, int d, int y);
private:
    int day;
    int month;
    int year;
    
};

#endif /* date_h */
