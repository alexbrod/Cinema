#ifndef  THREEDMOVIE_H
#define THREEDMOVIE_H
#include "Movie.h"

class ThreeDMovie : public Movie
{
public:
	ThreeDMovie(char* name, double length,bool glasses);
	virtual ~ThreeDMovie();
	void setGlasses(bool glasses);
	bool getGlasses() const;

private:
	bool glasses;
};

#endif THREEDMOVIE_H