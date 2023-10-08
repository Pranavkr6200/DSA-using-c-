#include<iostream>
using namespace std;
int main(){
int a[10],i,freq=0,key;
for(i=0;i<10;i++){
    cout<<"enter number "<<endl;
    cin>>a[i];
}
cout<<"enter no to find frequency"<<endl;
cin>>key;
for(i=0;i<10;i++){
    if(a[i]==key)
    freq++;
}
cout<<"frequency  "<<key<<"--> " <<freq <<endl;

}
