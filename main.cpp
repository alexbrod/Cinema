#include <iostream>
#include "Cinema.h"
 using namespace std;

const int MAX_HALLS = 7;
const int HALLS_NUM = 5;
const int MAX_LECURES = 10;
const int LECTURES_NUM = 5;
const int MAX_MOVIES = 10;
const int MOVIES_NUM = 3;
const int MAX_OCCASIONS = 10;
const int MAX_ACTORS_IN_MOVIE = 5;

const char* MOVIES_NAMES[] = {"ARMAGEDDON", "MiB", "ACE VENTURA"};
const char* HOST_NAMES[] = {"Prof. Higgins", "Dr. Dolittle", "Dr. Strange", "Dr. Evil", "Dr. Gray"};
const char* LECTURES_NAMES[] = {"Is our universe the only universe?",
                              "How to read the genome and build a human being",
                                "Artificial Intelligence, the History and Future",
                                "Zombie Roaches and other Parasite Tales",
                                "Catching Gravitational Waves"};
const char * ACTORS[MOVIES_NUM][MAX_ACTORS_IN_MOVIE];



int main()
{
    ACTORS[0] = {"Bruce Willis", "Leave Taylor"};
    ACTORS[1] = {"Will Smith"};
    ACTORS[2] = {"Jim Carrey"};

    int handler,select,movie,lecture;
    Cinema cinema(MAX_HALLS, MAX_LECURES, MAX_MOVIES, MAX_OCCASIONS);
    cinema.initHallsArray(HALLS_NUM);
    //TODO: check how to pass the ACTORS arrays
    cinema.initMovieList(MOVIES_NUM, MOVIES_NAMES, static_cast<const char ***>(ACTORS));
    cinema.initLectureList(LECTURES_NUM, HOST_NAMES, LECTURES_NAMES);
    //cinema.initOccasionList();
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