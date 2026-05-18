#include<iostream>
#include<stack>
using namespace std ;

int costInsertion( string s ){
    stack<char> st ;
    int closingCost = 2 ;   ;
    int openingCost = 1 ;
    int cost = 0 ;
    cout << s.length() << endl ;
    for(int i = 0 ; i < s.length() ; i++ ){
        if(s[i] == ')'){
            if(!st.empty()){
                st.pop() ;
            }else {
                cost += openingCost ;
            }

        }else{
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        cost += closingCost ;
        st.pop() ;
    }

    return cost ;
}

int main(){

    string s = "))))(";
    int cost = costInsertion(s);
    cout<< cost ;
    return 0 ;
}