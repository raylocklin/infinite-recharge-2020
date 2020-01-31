#define _USE_MATH_DEFINES
#include "Utilities.h"
#include <math.h>
#include <cmath>
#include <utility>
#include <iostream>
#include "Pair2D.h"

namespace utilities
{
    Pair2D<double> squarify(double x, double y)
    {
        //std::cout << "X: " << x << "Y: " << y << '\n';
        double angle{std::atan2(x, y)};
        std::cout << "Angle: " << angle << '\n';
        //Take the percentage from the origin to the edge of the circle
        double circleRadiusPercent{std::sqrt(x * x + y * y)};
        /*Find the maximum distance to a square whose sides are the diameter of the circle from the angle
        *The formula used is the radial equation for a circle by Raven Jyro Felix which uses modulo */
       
        /*Since a square has fourfold radius, the radius repeats four times.
        *Since the formula offsets the angle by pi/2, it must be added to make
        *The circle upright
        */
        double processedAngleForSquare{(std::fmod((angle + M_PI/4), M_PI/2)) - M_PI/4};
        double squareRadiusMax{std::sqrt(std::tan(processedAngleForSquare) + 1)};
        //Generate the radius which is the same percentage from the circle but this time from the origin to suqare square
        double rawSquareRadius{circleRadiusPercent * squareRadiusMax};

        return Pair2D<double> {rawSquareRadius * std::cos(angle), rawSquareRadius * std::sin(angle)};
    }

}