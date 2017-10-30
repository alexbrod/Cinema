#include <iostream>
#include "Lecture.h"
#include "Movie.h"
#include "Cinema.h"
 using namespace std;

const int MAX_HALLS = 7;
const int HALLS_NUM = 5;
const int MAX_LECURES = 10;
const int LECTURES_NUM = 5;
const int MAX_MOVIES = 10;
const int MOVIES_NUM = 3;
const int MAX_OCCASIONS = 10;

const char* MOVIES_NAMES[] = {"ARMAGEDDON", "MiB", "ACE VENTURA"};
const char* HOST_NAMES[] = {"Prof. Higgins", "Dr. Dolittle", "Dr. Strange", "Dr. Evil", "Dr. Gray"};
const char* LECTURES_NAMES[] = {"Is our universe the only universe?",
                              "How to read the genome and build a human being",
                                "Artificial Intelligence, the History and Future",
                                "Zombie Roaches and other Parasite Tales",
                                "Catching Gravitational Waves"};
const char* actors[MOVIES_NUM][Movie::MAX_ACTORS_IN_MOVIE];

int main()
{

    actors[0][0] = {"Bruce Willis"};
    actors[0][1] = {"Leave Taylor"};
    actors[1][0] = {"Will Smith"};
    actors[2][0] = {"Jim Carrey"};

    Occasion* occasionList[MAX_OCCASIONS];

    int handler,select;
    Cinema cinema(MAX_HALLS, MAX_LECURES, MAX_MOVIES, MAX_OCCASIONS);
    cinema.initHallsArray(HALLS_NUM);
    //TODO: check how to pass the ACTORS arrays
    cinema.initMovieList(MOVIES_NUM, MOVIES_NAMES, actors);
    cinema.initLectureList(LECTURES_NUM, HOST_NAMES, LECTURES_NAMES);
    //cinema.initOccasionList();
    cout << "press 1 for customer or 2 for employee \n";
    cin >> handler;
    switch(handler) {
        case 1: //customer
            cinema.showOccasions();
            cout << "press number of occasion \n";
            cin >> select;
            cinema.buyTicket(cinema.getOccasionByIndex(select));
            break;

        case 2: //employee

            cout << "Select option:\n"
                    "1 to add a movie\n"
                    "2 to add lecture\n"
                    "3 to create screening occasion\n"
                    "4 to create lecture occasion\n"
                    "5 to create event(screening + lecture)\n";
            cin >> select;
            switch (select)
            {
                case 1:
                    //need to implement step by step actions to add a movie
                    break;
                case 2:
                    //need to implement step by step actions to add a lecture
                    break;
                case 3:
                    //need to implement step by step actions to add a event
                    break;
            }

        default:
            cout << "you chose an invalid option";
    }
    return 0;
}