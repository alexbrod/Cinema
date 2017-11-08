#ifndef  CINEMA_H
#define CINEMA_H
#include "Hall.h"
#include "Occasion.h"
#include "Screening.h"
#include "Event.h"
#include "MyLinkedList.h"

class Cinema
{
private:
	MyLinkedList<Hall*> hallsList;
	vector<Movie*> movieList;
	vector<Lecture*> lectureList;
	vector<Occasion*> occasionList;


public:  //when you change the methodes to throw exeptions  - write void insted of bool
    const int MAX_HALLS;

    explicit Cinema(int maxHalls);
	virtual ~Cinema() = default;
	void addMovie(Movie* movie) ;
    void deleteMovie(int index);
	void addLecture(Lecture* lecture) ;
	void deleteLecture(int index);
    void addOccasion(Occasion* occasion) ;
    void deleteOccasion(const Occasion& occasion);
	void initHallsArray(int numOfHalls) ;
	void initMovieList(const vector<string>& moviesNames, const vector<vector<string>>& actors);
	void initLectureList(const vector<string>& hostNames, const vector<string>& lectureNames) ;
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
    bool showScreenings();
    bool showEmptyHalls() const;


    const bool operator+=(Movie& other);	// add movie to list
	const bool operator-=(Movie& other);	// remove movie from list
	const Movie operator[](int index);	//return the movie at index



};

#endif