#include <iostream>
#include "Cinema.h"
 using namespace std;

const int NUM_OF_HALLS = 5;

int main()
{
    int handler,select,movie,lecture;

    Cinema cinema(NUM_OF_HALLS);
    cinema.initHallsArray();
    cinema.initMovieList();
    cinema.initLectureList();
    cinema.initOccasionList();
    cout << "press 1 for customer or 2 for employee \n";
    cin >> handler;
    if (handler == 1) {
        cout << "press 1 for movie , 2 for lecture \n";
        cin >> select;
        if (select == 1) {
            cinema.showMovies();
            cout << "choose movie to buy ticket\n";
            cin >> movie;
            cinema.buyTicket(movie);
        }
        else if (select == 2) {
            cinema.showLectures();
            cout << "choose lecture to buy ticket\n";
            cin >> lecture;
            cinema.buyTicket(lecture);
        }
    }
    else if(handler == 2){
        cout << "press 1 to add a movie, 2 to add lecture , 3 to add movie+lecture \n";
        cin >> select;
        if (select == 1) {
            cinema.addMovieToList();
        }
        else if (select == 2) {
            cinema.addLecture();
        }
        else {
            cinema.addEvent();
        }
    }
    else {
        cout << "you chose an invalid option";
    }
    return 0;
}