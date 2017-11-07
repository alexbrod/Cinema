#ifndef  MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;




class Movie
{
public:
	enum eGenre{ACTION, COMEDY, DRAMA, HORROR, THRILLER};
	static const int GENRE_TYPES_NUM = 5;
protected:
	char* name;
	int lengthInMinutes;
	char** actorsList;
	int numberOfActors=0;
	int ageLimit;
	eGenre genre;
public:
	Movie(const char* name, int lengthInMinuttes,const char** actorsList, int numberOfActors, int ageLimit, eGenre genre);
	Movie(const Movie& movie);

	static const int MAX_ACTORS_IN_MOVIE = 5;
	static const char* toStringGenre(eGenre genre);

	virtual ~Movie();
	const Movie& operator=(const Movie& other);
	const bool operator<(const Movie& other);
	const bool operator>(const Movie& other);

	const char *getName() const;

	void setName(const char *name);

	int getLengthInMinutes() const;

	void setLengthInMinuttes(int lengthInMinutes);

	const char **getActorsList() const;

	void setActorsList(const char **actorsList);

	int getAgeLimit() const;

	void setAgeLimit(int ageLimit);

	eGenre getGenre() const;

	void setGenre(eGenre genre);

	int getNumberOfActors() const;

	void setNumberOfActors(int numberOfActors);

	friend ostream& operator<<(ostream& os, const Movie& movie);

	virtual void toOs(ostream &os) const{};

};

#endif