#ifndef COMPITO_2_TPA2_H
#define COMPITO_2_TPA2_H
#include <iostream>
using namespace std;


class Floor
{

public:
    double leng;
    double wid;

    Floor(double leng, double wid);

    void set_l(double leng);
    double get_l() const {return leng;}
    void set_w(double wid);
    double get_w() const {return wid;}
    double area(double leng, double wid) const;



};

class Room: public Floor //Room class inherited from Floor class
{
protected:
    double area = Floor::area(leng, wid);

public:

    Room(double leng, double wid, double h, double p);

    static double i;
    double pep;

    double height = 2.7;
    double vol{};

    void set_h(double height);
    double get_h() const {return height;}
    void set_p(double p);
    double get_p() const {return pep;}

    bool check(double pep, double area, double vol) const;

    double volume(double leng, double wid, double height);

    double add_people(double pep, double i, double area_tot, double vol_tot);
    static double remove_people(double pep, double r);
    double empty_room(double pep);

   //
    static void min_rooms(int n);
};

class Palace : public Room //Palace class inherited from Room class
{
public:
    int n_rooms{};
    double area_tot{};
    double vol_tot{};
    int pep_tot{};
    double *house{};
    double area = Floor::area(leng, wid);

    Palace();

    double add_and_remove(int pep, double area_tot, double vol_tot);
    Room operator+(Palace *house);
};

#endif //COMPITO_2_TPA2_H
