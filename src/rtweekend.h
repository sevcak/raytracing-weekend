#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

using std::make_shared;
using std::shared_ptr;


/* Common headers */

#include "vec3.h"
#include "color.h"
#include "ray.h"


/* Constants */

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;


/* Utility functions */

inline double degrees_to_radians( double degrees )
{
    return degrees * pi / 180.0;
}

#endif
