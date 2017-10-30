#include "ThreeDMovie.h"

ThreeDMovie::ThreeDMovie(char *name, double lengthInMinuttes, char **actorsList, int numberOfActors, int ageLimit,
                         Movie::eGenre genre) : Movie(name, lengthInMinuttes, actorsList, numberOfActors, ageLimit,
                                                      genre) {}

bool ThreeDMovie::isGlasses() const {
    return glasses;
}

void ThreeDMovie::setGlasses(bool glasses) {
    ThreeDMovie::glasses = glasses;
}

ostream &operator<<(ostream &os, const ThreeDMovie &movie) {
    os << " 3DMovie: "<< static_cast<const Movie &>(movie) << " 3DMovie glasses: " << movie.glasses;
    return os;
}

