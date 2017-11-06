#ifndef  CINEMA_H
#define CINEMA_H
#include "Hall.h"
#include "Occasion.h"
#include "Screening.h"
#include "Event.h"

class Cinema
{
private:
	Hall** hallsArray;
	Movie** movieList;
	Lecture** lectureList;
	Occasion** occasionList;

    int currentHalls;
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
	void addMovie(Movie* movie) ;
    void deleteMovie(int index);
	void addLecture(Lecture* lecture) ;
	void deleteLecture(int index);
    void addOccasion(Occasion* occasion) ;
    bool deleteOccasion(const Occasion& occasion);
	void initHallsArray(int numOfHalls) ;
	void initMovieList(int numOfMovies, const char** moviesNames,
					   const char* actors[][Movie::MAX_ACTORS_IN_MOVIE],
					   const int NUM_OF_ACTORS[]);
	void initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames) ;
	const SeatTicket& buyTicket(const Occasion& occasion);

    Occasion* getOccasionByIndex(int index);
    Movie* getMovieByIndex(int index);
    Lecture* getLectureByIndex(int index);
    Hall* getHallByIndex(int index);
    Screening* getScreeningByIndex(int index);

	void showMovies() const;
	void showLectures() const;
    bool showOccasionsAssigendToHalls() const;
    bool showOccasionsWithoutHalls() const;
    void showAllOccasions() const;
    void showScreenings();


    const bool operator+=(Movie& other);	// add movie to list
	const bool operator-=(Movie& other);	// remove movie from list
	const Movie operator[](int index);	//return the movie at index


    void showEmptyHalls() const;

};

#endif