#include <iostream>
#include "randomized_queue.h"
#include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char ** argv){
        if (argc!=2){
	  cout<<"Please specify an output number k!"<<endl;
	  return 0;
	}
	char* endptr;
	long int k=std::strtol(argv[1],&endptr,10);
	if(k<=0){
	  cout<<"Invalid output number k!"<<endl;
	  return 0;
	}
	string str;
	getline(cin,str);
	srand(time(0));
	RandomizedQueue<string> rq;
	int index=0;
        for(int i=0;i<str.size();++i){
	  if(str[i]==' '){
	    char word[i-index+1];
	    for(int k=0;k<i-index;++k){
	      word[k]=str[index+k];
	    }
	    word[i-index]='\0';
	    index=i+1;
	    rq.enqueue(word);
	  }
	  else if(str.size()==i+1){
	    char word[i-index+2];
	    for(int k=0;k<i-index+1;++k){
	      word[k]=str[index+k];
	    }
	    word[i-index+1]='\0';
	    index=i+1;
	    rq.enqueue(word);
	  }
	}
	RandomizedQueue<string>::Iterator itr = rq.iterator();
	for(long int i = 0; i < k;i++){
	  cout << *itr << endl;
	  if(itr.get_index()>=itr.get_randsize()-1&&itr.get_randsize()<k){
	    cout<<"Floating exception"<<endl;
	    break;
	  }
	  ++itr;
	}
	return 0;
}
