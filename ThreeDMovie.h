#ifndef  THREEDMOVIE_H
#define THREEDMOVIE_H

#include <ostream>
#include "Movie.h"

class ThreeDMovie : virtual public Movie
{
public:
	ThreeDMovie(const ThreeDMovie& threeDMovie):Movie(threeDMovie),glasses(glasses){}
	ThreeDMovie(char * name, double lengthInMinuttes, char** actorsList, int numberOfActors, int ageLimit, eGenre genre, bool glasses):Movie(
			const_cast<char *>(name), lengthInMinuttes,
			const_cast<char **>(actorsList), numberOfActors, ageLimit, genre){}

	ThreeDMovie(char *name, double lengthInMinuttes, char **actorsList, int numberOfActors, int ageLimit, eGenre genre);

	virtual ~ThreeDMovie();

	bool isGlasses() const;

	void setGlasses(bool glasses);

	void show(ostream& os) const;

	friend ostream &operator<<(ostream &os, const ThreeDMovie &movie);


private:
	bool glasses;
};

#endif THREEDMOVIE_H