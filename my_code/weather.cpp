//
//  weather.cpp
//  OOPsummer
//
//  Created by Shuqing Li on 6/5/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "weather.h"
#include "date.h"

using namespace std;

/*
 * A constructor for weather class.
 * */

ostream& operator <<(ostream& os, const GPS& gps) {
    os<<"GPS: ("<<gps.latitude<<", "<<gps.longitude<<")"<<endl;
    return os;
}

//Weather
Weather::Weather(string nm, GPS loc) :station_nm(nm), my_loc(loc) {}

ostream& operator <<(ostream& os, const Weather& w){
    os<<"name: "<<w.station_nm<<" location: "<<w.my_loc<<" rating:"<<w.rating<<endl;
    for (WReading wr : w.wreadings){
        os<<"  "<<wr<<endl;
    }
    return os;
}

string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const {
    return rating;
}

void Weather::add_reading(WReading wr) {
    wreadings.push_back(wr);
}


void Weather::set_rating(int new_rating) {
    rating=new_rating;
}

//WReading
WReading::WReading(Date dt,double temp,double hum,double ws):date(dt),temperature(temp),humidity(hum),windspeed(ws){}
ostream& operator <<(ostream&os, const WReading& wr){
    cout<<wr.date<<"temp: "<<wr.temperature<< "; humid: "<<wr.humidity<<"; windspeed: "<<wr.windspeed<<endl;
    return os;
}

double WReading::get_tempF() const {return temperature*(9/5)+32; }

double WReading::get_tempC() const {return temperature;}

double WReading::get_heat_index() const {return humidity;}

double WReading::get_wind_chill() const {return windspeed;}
