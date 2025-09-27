#include "math.h"

double round(double number) {
    return (number >= 0.0) ? floor(number + 0.5) : ceil(number - 0.5);
}
