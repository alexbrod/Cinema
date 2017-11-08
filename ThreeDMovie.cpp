#include <vector>
#include "ThreeDMovie.h"

ThreeDMovie::ThreeDMovie(string& name, int lengthInMinuttes, const vector<string>& actorsList,
                          int ageLimit, Movie::eGenre genre, bool glasses) :
        Movie(name, lengthInMinuttes, actorsList, ageLimit, genre), glasses(glasses)
{

}



bool ThreeDMovie::isGlasses() const {
    return glasses;
}

void ThreeDMovie::setGlasses(bool glasses) {
    ThreeDMovie::glasses = glasses;
}

void ThreeDMovie::toOs(ostream& os) const
{
    os << (glasses ? " with glasses":" no glasses") << " | 3D-Movie";
}



