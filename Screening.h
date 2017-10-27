#ifndef  SCREENING_H
#define SCREENING_H
#include "Occasion.h"
#include "Movie.h"

class Screening : public Occasion
{
public:
	Screening(Date date, int startHour, int endHour, Hall* hall, Movie* movie);
	virtual ~Screening();
	void setMovie(Movie* movie);
	Movie* getMovie();

private:
	Movie* movie;
};

#endif