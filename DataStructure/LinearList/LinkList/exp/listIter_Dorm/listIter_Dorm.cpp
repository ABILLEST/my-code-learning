#include<iostream>
#include<list>
#include<vector>
using namespace std;

const int maxx= 50;
string str[maxx];
list<int> l1;
list<int> l2;

void ass(string s){//安排学生
    list<int>::iterator it= l2.begin();
//  cout<<*it;
    str[*it- 100]= s;
    l1.push_back(*it);
    l2.pop_front();

}

void ret(int i){//归还宿舍
    list<int>::iterator it= l1.begin();
    while(it!= l1.end()){
        if(*it== i)
         break;
         it++;
    }
    l2.push_back(*it);
    l1.erase(it);

}

void used(){//输出已用的宿舍号
    l1.sort(); 
    list<int>::iterator it= l1.begin();
    while(it!= l1.end()){
        cout<<str[*it- 100]<<'('<<*it<<')';
        it++;
        if(it!= l1.end())
         cout<<'-';
    }
    cout<<endl;
}

void fre(){//输出可使用的宿舍号
    list<int>::iterator it= l2.begin();
    while(it!= l2.end()){
        cout<<*it;
        it++;
        if(it!= l2.end())
         cout<<'-';
    }
}

int main(){


    vector<int> vec(25, 0);
    int n;
    int j;
    string s;
    cin>>n;
    for(int i= 0; i< n; i++){
        cin>>s;
        cin>>j;

        str[j- 100]= s;
        l1.push_back(j);
        vec[j- 100]= 1;

    } 

    for(int i= 1; i<= 20; i++){//记录可使用的宿舍号
        if(!vec[i]){
            l2.push_back(i+ 100);
        }
    }

    int m;
    cin>>m;
    while(m--){
        string s;
        cin>>s;
        if(s== "assign"){
            string name;
            cin>>name;
            ass(name);
            //cout<<'a';
        }
        else if(s== "return"){
            int shu;
            cin>>shu;
            ret(shu);
        }
        else if(s== "display_used"){
            used();
        }
        else{
            fre();
        }
    }
    return 0;
}
