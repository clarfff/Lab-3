import math
import matplotlib.pyplot as plt
import numpy as np

xZERO = 500
yZERO = 220

im = plt.imread("C:/Users/Clark/OneDrive - Texas Tech University/Desktop/Lab3/techmap.jpg")
def calculateRadius(time):
    location = time * 300000000

    return location

def calculateIntersectionOne(a, b):
    y = ((pow(a, 2) - pow(b, 2)) + 3481) / 118
    x = (math.sqrt((-pow(a, 4) + (2 * pow(a, 2) * (pow(b, 2) + 3481) -pow(pow(b, 2) - 3481, 2)))))/118

    return x,y

x = 0
y = 0
z = 0
t = 0

diameterOne = 0
diameterTwo = 0
diameterThree = 0

x1 = 0
y1 = 0
x2 = 0
y2 = 0

r1 = 0
r2 = 0
r3 = 0

rover = 'x'
satelliteONE = 'S1'
satelliteTWO = 'S2'
satelliteTHREE = 'S3'
homeBase = 'H'

var1 = 0.0000001
var2 = 0.0000001
var3 = 0.0000001

r1 = calculateRadius(var1+0.000000005)
r2 = calculateRadius(var2+0.000000009)
r3 = calculateRadius(var3+0.000000005)

print("Radius: " + str(r1))
print("Radius 2: " + str(r2))

x1,y1 = calculateIntersectionOne(r1,r2)

print("Intersection: " + str(x1) + ' ' + str(y1))

x2,y2 = calculateIntersectionOne(r1,r3)

print("Intersection: " + str(x2) + ' ' + str(y2))

while((x1 <= 250) or (y1 <= 250)):
    r1 = calculateRadius(var1)
    r2 = calculateRadius(var2)
    r3 = calculateRadius(var3)

    print("Radius: " + str(r1))
    print("Radius 2: " + str(r2))

    x1,y1 = calculateIntersectionOne(r1,r2)

    print("Intersection: " + str(x1) + ' ' + str(y1))

    x2,y2 = calculateIntersectionOne(r1,r3)

    print("Intersection: " + str(x2) + ' ' + str(y2))

    var1 = var1 + 0.000000009
    var2 = var2 + 0.000000005
    var3 = var3 + 0.000000005
    implot = plt.imshow(im)

    plt.scatter([xZERO + x1],[yZERO + x2], c='r')

    plt.pause(0.2)
    plt.clf()

    