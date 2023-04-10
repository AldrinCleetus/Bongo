#include "utility_functions.h"

sf::Vector2f Utility::normalizeVector(sf::Vector2f vect)
{
    float length = sqrt((vect.x * vect.x) + (vect.y * vect.y));
    if (length != 0)
        return sf::Vector2f(vect.x / length, vect.y / length);
    else
        return vect;
}
