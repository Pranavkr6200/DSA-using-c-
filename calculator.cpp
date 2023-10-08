#include <iostream>
using namespace std;
int main(){
    int x, a, b;
    cout<<"enter no. b/w 1-4 "<<endl;
    cin>>x;
    cout<<"enter two digits"<<endl;
    cin>>a>>b;
    int sum, div, multi, sub;
    switch (x) {
            case 1 :
                sum = a + b;
                cout<<"sum= "<<sum;
                break;
            case 2 :
                sub = a - b;
                cout<<"sub= "<<sub;
                break;
            case 3 :
                multi = a * b;
                cout<<"multi= "<<multi;
                break;
            case 4 :
                div = a / b;
                cout<<"div= "<<div;
                break;
            
            default :
            cout<<"wrong case";
        }


}
