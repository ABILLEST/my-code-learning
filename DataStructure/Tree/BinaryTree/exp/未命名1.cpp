#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define ok 1
#define error -1
const int maxW= 9999;
 
class HuffNode{
    public:
        int weight;
        int parent;
        int leftChild;
        int rightChild;
        char name;
};
 
class HuffMan{
    private:
        void MakeTree(){
            for(int i= lnum+ 1; i<= len; i++){
                int s1, s2;
                SelectMin(i- 1, &s1, &s2);
                
                huffTree[s1].parent= huffTree[s2].parent= i;
                huffTree[i].leftChild= s1;
                huffTree[i].rightChild= s2;
                huffTree[i].weight= huffTree[s1].weight+ huffTree[s2].weight;
            }
        }
        void SelectMin(int pos, int *s1, int *s2){
            int w1, w2, i;
            w1= w2= maxW;
            *s1= *s2= 0;
             
            for(i= 1; i<= pos ; i++){
                if(w1> huffTree[i].weight&&!huffTree[i].parent){
                     
                    w2= w1;
                    *s2= *s1;
                     
                    w1= huffTree[i].weight;
                    *s1= i;
                     
                }
                else if(w2> huffTree[i].weight&&!huffTree[i].parent){
                    w2= huffTree[i].weight;
                    *s2= i;
                }
            }
        }
         
    public:
        int len;
        int lnum;
        HuffNode *huffTree;
        string *huffCode;
        void MakeTree(int n, int wt[], char nam[]){
            int i;
            lnum= n;
            len= 2*n- 1;
            huffTree = new HuffNode[2*n];
            huffCode= new string[lnum+ 1];
             
            for(i= 1; i<= n; i++){
                huffTree[i].weight= wt[i- 1];
                huffTree[i].name= nam[i- 1];
                //cout<<huffTree[i].name<<endl;
            }
                
             
            for(i= 1; i<= len; i++){
                if(i> n)
                 huffTree[i].weight= 0;
                 huffTree[i].parent= 0;
                 huffTree[i].leftChild= 0;
                 huffTree[i].rightChild= 0;
            }
            MakeTree();
        }
        void Coding(){
            char *cd;
            int i, c, f, start;
             
            cd= new char[lnum];
            cd[lnum- 1]= '\0';
            for(i= 1; i<= lnum; i++){
                start= lnum- 1;
                 
                for(c= i, f= huffTree[i].parent; f!= 0; c= f, f= huffTree[f].parent)
                   if(huffTree[f].leftChild== c){
                    cd[--start]= '0';
                    
                   } 
                   else{
                    cd[--start]= '1';
                  
                   }
                  
                 
                huffCode[i].assign(&cd[start]);
                //cout<<huffCode[i]<<&cd[start]<<endl;
            }
             
            delete []cd;
        }
        void Destroy(){
            len= 0;
            lnum= 0;
            delete []huffTree;
            delete []huffCode;
        }
         
        int deCode(const string codestr, char txtstr[]){
            int i, k, c;
            char ch;
            c= len;
            k= 0; 
             
            for(int i= 0; i< codestr.length();i++){
                 
                ch= codestr[i];
                 
                if(ch== '0'){
                    //cout<<ch<<endl;
                    c= huffTree[c].leftChild;
                }
                if(ch== '1'){
                    c= huffTree[c].rightChild;
                }
             
                if(ch!= '0'&&ch!= '1')
                 return error;
                if(!huffTree[c].leftChild&&!huffTree[c].rightChild){
                    txtstr[k++]= huffTree[c].name;
                   
                    c= len;
                   }
                else{
                    ch= '\0';
                }
            }
            if(ch== '\0')
            return error;
            else
            txtstr[k]= '\0';
            return ok;
        }
};
 
int main(){
    int t, n,i,j;
    int wt[800];
    char ch[800];
     
    HuffMan myHuff;
    cin>>t;
    for(i= 0; i< t; i++){
         
         
         
        cin>>n;
        for(j= 0; j< n; j++)
           cin>>wt[j];
        for(j= 0; j< n; j++){
            cin>>ch[j];
            //cout<<ch[j]<<endl;
        }
            
            
        myHuff.MakeTree(n, wt, ch);
 
        int in;
        cin>>in;
        while(in--){
            string str;
            char txt[800];
            cin>>str;
            //cout<<str<<endl;
            if(myHuff.deCode(str, txt)!= -1)
            cout<<txt<<endl;
            else
            cout<<"error"<<endl;
        }
 
 
 
 
 
        myHuff.Destroy();
    }
    return 0;
}

