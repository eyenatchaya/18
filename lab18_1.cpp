#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
    double xLeft, xRight, yTop, yBottom, xLength, yLength, Area;

    if(R1.x > R2.x) xLeft = R1.x;
    else xLeft = R2.x;

    if(R1.x + R1.w < R2.x + R2.w) xRight = R1.x + R1.w;
    else xRight = R2.x + R2.w;

    if(R1.y < R2.y) yTop = R1.y;
    else yTop = R2.y;

    if(R1.y - R1.h > R2.y - R2.h) yBottom = R1.y - R1.h;
    else yBottom = R2.y - R2.h;

    xLength = xRight - xLeft;
    yLength = yTop - yBottom;

    if((xLeft > xRight) || (yBottom > yTop)) return 0;
    else{
        Area = xLength * yLength;
        return Area;
    }
}
    

int main(){
    Rect R1 = {-1,2,6.9,9.6};
    Rect R2 = {0,0,1.2,2.5};	
    cout << overlap(R1,R2);	
}
// double overlap(Rect R1, Rect R2){
//     double x_dist = min(R1.x + R1.w, R2.x + R2.w) - max(R1.x, R2.x);
//     double y_dist = min(R1.y,R2.y) - max(R1.y-R1.h,R2.y-R2.h);
//     if(x_dist <= 0)
// 	return 0;
//     return x_dist * y_dist;
// }
