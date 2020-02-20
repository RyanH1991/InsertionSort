#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
  
void print(vector<int> &year, vector<string> &firstname, vector<string> &lastname) 
{ 
    for (int i=0;i<year.size();i++){
        cout << *(firstname.begin()+i) << " " << *(lastname.begin()+i) << " " << *(year.begin()+i) << endl;
    }
    cout << endl; 
} 

void insertionSort(vector<int> &year, vector<string> &firstname, vector<string> &lastname) 
{ 
    int newposcounter=0;
    int oldposcounter=0;
    auto it2 = firstname.begin();
    auto it3 = lastname.begin();
    for (auto it = year.begin(); it != year.end(); it++) {
    //it is new, i is old
        auto insertpoint = year.begin();
        
        auto i2 = firstname.begin();
        auto i3 = lastname.begin();

        int change = 0;
        for (auto i=year.begin();i<it;i++){
            if(*i>*it){
                //if old is bigger
                insertpoint = i;
                rotate(i, it, it+1);
                rotate(i2, it2, it2+1);
                rotate(i3, it3, it3+1);
                //print(year,firstname,lastname); 
                change = 1;
                i=it;
            }
            else if(*i==*it){
                int comp = (*it2).compare(*i2);
                if (comp<0){
                    insertpoint = i;
                    rotate(i, it, it+1);
                    rotate(i2, it2, it2+1);
                    rotate(i3, it3, it3+1);
                    //print(year,firstname,lastname); 
                    change = 1;
                    i=it;
                }
                else if(comp == 0){
                    int complast = (*it3).compare(*i3);
                    if(complast<0){
                        insertpoint = i;
                        rotate(i, it, it+1);
                        rotate(i2, it2, it2+1);
                        rotate(i3, it3, it3+1);
                        //print(year,firstname,lastname); 
                        change = 1;
                        i=it;
                    }
                    else{
                        //print(year,firstname,lastname); 
                    }
                    
                }
                else{
                    //print(year,firstname,lastname); 
                }
            }
            else{
                //print(year,firstname,lastname); 
            }
            oldposcounter++;
            i2++;
            i3++;
        }
        it2++;
        it3++;
        if(it!=year.begin()){
            print(year,firstname,lastname); 
        }

        //print(year,firstname,lastname); 
    } 
    newposcounter++;
    oldposcounter=0;
} 


int main() {
    vector<int> year = {2014,2014};  
    vector<string> firstname = {"mingming","emma"};
    vector<string> lastname = {"feng","ziegellaub-eichler"};
    insertionSort(year,firstname,lastname);     
    //print(year,firstname,lastname); 
    return 0;
}
