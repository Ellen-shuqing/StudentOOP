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

string get_input_file() {
    string filename;
    
    cout<<"Input the name of the new reading: "<<endl;
    cin>>filename;
    return filename;
}


void weather_recording(Weather& w){
    ifstream rfile(get_input_file());
    while (!rfile){
        cout<<"could not read input file: "<<endl;
        rfile.open(get_input_file());
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
    
    weather_recording(irkutsk);
    
    cout << irkutsk << endl;
    

}
