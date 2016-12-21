#include <iostream>
#include "deque.h"
#include <cstdlib>

using namespace std;

int main(){
	string str;
	getline(cin,str);
	Deque<char> q;
	for(int i=0;i<str.size();++i){
	  if(str[i]=='A'||str[i]=='C'||str[i]=='T'||str[i]=='G'){
	  q.addLast(str[i]);
	  }
	  else{
	    cout<<"false"<<endl;
	    return 0;
	  }
	}
        Deque<char>::Iterator head = q.iterator();
	Deque<char>::Iterator rear = q.iterator();
        for(int i = 0; i < q.size();i++){++rear;}
	for(int i = 0; i < q.size();i++){
	  if((*head=='A'&&*rear=='T')||(*head=='T'&&*rear=='A')
	    ||(*head=='C'&&*rear=='G')||(*head=='G'&&*rear=='C')){
	      head++;
	      rear--;
	    }
	    else{
	      cout<<"false"<<endl;
	      return 0;
	    }
	}
	cout<<"true"<<endl;
	return 0;
}
