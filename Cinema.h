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
	bool addMovieToList(Movie* movie); 
	bool deleteMovieFromList(int index);
	bool addScreening(Screening* screening);
	bool deleteScreening(int index);
	bool addLecture(Lecture* lecture);
	bool deleteLecture(int index);
	bool addEvent(Event* event);
	bool deleteEvent(Event event);
	bool addHall(Hall* hall);
	bool deleteHall(const Hall& hall);
	void initHallsArray(int numOfHalls);
	void initMovieList(int numOfMovies, const char** moviesNames, const char*** actors);
	void initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames);
	void initOccasionList(Occasion** occasionList);
	bool buyTicket(Occasion* occasion);

	void showMovies() const;
	void showLectures() const;
	void addMovieToList();
	void addLecture();

	const bool operator+=(Movie other);	// add movie to list
	const bool operator-=(Movie other);	// remove movie from list
	const Movie operator[](int index);	//return the movie at index

	void addEvent();
	void buyTicket(int id);
};

#endif