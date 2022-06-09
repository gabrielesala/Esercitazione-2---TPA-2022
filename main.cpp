#include <iostream>
#include "tpa2.h"

using namespace std;

int main() {
    // Fornire informazioni riguardanti: n. stanze, area totale pavimenti, area totale pareti, volume totale stanze

    double leng, vol, wid, height, area, heigth, area_tot, vol_tot, pep_tot;
    int pep; //people initially in the room
    int n; //n. rooms to create

    //create Floor & Room & Palace
    Floor base(leng, wid);
    Room stan(leng, wid, height, pep);
    Palace lobby;

    cout<<"Enter the number of rooms (min. 4 rooms): \n";
    cin>>n; //stores total no of rooms from user
    stan.min_rooms(n); //method to control rooms' amount chosen is equal or greater to 4
    Palace house[n]; //initialises that n instance of class palace will be created
    for(int i=0; i<n; i++){ //loop used to take input for different properties for different rooms from user
        cout << "Room " << i+1 << ":" << endl;
        cout<<"Enter the lenght of the room: \n";
        cin>> stan.leng;
        base.set_l(stan.leng); //control function to avoid lenght <=0
        house[i].leng = stan.leng;
        cout<<"Enter the width of the room: \n";
        cin>> stan.wid;
        base.set_w(stan.wid); //control function to avoid width <=0
        house[i].wid = stan.wid;
        cout<<"Enter the height of walls: \n";
        cin>> stan.height; //control function to avoid height <=0
        stan.set_h(stan.height);
        house[i].height = stan.get_l();
        cout<<"Enter number of people in the room: \n";
        cin>>house[i].pep;
        house[i].area = base.area(house[i].leng, house[i].wid);
        house[i].vol = stan.volume(house[i].leng, house[i].wid, house[i].height);
        pep_tot += house[i].pep;
        area_tot += house[i].area;
        vol_tot += house[i].vol;
    }

    cout << " " << endl;
    cout << "Total population of the palace is: " << pep_tot << endl;
    cout << "Total area of the palace is: " << area_tot << endl;
    cout << "Total volume of the palace is: " << vol_tot << endl;
    pep_tot = lobby.add_and_remove(pep_tot, area_tot, vol_tot); //add population until saturation, remove people from the palace
    cout << "Population after performing the fire alarm: " << pep_tot << endl; //population in the palace after esecuting the fire alarm
    cout << " " << endl;
    cout << "##################TMP_ROOM (Operator+ Test)###################" << '\n';
    Room tmp_room = lobby.operator+(house); //operator+ function esecution
    cout << "TMP_ROOM:" << '\n';
    cout << "Lenght of the temporary room (it was chosen to sum the width, therefore the lenght output is = to the lenght of the second room chosen): " << tmp_room.leng << endl;
    cout << "Width of the temporary room (sum of the width of the rooms chosen): " << tmp_room.wid << endl;
    cout << "Height of the temporary room (the output is the greater height of the rooms chosen): " << tmp_room.height << endl;
    // cout << "Population of the temporary room (the output is the population sum of the rooms chosen): " << tmp_room.height << endl; *not required, but available*
    cout << "#############################TEST END#########################";
    return 0;

}
