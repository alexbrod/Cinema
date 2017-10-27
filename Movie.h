#ifndef  MOVIE_H
#define MOVIE_H

class Movie
{
public:
	enum  eGenre{ACTION, COMEDY, DRAMA, HORROR, THRILLER};

	Movie(char* name,double length, char** actorsList, int ageLimit, eGenre genre);
	virtual ~Movie();
	const Movie operator=(Movie other);
	const bool operator<(Movie other);
	const bool operator>(Movie other);
	char* getName();
	void setName(char* name);
	double getLength();
	void setLength(double length);
	char** getActorsList();
	void addActor(char* actorName);
	int getAgeLimit();
	void setAgeLimit(int age);
	eGenre getGenre();
	void setGenre(int index);
	
private:
	char* name;
	double lengthInMinuttes;
	char** actorsList;
	int ageLimit;
	eGenre genre;
};

#endif