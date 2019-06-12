//
//  weather.h
//  OOPsummer
//
//  Created by Shuqing Li on 6/5/19.
//  Copyright © 2019 Shuqing Li. All rights reserved.
//


#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
    longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
public:
    WReading(Date dt,double temp,double hum,double ws);
    double get_tempF() const;
    double get_tempC() const;
    double get_heat_index() const;
    double get_wind_chill() const;
private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
};

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
   
private:
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
    std::vector<WReading> wreadings;
};



class Image {
public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    std::string display(std::string s);
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    int get_height() const { return height; }
    int get_width() const { return width; }
    
private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};


#endif
