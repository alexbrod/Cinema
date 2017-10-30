#ifndef  SCREENING_H
#define SCREENING_H

#include <ostream>
#include "Occasion.h"
#include "Movie.h"

class Screening : public Occasion
{
public:

	Screening(const Date &date, int startHour, int endHour, char *name, Hall *hall);

	virtual ~Screening();

	Movie *getMovie() const;

	void setMovie(Movie *movie);

	friend ostream &operator<<(ostream &os, const Screening &screening);


private:
	Movie* movie;
};

#endif