#include <iostream>
#include <cmath>

using namespace std;


class TOA{
    public:
        double time;
        const double rfTravel = 300000000; // meters per second
        int distance;
        double location;
        double location2;
        double diameter;
        double x;
        double y;

        TOA()
        {
            time = 0; // seconds
            //rfTravel = 300000000; // meters per second
            distance = 0;
            location = 0;
            location2 = 0;
            diameter = 0;
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
        
        void setLocation2(double l)
        {
            location2 = l;
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

        void calculateIntersection(double a, double b)
        {
            // x^2 + y^2 = a^2 (homebase circle)
            // x^2 + (y-59) = b^2 (satellite one)
            // (x-59)^2 + y^2 = c^2 (satellite two)

            x = a;
            y = b;

            y = ((a - b) + 3481)/118;
            x = 900 - (y*y);
            y = ceil(y);
            x = ceil(x);
            cout << "x: " << x << endl;
            //ceil(x);
            //x = sqrt(x);
        }

        double getX()
        {
            return x;
        }

        double getY()
        {
            return y;
        }

        double getIntersection()
        {
            return diameter;
        }

};

class Homebase{
    public:
        double location;
        double time;

        double satelliteOneTime;
        double satelliteTwoTime;
        double satelliteThreeTime;
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

        void setSatelliteOneTime(double a)
        {
            satelliteOneTime = a;
        }

        void setSatelliteTwoTime(double a)
        {
            satelliteTwoTime = a;
        }

        void setSatelliteThreeTime(double a)
        {
            satelliteThreeTime = a;
        }

        void setHomebaseTime(double a)
        {
            homebaseTime = a;
        }

        double getSatelliteOneTime()
        {
            return satelliteOneTime;
        }

        double getSatelliteTwoTime()
        {
            return satelliteTwoTime;
        }

        double getSatelliteThreeTime()
        {
            return satelliteThreeTime;
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

        double satelliteOneTime;
        double satelliteTwoTime;
        double satelliteThreeTime;
        double homebaseTime;

        Rover()
        {
            location = 0;
            time = 0;
            satelliteOneTime = 0;
            satelliteTwoTime = 0;
            satelliteThreeTime = 0;
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

        void setSatelliteOneTime(double a)
        {
            satelliteOneTime = a;
        }

        void setSatelliteTwoTime(double a)
        {
            satelliteTwoTime = a;
        }

        void setSatelliteThreeTime(double a)
        {
            satelliteThreeTime = a;
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

        double getSatelliteOneTime()
        {
            return satelliteOneTime;
        }

        double getSatelliteTwoTime()
        {
            return satelliteTwoTime;
        }

        double getSatelliteThreeTime()
        {
            return satelliteThreeTime;
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
    int z;
    int diameterOne;
    int diameterTwo;
    int diameterThree;
    int a;
    int b;
    int c;
    char roveR = 'x';
    char satelliteONE = 'S1';
    char satelliteTWO = 'S2';
    char satelliteTHREE = 'S3';
    char homeBase = 'H';
    double var1 = 0.0000001;
    double var2 = 0.0000001;
    double var3 = 0.0000001;
    char grid[60][60];

    TOA toa = TOA();
    Homebase homebase = Homebase();
    Satellite satelliteOne = Satellite();
    Satellite satelliteTwo = Satellite();
    Satellite satelliteThree = Satellite();
    Rover rover = Rover();

    satelliteOne.setTime(0.0000001); // time that rover to satellite, satellite would send back that value and it is held until sent to homebase
    satelliteTwo.setTime(0.0000001);
    satelliteThree.setTime(0.00000001);
    homebase.setTime(0.0000001); // time that rover to homebase, homebase would send that value back and it is held until sent back to homebase

    rover.setHomebaseTime(homebase.getTime());
    rover.setSatelliteOneTime(satelliteOne.getTime());
    rover.setSatelliteTwoTime(satelliteTwo.getTime());
    rover.setSatelliteThreeTime(satelliteThree.getTime());

    homebase.setHomebaseTime(rover.getHomebaseTime());
    homebase.setSatelliteOneTime(rover.getSatelliteOneTime());
    homebase.setSatelliteTwoTime(rover.getSatelliteTwoTime());
    homebase.setSatelliteThreeTime(rover.getSatelliteThreeTime());
    
    while(1)
    {
        rover.setHomebaseTime(homebase.getTime());
        rover.setSatelliteOneTime(satelliteOne.getTime());
        rover.setSatelliteTwoTime(satelliteTwo.getTime());
        rover.setSatelliteThreeTime(satelliteThree.getTime());
    
        homebase.setHomebaseTime(rover.getHomebaseTime());
        homebase.setSatelliteOneTime(rover.getSatelliteOneTime());
        homebase.setSatelliteTwoTime(rover.getSatelliteTwoTime());
        homebase.setSatelliteThreeTime(rover.getSatelliteThreeTime());
    
    
        toa.setTime(homebase.getHomebaseTime());
        toa.calculateLocation();
        x = toa.getLocation();
        cout << endl;
        //cout << "Location from Homebase: " << toa.getLocation() << " meters ";
        toa.setTime(homebase.getSatelliteOneTime());
        toa.calculateLocation();
        y = toa.getLocation();
        //toa.calculateDiameter(x,y);
        //diameterOne = toa.getDiameter();
        toa.setTime(homebase.getSatelliteTwoTime());
        toa.calculateLocation();
        z = toa.getLocation();
        //cout << "Location from Satellite: " << toa.getLocation() << " meters" << endl;
    
        cout << "x: " << x << " y: " << y << " z: " << z << endl;

        toa.calculateIntersection(x,y);

        a = toa.getX();
        b = toa.getY();

        toa.calculateIntersection(x,z);
        c = toa.getY();

        cout << "a: " << a << " b: " << b << " c: " << c << endl;
    
        for(int i = 0; i < 60; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                grid[i][j] = '-';
            }
        }

        grid[a][b] = roveR;
        grid[0][0] = homeBase;
        grid[0][59] = satelliteONE;
        grid[59][0] = satelliteTWO;
        grid[59][59] = satelliteTHREE;
        
        //system("CLS");  
        
        for(int i = 0; i < 60; i++)
            {
                for(int j = 0; j < 60; j++)
                {
                    cout << grid[i][j];
                }
                cout << endl;
            }
            
        satelliteOne.setTime(var1); // time that rover to satellite, satellite would send back that value and it is held until sent to homebase
        satelliteTwo.setTime(var2);
        satelliteThree.setTime(0.00000001);
        homebase.setTime(var3); // time that rover to homebase, homebase would send that value back and it is held until sent back to homebase
        
        var1 += 0.00000000005;
        var2 -= 0.000000005;
        var3 += 0.000000005;
    }


    toa.setTime(homebase.getHomebaseTime());
    toa.calculateLocation();
    x = toa.getLocation();
    cout << endl;
    //cout << "Location from Homebase: " << toa.getLocation() << " meters ";
    toa.setTime(homebase.getSatelliteOneTime());
    toa.calculateLocation();
    y = toa.getLocation();
    //toa.calculateDiameter(x,y);
    //diameterOne = toa.getDiameter();
    toa.setTime(homebase.getSatelliteTwoTime());
    toa.calculateLocation();
    z = toa.getLocation();
    //cout << "Location from Satellite: " << toa.getLocation() << " meters" << endl;

    cout << "x: " << x << " y: " << y << " z: " << z << endl;

    toa.calculateIntersection(x,y);

    a = toa.getX();
    b = toa.getY();

    toa.calculateIntersection(y,z);
    c = toa.getY();

    cout << "a: " << a << " b: " << b << " c: " << c << endl;

    //char grid[60][60];
    for(int i = 0; i < 60; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                grid[i][j] = '-';
            }
        }
    grid[x][y] = roveR;
    grid[0][0] = homeBase;
    grid[0][59] = satelliteONE;
    grid[59][0] = satelliteTWO;
    grid[59][59] = satelliteTHREE;

    for(int i = 0; i < 60; i++)
        {
            for(int j = 0; j < 60; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    return 0;
}