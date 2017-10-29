#ifndef  CINEMA_H
#define CINEMA_H
#include "Hall.h"
#include "Movie.h"
#include "Occasion.h"
#include "Lecture.h"
#include "Screening.h"
#include "Event.h"

class Cinema
{
private:
	Hall** hallsArray;
	Movie** movieList;
	Lecture** lectureList;
	Occasion** occasionList;
    int numOfActiveHalls;
    int currentLectures;
    int currentMovies;
    int currentOccasions;

public:  //when you change the methodes to throw exeptions  - write void insted of bool
    const int MAX_HALLS;
    const int MAX_LECTURES;
    const int MAX_MOVIES;
    const int MAX_OCCASIONS;
    Cinema(int maxHalls, int maxLectures, int maxMovies, int maxOccasions);
	virtual ~Cinema();
	void addMovie(Movie* movie) throw(const char*);
    bool deleteMovie(const Movie& movie);
	bool addLecture(Lecture* lecture) throw(const char*);
	bool deleteLecture(const Lecture& lecture);
	void addHall(Hall* hall) throw(const char*);
	bool deleteHall(const Hall& hall);
    void addOccasion(Occasion* occasion) throw(const char*);
    bool deleteOccasion(Occasion& occasion);
	void initHallsArray(int numOfHalls) throw(const char*);
	void initMovieList(int numOfMovies, const char** moviesNames, const char* actors[][Movie::MAX_ACTORS_IN_MOVIE]) throw(const char*);
	void initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames) throw(const char*);
	void initOccasionList(Occasion** occasionList);
	const SeatTicket& buyTicket(const Occasion& occasion);
    bool cancelTicket(Occasion& occasion, SeatTicket& seatTicket) throw(const char*);

    const Occasion& getOccasionByIndex(int index);
    const Movie& getMovieByIndex(int index);
    const Lecture& getLectureByIndex(int index);

	void showMovies() const;
	void showLectures() const;
    void showOccasions() const;

	const bool operator+=(Movie other);	// add movie to list
	const bool operator-=(Movie other);	// remove movie from list
	const Movie operator[](int index);	//return the movie at index

};

#endif