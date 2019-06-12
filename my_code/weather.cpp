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

Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
    width=img2.width;
    height=img2.height;
    filename=img2.filename;
    image_buf=new char[image_sz()];
    for (int i=0;i<image_sz();++i) {
        image_buf[i]=img2.image_buf[i];
    }
}

Image::~Image() {
    if(image_buf!=nullptr) {
        delete[] image_buf;
    }
}

Image& Image::operator=(const Image& img2) {
    if (&img2!=this) {
        if (image_buf!=nullptr) {
            delete[] image_buf;
            copy_fields(img2);
        }
    }
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
    width=img2.width;
    height=img2.height;
    filename=img2.filename;
    image_buf=new char[image_sz()];
    for (int i=0;i<image_sz();++i) {
        image_buf[i]=img2.image_buf[i];
    }
}
/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}
