#include "user.h"
#include <vector>


void User::addMovie(int movie_id, int seat) {
    movies.push_back(movie_id);
    seats.push_back(seat);
}

void User::setPhone(string number) {
    phone = number;
}