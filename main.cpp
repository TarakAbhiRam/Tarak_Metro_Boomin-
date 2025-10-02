#include<bits/stdc++.h>
#include "metro_mgmt.cpp"
using namespace std;

void makegraph(Manager &m){
   
   m.add_node("JNTU college");
   m.add_node("Kukatpally");
   m.add_node("Bharat Nagar");
   m.add_node("ESI Hospital");
   m.add_node("S.R.Nagar");
   m.add_node("Ammerpet");
   m.add_node("Hitech City");
   m.add_node("Raidurg");
   m.add_node("Peddama gudi");
   m.add_node("Yusufguda");
   m.add_node("Khairatabad");
   m.add_node("Nampally");
   m.add_node("MG Bus Station");
   m.add_node("Rasoolpura");
   m.add_node("JBS Parade ground");
   m.add_node("Musheerabad");
   m.add_node("Narayana guda");
   m.add_node("Musarambagh");
   m.add_node("Chaitanyapuri");
   m.add_node("LB Nagar");
   m.add_node("Mettuguda");
   m.add_node("NGRI");
   m.add_node("Nagole");
   m.add_edge("JNTU college","Kukatpally",1.5);
   m.add_edge("Bharat Nagar","Kukatpally",2);
   m.add_edge("Bharat Nagar","ESI Hospital",1);
   m.add_edge("S.R.Nagar","ESI Hospital",0.5);
   m.add_edge("S.R.Nagar","Ammerpet",0.5);
   m.add_edge("Yusufguda","Ammerpet",1);
   m.add_edge("Yusufguda","Peddama gudi",3);
   m.add_edge("Hitech City","Peddama gudi",2);
   m.add_edge("Hitech City","Raidurg",0.5);
   m.add_edge("Rasoolpura","Ammerpet",3);
   m.add_edge("Rasoolpura","JBS Parade ground",1);
   m.add_edge("Musheerabad","JBS Parade ground",2);
   m.add_edge("Musheerabad","Narayana guda",3);
   m.add_edge("MG Bus Station","Narayana guda",1);
   m.add_edge("MG Bus Station","Nampally",2);
   m.add_edge("Khairatabad","Nampally",2);
   m.add_edge("Khairatabad","Ammerpet",2);
   m.add_edge("Mettuguda","JBS Parade ground",1);
   m.add_edge("Mettuguda","NGRI",2);
   m.add_edge("Nagole","NGRI",2);
   m.add_edge("MG Bus Station","Musarambagh",2);
   m.add_edge("Chaitanyapuri","Musarambagh",1);
   m.add_edge("Chaitanyapuri","LB Nagar",1);
   m.flloyd_warshall();
   cout<<"List of all stations in the metro network:\n"<<endl;
   m.list_all_stations();
   cout<<"Total number of stations in the metro network:"<<endl;
   m.cnt_stations();
}
int main(){
    
    Manager m(23);
    makegraph(m);
    user u(m.getNode(),m.getDIstance(),m.getStationCOunt(),m.getindex());
    string s1,s2;

    // Get valid source station
    cout << "Enter source station:" << endl;
    getline(cin, s1);
    while (m.check_error(s1)) {
        cout << "Invalid source station name, please enter again:" << endl;
        getline(cin, s1);
    }

    // Get valid destination station (not same as source)
    cout << "Enter destination station:" << endl;
    getline(cin, s2);
    while (m.check_error(s2) || s1 == s2) {
        if (m.check_error(s2)) {
            cout << "Invalid destination station name, please enter again:" << endl;
        } else if (s1 == s2) {
            cout << "Source and destination cannot be the same. Please enter a different destination:" << endl;
        }
        getline(cin, s2);
    }
    int price = u.get_price(s1,s2);
    int short_dis = u.short_distance(s1,s2);    
    if(short_dis==INT_MAX){
        cout<<"No path exists between "<<s1<<" and "<<s2<<endl;
    }
    else{
        cout<<"Shortest distance between "<<s1<<" and "<<s2<<" is: "<<short_dis<<" km"<<endl;
        cout<<"Price of ticket is: "<<price<<" Rs"<<endl;
    }
}