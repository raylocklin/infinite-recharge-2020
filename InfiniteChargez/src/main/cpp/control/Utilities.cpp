#define _USE_MATH_DEFINES
#include "Utilities.h"
#include <math.h>
#include <cmath>
#include <utility>
namespace utilities
{
    std::pair<double, double> squarify(double x, double y)
    {
        double angle{atan2(x, y)};
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

        return std::pair<double, double> {rawSquareRadius * std::cos(angle), rawSquareRadius * std::sin(angle)};
    }

}