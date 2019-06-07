//
//  test_weather.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 6/6/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

void read_recording(string filename, Weather& w){
    ifstream rfile(filename);
    if(!rfile){
        cout<<"could not read input file: "<<filename<<endl;
        exit(1);
    }
    int m,d,y;
    double temp,hum,ws;
    while(rfile >> m >> d >> y >> temp >> hum >> ws) {
        WReading wr=WReading(Date(m,d,y),temp,hum,ws);
        w.add_reading(wr);
    }
    rfile.close();
}


int main() {
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    
    string filename;
    cout<<"Input the name of the new readings file;\n";
    cin>>filename;
    
    read_recording(filename,irkutsk);
    
    cout << irkutsk << endl;
    

}
