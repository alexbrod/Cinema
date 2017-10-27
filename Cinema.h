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

public:  //when you change the methodes to throw exeptions  - write void insted of bool
	Cinema(int numOfHalls);
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
	bool deleteHall(int index);
	void initHallsArray();
	void initMovieList();
	void initLectureList();
	void initOccasionList();
	bool buyTicket(Occasion* occasion);

	void showMovies();
	void showLectures();
	void addMovieToList();
	void addLecture();

	const bool operator+=(Movie other);	// add movie to list
	const bool operator-=(Movie other);	// remove movie from list
	const Movie operator[](int index);	//return the movie at index

	void addEvent();
	void buyTicket(int id);
};

#endif