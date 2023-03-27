

// F

#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,i1,j1,i2,j2;
        string d;
        cin>>n>>m>>i1>>j1>>i2>>j2;
        cin>>d;
        int bounces = 0;
        int x=i1,y=j1;
        string dir = d;
        while(true){
           if(d == "DL"){
             if(i2 >= i1 && j2 <= j1 && (i2-i1 == j1-j2)){
                cout<<bounces<<endl;
                break;
             }
             else if(x >= i1 && y <= j1 && (x - i1 == j1 - y) && d == dir && bounces!=0){
                cout<<"-1"<<endl;
                break;
             }
             else{
                    int horobstacle = n - i1;
                    int verobstacle = j1 - 1;
                    if(horobstacle < verobstacle){
                        bounces++;
                        d = "UL";
                        i1 = i1 + horobstacle;
                        j1 = j1 - horobstacle;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else if(horobstacle > verobstacle){
                        bounces++;
                        d = "DR";
                        i1 = i1 + verobstacle;
                        j1 = j1 - verobstacle;
                        if(i1==x && j1==y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else{
                        bounces++;
                        d = "UR";
                    }
                
                }
           }
           else if(d == "UL"){
              if(i2 <= i1 && j2 <= j1 && (i1-i2 == j1-j2)){
                cout<<bounces<<endl;
                break;
              }
              else if(x <= i1 && y <= j1 && (i1 - x == j1 - y) && d == dir && bounces!=0){
                cout<<"-1"<<endl;
                break;
             }
              else{
                int horobstacle = i1 - 1;
                int verobstacle = j1 - 1;
                    if(horobstacle < verobstacle){
                        bounces++;
                        d = "DL";
                        i1 = i1 - horobstacle;
                        j1 = j1 - horobstacle;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else if(verobstacle < horobstacle){
                        bounces++;
                        d = "UR";
                        i1 = i1 - verobstacle;
                        j1 = j1 - verobstacle;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else{
                       bounces++;
                        d = "DR";
                    }
              }
           }
           else if(d == "UR"){
             if(i2 <= i1 && j2 >= j1 && (i1-i2 == j2-j1)){
                cout<<bounces<<endl;
                break;
             }
             else if(x <= i1 && y >= j1 && (i1 - x == y - j1) && d == dir && bounces!=0){
                cout<<"-1"<<endl;
                break;
             }
             else{
                int hor = i1 - 1;
                int ver = m - j1;
                    if(hor < ver){
                        bounces++;
                        d = "DR";
                        i1 = i1 - hor;
                        j1 = j1 + hor;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else if(ver < hor){
                        bounces++;
                        d = "UL";
                        i1 = i1 - ver;
                        j1 = j1 + ver;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else{
                        bounces++;
                        d = "DL";
                    }
             }
           }
           else if(d == "DR"){
              if(i2 >= i1 && j2 >= j1 && (i2-i1 == j2-j1)){
                cout<<bounces<<endl;
                break;
              }
              else if(x >= i1 && y >= j1 && (x - i1 == y - j1) && d == dir && bounces!=0){
                cout<<"-1"<<endl;
                break;
             }
              else{
                int hor = n - i1;
                int ver = m - j1;
                    if(hor < ver){
                        bounces++;
                        d = "UR";
                        i1 = i1 + hor;
                        j1 = j1 + hor;
                        if(i1 == x && j1 == y && d==dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else if(ver < hor){
                        bounces++;
                        d = "DL";
                        i1  = i1 + ver;
                        j1 = j1 + ver;
                        if(i1 == x && j1 == y && d == dir){
                            cout<<"-1"<<endl;
                            break;
                        }
                    }
                    else{
                        bounces++;
                        d = "UL";
                    }
              }
           }
        }
    }
    return 0;
}