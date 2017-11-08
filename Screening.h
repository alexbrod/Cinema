#ifndef  SCREENING_H
#define SCREENING_H
#include <ostream>
#include "Occasion.h"
#include "Movie.h"



class Screening : virtual public Occasion
{
private:
	const Movie* movie;
public:

	Screening(const string& name, const Date &date, int startHour, int endHour, const Movie& movie);

	virtual ~Screening();

    virtual const Movie* getMovie() const;

    virtual void setMovie(const Movie& movie);

	virtual void setHall(Hall* hall);

	virtual Hall* getHall() const;

    virtual void toOs(std::ostream& os) const;
};



#endif