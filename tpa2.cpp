#include "tpa2.h"
#include <iostream>
using namespace std;

// FLOOR CONSTRUCTOR, AREA CALC
Floor::Floor(double leng, double wid) //Floor constructor
{
    this->leng = leng;
    this->wid = wid;
}

void Floor::set_l(double l){ //Function to get lenght of the room, returns error if length <= 0
    if(l <= 0)
        throw std::invalid_argument("Lenght must be non-negative or zero.");
    this->leng = l;
}

void Floor::set_w(double w){ //Function to get width of the room, returns error if width <= 0
    if(w <= 0)
        throw std::invalid_argument("Width must be non-negative or zero.");
    this->wid = w;
}

double Floor::area(double leng, double wid) const //Function to obtain area
{
    double area = leng * wid;
    return area;
}


//ROOM CONSTRUCTOR, VOL CALC, POP CHECK
Room::Room(double leng, double wid, double h, double p) : Floor(leng, wid) { //Room constructor
    this->height = h;
    this->pep = p;
}

void Room::set_h(double h){ //Function to get width of the room, returns error if height <= 0
    if(h <= 0)
        throw std::invalid_argument("Height must be non-negative or zero.");
    this->height = h;
}

void Room::set_p(double p){ //Function to get width of the room, returns error if height <= 0
    if(p < 0)
        throw std::invalid_argument("Population must be non-negative.");
    this->pep = p;
}

 void Room::min_rooms(int n) //method to check if the user tries to input less than 4 rooms
{
    if (n < 4)
        throw std::invalid_argument("Rooms amount has to be 4 or above");
}

bool Room::check(double pep, double area, double vol) const //method to check whether vital space conditions are met
{
    bool n = false;
    double x, y;
    x = area/pep;
    y = vol/pep;
    if(x > 8) {
        if (y > 10)
            n = true;
    }
    return n;
}

double Room::volume(double leng, double wid, double height) //method to calculate volume
{
    vol = height * wid * leng;
    return vol;
}

//people
double Room::add_people(double pep, double i, double area_tot, double vol_tot) //method to add people, Overpopulated warning is set when people have < 8mq (area)/12mc (vol) each
{
    Floor ctrl(leng, wid);
    if (check(pep, area_tot,vol_tot)){
        pep = pep + i;
    }
    if (check(pep, area_tot,vol_tot)){
        return pep;
    }
    if (!check(pep, area_tot,vol_tot)){
        cout << "Overpopulated" << endl;
    }
    return pep;
}

double Room::remove_people(double pep, double r) //method to remove people, attention is paid if the number of people to be removed is greater than the number of people presented
{
    if (pep >= r)
    {
        pep = pep - r;
    }
    if (pep < r)
    {
        cout << "You can't remove more people than there are present in the room" << endl;
    }
    return pep;
}

double Room::empty_room(double pep) //method to empty the room
{
    pep = 0;
    cout << "You emptied the room" << endl;
    return pep;
}


//PALACE

Palace::Palace() : Room(leng, wid, height, pep) //Palace constructor
{

}

double Palace::add_and_remove(int pep, double area_tot, double vol_tot) //add and remove method (using random values between 0 and 100 through rand() % 100
{
    Floor(leng, wid);
    while (check(pep, area_tot, vol_tot)) {
        int l = rand() % 100;
        pep = add_people(pep, l, area_tot, vol_tot);
    }
    cout << "It gets saturated at " << pep << " people" << endl;
    pep = empty_room(pep);
    return pep;
}


Room Palace::operator+(Palace *house){ //method operator+, the user can choose which rooms to sum (lenght = lenght of the second room chose, width = sum of width, height = max height, population = sum of population)
    int x, y;
    cout << "Choose rooms to sum:" << endl;
    cin >> x >> y;
    if (x <= 0)
        throw std::invalid_argument("Rooms' id_number can't be less than 0");
    if (y <= 0)
        throw std::invalid_argument("Rooms' id_number can't be less than 0");
    Room tmp_room = {house[x-1].leng, house[x-1].wid + house[y-1].wid, max(house[x-1].height, house[y-1].height), house[x-1].pep+house[y-1].pep};
    return tmp_room;
}
