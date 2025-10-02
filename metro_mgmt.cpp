#include<bits/stdc++.h>
using namespace std;

class MetroMap{
protected:
    int index;
    int no_of_stations;
    shared_ptr<unordered_map<string,int>> node;
    shared_ptr<vector<vector<float>>> distance;
public:
    MetroMap(){
        index=0;
        no_of_stations=0;
        node= make_shared<unordered_map<string,int>>();
        distance = make_shared<vector<vector<float>>>();
    }
    MetroMap(int no_of_stations){
        this->no_of_stations = no_of_stations;
        index=0;
        node = make_shared<unordered_map<string,int>>();
        //initialise distance matix with infinity
        distance = make_shared<vector<vector<float>>>(no_of_stations,vector<float>(no_of_stations,INT_MAX));
        for(int i=0;i<no_of_stations;i++){
            (*distance)[i][i]= 0;
        }
    }

    virtual void add_node(string s){}
    virtual void flloyd_warshall(){}
    virtual void add_edge(string s1,string s2,float dis){}
    shared_ptr<unordered_map<string,int>> getNode() const{return node;}
    shared_ptr<vector<vector<float>>> getDIstance() const{return distance;}
    int getindex() const{return index;}
    int getStationCOunt() const{return no_of_stations;}

    virtual ~MetroMap(){
        //destructor
    }
};

class Manager: public MetroMap{
    public:
    Manager(int no_of_stations):MetroMap(no_of_stations){
    }
    void add_node(string s) override{
        if(node->find(s)==node->end()){
            (*node)[s]=index;
            index++;
        }
    }
    
    void flloyd_warshall() override{
        for(int via=0;via<no_of_stations;via++){
            for(int i=0;i<no_of_stations;i++){
                for(int j=0;j<no_of_stations;j++){
                    if((*distance)[i][via]!=INT_MAX && (*distance)[via][j]!=INT_MAX){
                        (*distance)[i][j] = min((*distance)[i][j], (*distance)[i][via]+(*distance)[via][j]);
                    }
                }
            }
        }
    }
    void add_edge(string s1,string s2,float dis) override{
        if(node->find(s1)!= node->end()&& node->find(s2)!= node->end()){
            int u = (*node)[s1];
            int v = (*node)[s2];
            (*distance)[u][v] = dis;
            (*distance)[v][u] = dis;
        }
   
    }
    void list_all_stations() {
        int i = 1;
        for(auto &it : *node) {
            cout << i << ". " << it.first << endl;
            i++;
        }
    }
    void cnt_stations() {
        cout << no_of_stations << endl;
    }
    bool check_error(string s1){
        return node->find(s1)==node->end();
    }
 ~Manager(){}
};

class user: public MetroMap{
    public:
    user(shared_ptr<unordered_map<string,int>> node, shared_ptr<vector<vector<float>>> distance, int no_of_stations, int index){
        this->node = node;
        this->distance = distance;
        this->no_of_stations = no_of_stations;
        this->index = index;
    }
   int short_distance(string s1,string s2){
        int u =(*node)[s1];
        int v =(*node)[s2];
        return (*distance)[u][v];
   }
    

    int get_price(string s1,string s2){
        int min_price = 10;
        int short_dis = short_distance(s1,s2);
        int cost = 10*short_dis;
        int price = max(min_price,cost);
        return price;
    }
    ~user(){}
};
