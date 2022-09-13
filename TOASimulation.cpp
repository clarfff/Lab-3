//
// Author: Clark Reed
// TTU Lab 3
//
// Description: This code acts as a proof of concept and simulation for the time of arrival location tracking system.
// It uses classes for each aspect including: The TOA calculation, homebase, the rover, and the satellite location.
//
// This code is open source and I am allowing anyone to use this as long as you give credit.



#include <iostream>

using namespace std;


class TOA{
    public:
        double time;
        const double rfTravel = 300000000; // meters per second
        int distance;
        double location;

        TOA()
        {
            time = 0; // seconds
            //rfTravel = 300000000; // meters per second
            distance = 0;
            location = 0;
        }

        void setTime(double a)
        {
            time = a;
        }

        void setDistance(int d)
        {
            distance = d;
        }

        void setLocation(double l)
        {
            location = l;
        }

        int getTime()
        {
            return time;
        }

        int getDistance()
        {
            return distance;
        }

        double getLocation()
        {
            return location;
        }

        void calculateLocation()
        {
            location = time * rfTravel;
        }
};

class Homebase{
    public:
        double location;
        double time;

        double satelliteTime;
        double homebaseTime;

        Homebase()
        {
            location = 0;
            time = 0;
        }

        void setLocation(double l)
        {
            location = l;
        }

        void setTime(double t)
        {
            time = t;
        }

        double getLocation()
        {
            return location;
        }

        double getTime()
        {
            return time;
        }

        void setSatelliteTime(double a)
        {
            satelliteTime = a;
        }

        void setHomebaseTime(double a)
        {
            homebaseTime = a;
        }

        double getSatelliteTime()
        {
            return satelliteTime;
        }

        double getHomebaseTime()
        {
            return homebaseTime;
        }

};

class Rover{
    public:
        double location;
        double time;

        double satelliteTime;
        double homebaseTime;

        Rover()
        {
            location = 0;
            time = 0;
            satelliteTime = 0;
            homebaseTime = 0;
        }

        void setLocation(double l)
        {
            location = l;
        }

        void setTime(double t)
        {
            time = t;
        }

        void setSatelliteTime(double a)
        {
            satelliteTime = a;
        }

        void setHomebaseTime(double a)
        {
            homebaseTime = a;
        }

        double getLocation()
        {
            return location;
        }

        double getTime()
        {
            return time;
        }

        double getSatelliteTime()
        {
            return satelliteTime;
        }

        double getHomebaseTime()
        {
            return homebaseTime;
        }
};

class Satellite{
    public:
        double location;
        double time;

        Satellite()
        {
            location = 0;
            time = 0;
        }

        void setLocation(double l)
        {
            location = l;
        }

        void setTime(double t)
        {
            time = t;
        }

        double getLocation()
        {
            return location;
        }

        double getTime()
        {
            return time;
        }

};

int main()
{
    int x;
    int y;
    char roveR = 'x';
    TOA toa = TOA();
    Homebase homebase = Homebase();
    Satellite satellite = Satellite();
    Rover rover = Rover();

    satellite.setTime(0.0000002); // time that rover to satellite, satellite would send back that value and it is held until sent to homebase
    homebase.setTime(0.00000001); // time that rover to homebase, homebase would send that value back and it is held until sent back to homebase

    rover.setHomebaseTime(homebase.getTime());
    rover.setSatelliteTime(satellite.getTime());

    homebase.setHomebaseTime(rover.getHomebaseTime());
    homebase.setSatelliteTime(rover.getSatelliteTime());

    toa.setTime(homebase.getHomebaseTime());
    toa.calculateLocation();
    x = toa.getLocation();
    cout << endl;
    cout << "Location from Homebase: " << toa.getLocation() << " meters ";
    toa.setTime(homebase.getSatelliteTime());
    toa.calculateLocation();
    y = toa.getLocation();
    cout << "Location from Satellite: " << toa.getLocation() << " meters" << endl;

    char grid[100][100];
    for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                grid[i][j] = '-';
            }
        }
    grid[x][y] = roveR;

    for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    return 0;
}