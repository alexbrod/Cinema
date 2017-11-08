#ifndef  MOVIE_H
#define MOVIE_H
#include <iostream>
#include<vector>
using namespace std;

class Movie
{
public:
	enum eGenre{ACTION, COMEDY, DRAMA, HORROR, THRILLER};
	static const int GENRE_TYPES_NUM = 5;
protected:
	string name;
	int lengthInMinutes;
	vector<string> actorsList;
	int ageLimit;
	eGenre genre;
public:
	Movie(const string& name, int lengthInMinuttes, const vector<string>& actorsList, int ageLimit, eGenre genre);
	Movie(const Movie& movie);

	static const int MAX_ACTORS_IN_MOVIE = 5;
	static const string toStringGenre(eGenre genre);

	virtual ~Movie() = default;
	const bool operator<(const Movie& other);
	const bool operator>(const Movie& other);

	const string& getName() const;

	void setName(const string& name);

	int getLengthInMinutes() const;

	void setLengthInMinuttes(int lengthInMinutes);

	const vector<string>& getActorsList() const;

	void setActorsList(const vector<string>& actorsList);

	int getAgeLimit() const;

	void setAgeLimit(int ageLimit);

	eGenre getGenre() const;

	void setGenre(eGenre genre);

	friend ostream& operator<<(ostream& os, const Movie& movie);

	virtual void toOs(ostream &os) const{};

};

#endif