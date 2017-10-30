#ifndef  MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;




class Movie
{
public:
	Movie(char *name, double lengthInMinuttes, char **actorsList, int numberOfActors, int ageLimit, eGenre genre);

	static const int MAX_ACTORS_IN_MOVIE = 5;
	enum  eGenre{ACTION, COMEDY, DRAMA, HORROR, THRILLER};

	virtual ~Movie();
	const Movie operator=(Movie other);
	const bool operator<(Movie other);
	const bool operator>(Movie other);

	const char *getName() const;

	void setName(const char *name);

	double getLengthInMinuttes() const;

	void setLengthInMinuttes(double lengthInMinuttes);

	const char **getActorsList() const;

	void setActorsList(const char **actorsList);

	int getAgeLimit() const;

	void setAgeLimit(int ageLimit);

	eGenre getGenre() const;

	void setGenre(eGenre genre);

	int getNumberOfActors() const;

	void setNumberOfActors(int numberOfActors);

	friend ostream& operator<<(ostream& os, const Movie& movie);




protected:
	const char* name;
	double lengthInMinuttes;
	const char** actorsList;
	int numberOfActors=0;
	int ageLimit;
	eGenre genre;

	virtual void toSrting(ostream &os) const;
};

#endif