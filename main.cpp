#include <iostream>
#include <cstring>
#include <limits>
#include "Lecture.h"
#include "Movie.h"
#include "Cinema.h"
#include "ThreeDMovie.h"

using namespace std;

const int MAX_CH_IN_NAME = 100;
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
const char* ACTORS[MOVIES_NUM][Movie::MAX_ACTORS_IN_MOVIE];
const int NUM_OF_ACTORS[MOVIES_NUM] = {2,1,1};

void createScreeningOccasion(Cinema& cinema);
void addLecture(Cinema& cinema);
void buyTicket(Cinema& cinema);
void assignHallToOccasion(Cinema& cinema);
void addMovieToList(Cinema& cinema);
void createEventOccasion(Cinema& cinema);


int main()
{
    bool exit = false;
    int select;

    ACTORS[0][0] = {"Bruce Willis"};
    ACTORS[0][1] = {"Leave Taylor"};
    ACTORS[1][0] = {"Will Smith"};
    ACTORS[2][0] = {"Jim Carrey"};
    const char* GUARDIAN_ACTORS[1];
    Lecture* tmpLecture;
    GUARDIAN_ACTORS[0] = {"Ashton Kutcher"};
    Movie* movie = new Movie("The Gaurdian",120,GUARDIAN_ACTORS,1,12,Movie::DRAMA);
    Screening* screening = new Screening("Birthday Screening",
            Date(2017,11,5),20,21,*movie);
    Lecture* lecture = new Lecture("Do schools kill creativity?",
            "Ken Robinson",Date(2017,11,5),18,19);

    Cinema cinema(MAX_HALLS, MAX_LECURES, MAX_MOVIES, MAX_OCCASIONS);
    cinema.initHallsArray(HALLS_NUM);
    cinema.initMovieList(MOVIES_NUM, MOVIES_NAMES, ACTORS, NUM_OF_ACTORS);
    cinema.initLectureList(LECTURES_NUM, HOST_NAMES, LECTURES_NAMES);
    cinema.addMovie(movie);
    cinema.addLecture(lecture);
    cinema.addOccasion(screening);
    while(!exit)
    {
        cout << "Press 0 for Exit, 1 for customer or 2 for employee \n";
        cin >> select;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (select) {
            case 0:
                exit = true;
                break;
            case 1: //customer
                cout << "Press number of occasion to buy ticket to:\n0. don\'t buy\n";
                if (cinema.showOccasionsAssigendToHalls())
                    buyTicket(cinema);
                break;
            case 2: //employee

                cout << "Select option:\n"
                        "1 to create screening occasion\n"
                        "2 to create lecture occasion\n"
                        "3 to create event(screening + lecture)\n"
                        "4 to set hall to occasion\n"
                        "5 to delete occasion\n"
                        "6 to add movie to list\n"
                        "7 to add lecture to list\n"
                        "8 to delete movie\n"
                        "9 to delete lecture\n"
                        "10 to show movies list\n"
                        "11 to show lecture list\n";
                cin >> select;
                cin.ignore();
                switch (select) {
                    case 1:
                        createScreeningOccasion(cinema);
                        break;
                    case 2:
                        cout << "Choose lecture to add to occasion list:\n0. Abort\n";
                        cinema.showLectures();
                        cin >> select;
                        if (select == 0)
                            break;
                        try {
                            tmpLecture = cinema.getLectureByIndex(select);
                            cinema.addOccasion(new Lecture(*tmpLecture));
                            cout << "Lecture occasion created\n";
                        }
                        catch (const char *e) {
                            cout << "Occasion not created. Reason: " << e << endl;
                        }
                        break;
                    case 3:
                        createEventOccasion(cinema);
                        break;
                    case 4:
                        cout << "Choose occasion to assign or press 0 to abort:\n";
                        if (cinema.showOccasionsWithoutHalls())
                            assignHallToOccasion(cinema);
                        break;
                    case 5:
                        cout << "Choose occasion to delete:\n 0. Abort\n";
                        cinema.showAllOccasions();
                        cin >> select;
                        if (select == 0)
                            break;
                        try {
                            cinema.deleteOccasion(*cinema.getOccasionByIndex(select));
                            cout << "Occasion deleted" << endl;
                        }
                        catch (const char *e) {
                            cout << "Occasion not deleted. Reason: " << e << endl;
                        }
                        break;
                    case 6:
                        try {
                            addMovieToList(cinema);
                            cout << "Movie added" << endl;
                        }
                        catch (const char *e) {
                            cout << "Movie was not added to list. Reason: " << e << endl;
                        }
                        break;
                    case 7:
                        addLecture(cinema);
                        break;
                    case 8:
                        cout << "Choose movie to delete or 0 to abort:\n";
                        cinema.showMovies();
                        cin >> select;
                        if (select == 0) break;
                        try {
                            cinema.deleteMovie(select);
                            cout << "Movie deleted" << endl;
                        }
                        catch (const char *e) {
                            cout << "Movie not deleted. Reason: " << e << endl;
                        }
                        break;
                    case 9:
                        cout << "Choose lecture to delete or 0 to abort:\n";
                        cinema.showLectures();
                        cin >> select;
                        if (select == 0) break;
                        try {
                            cinema.deleteLecture(select);
                            cout << "Lecture deleted" << endl;
                        }
                        catch (const char *e) {
                            cout << "Lecture not deleted. Reason: " << e << endl;
                        }
                        break;
                    case 10:
                        cinema.showMovies();
                        break;
                    case 11:
                        cinema.showLectures();
                        break;
                    default:
                        cout << "You chose an invalid option\n";
                        break;
                }
                break;
            default:
                cout << "You chose an invalid option\n";
        }
    }
    return 0;
}


void createScreeningOccasion(Cinema& cinema)
{
    char *name = new char[MAX_CH_IN_NAME];
    int year, month, day, startHours, endHours;
    int movieNum;
    Screening *screening;
    cout << "Adding Screening:\nPlease enter name: ";
    cin.getline(name, MAX_CH_IN_NAME,'\n');
    cout << "Please enter Date:\n Year (yyyy): ";
    cin >> year;
    cout << "Month (MM): ";
    cin >> month;
    cout << "Day (dd): ";
    cin >> day;
    cout << "Please enter time:\n start hour (hh): ";
    cin >> startHours;
    cout << "Please enter time:\n end hour (hh): ";
    cin >> endHours;
    cout << "Choose movie:\n";
    cinema.showMovies();
    cin >> movieNum;
    try
    {
        screening = new Screening(
                name,
                Date(year, month, day),
                startHours, endHours, *cinema.getMovieByIndex(movieNum));
        cinema.addOccasion(screening);
        cout << "Screening added to occasion list" << endl;
    }
    catch(const char* e)
    {
        cout << "Occasion not created. Reason: " << e << endl;
    }
}

void addLecture(Cinema& cinema)
{
    char *name = new char[MAX_CH_IN_NAME];
    char *hostName = new char[MAX_CH_IN_NAME];
    int year, month, day, startHours, endHours;
    Lecture *lecture;
    cout << "Adding Lecture:\nPlease enter name: ";
    cin.getline(name, MAX_CH_IN_NAME,'\n');
    cout << "Please enter host name: ";
    cin.getline(hostName, MAX_CH_IN_NAME,'\n');
    cout << "Please enter Date:\n Year (yyyy): ";
    cin >> year;
    cout << "Month (MM): ";
    cin >> month;
    cout << "Day (dd): ";
    cin >> day;
    cout << "Please enter time:\n start hour (hh): ";
    cin >> startHours;
    cout << "Please enter time:\n end hour (hh): ";
    cin >> endHours;
    try
    {
        lecture = new Lecture(
                name,hostName,
                Date(year, month, day),
                startHours, endHours);
        cinema.addLecture(lecture);
        cout << "Lecture added to list" << endl;
    }
    catch(const char* e)
    {
        cout << "Lecture not added. Reason: " << e << endl;
    }
}

void buyTicket(Cinema& cinema)
{
    int select;
    cin >> select;
    if (select != 0)
    {
        try
        {
            const SeatTicket& seatTicket = cinema.buyTicket(*cinema.getOccasionByIndex(select));
            cout << "Ticket bought: " << seatTicket << endl;
        }
        catch(const char* e)
        {
            cout << "Ticket was not bought. Reason: " << e << endl;
        }
    }
}

void assignHallToOccasion(Cinema& cinema)
{
    int select,hallNumber;
    cin >> select;
    if(select == 0) return;
    cout << "Choose Hall, or press 0 to abort:\n";
    if(!cinema.showEmptyHalls()) return;
    cin >> hallNumber;
    if(hallNumber != 0)
    {
        try
        {
            cinema.getOccasionByIndex(select)->setHall(cinema.getHallByIndex(hallNumber));
            cout << "Occasion assigned to hall" << endl;
        }
        catch(const char* e)
        {
            cout << "Occasion was not assigned to hall. Reason: " << e << endl;
        }
    }
}

void addMovieToList(Cinema& cinema)
{
    Movie *movie;
    char *name = new char[MAX_CH_IN_NAME];
    char *answerString = new char[MAX_CH_IN_NAME];
    const char* actors[1][Movie::MAX_ACTORS_IN_MOVIE];
    int movieLength, ageLimit, numOfActors = 0, genre;
    cout << "Adding Movie:\nPlease enter name: ";
    cin.getline(name, MAX_CH_IN_NAME,'\n');
    cout << "Please enter length (in minutes): ";
    cin >> movieLength;
    cout << "Please age limit: ";
    cin >> ageLimit;
    cout << "Choose genre:\n";
    for (int i = Movie::ACTION ; i <= Movie::THRILLER ; ++i)
    {
        cout << i+1 << ". " << Movie::toStringGenre(static_cast<Movie::eGenre>(i)) << endl;
    }
    cin >> genre;
    if(genre < 0 && genre >= Movie::GENRE_TYPES_NUM)
    {
        cout << "No such genre\n";
        return;
    }
    cin.ignore();
    cout << "If you want the 3D movie? press \'y\': ";
    cin >> answerString;
    if(strcmp(answerString,"y") == 0)
    {
        movie = new ThreeDMovie(name, movieLength,
                                actors[1], numOfActors,
                                ageLimit,
                                static_cast<Movie::eGenre>(genre-1),
                                true);
    }
    else
    {
        movie = new Movie(name, movieLength,
                          actors[1], numOfActors,
                          ageLimit,
                          static_cast<Movie::eGenre>(genre-1));
    }

    cinema.addMovie(movie);
}

void createEventOccasion(Cinema& cinema)
{
    int lectureNum, screeningNum;
    Event* event;
    cout << "Choose lecture:\n0 - Abort\n";
    cinema.showLectures();
    cin >>  lectureNum;
    if(lectureNum == 0) return;
    cout << "Choose screening:\n0 - Abort\n";
    if(!cinema.showScreenings()) return;
    cin >>  screeningNum;
    if(lectureNum == 0) return;
    try
    {
        event = new Event(*cinema.getScreeningByIndex(screeningNum),
            *cinema.getLectureByIndex(lectureNum));
        cinema.addOccasion(event);
        cout << "Event was added to occasion list" << endl;
    }
    catch (const char* e)
    {
        cout << "Event was not created. Reason: " << e << endl;
    }
}