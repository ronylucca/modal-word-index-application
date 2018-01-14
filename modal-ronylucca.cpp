
//Modal aplication test


#include<cstdio>
#include <stdio.h>
#include<cstring>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;


const int WORD_LEN_MAX=30;
char word[WORD_LEN_MAX+1];

int len;
FILE *fp;
int t;


//validate word
bool validate(){
	for(int i=0;i+1<len;i++)
		for(int j=i+1;j<len;j++)
        {
			if(word[i]>=word[j])
            {
                return false;
            }
        }
	return true;
}


//aggregator
int aggregate(int total,int unit)
{
	if(total < unit)
		return 0;
	if(total-unit < unit)
		return aggregate(total, total-unit);
	int result=1;
	for(int i = 0; i<unit; i++)
		result=result*(total-i)/(i+1);
	return result;
}

//counter
int append(char first,int len)
{
	return aggregate('z'-first,len-1);
}


int main(){

    char temp[30];
    fstream data;

    data.open("in.txt",ios::in);

           while (!data.eof()){
            data.getline(word, sizeof(data));
            len = strlen(word);
            
            if(!validate()){
                printf("0\n");
                continue;
            }
            char limit='a';
            int initial=1;
            
            for(int i=0; i<len; i++){
                for(char first=limit; first<word[i]; first++)
                    initial+=append(first, len-i);
                limit=word[i]+1;
            }

            for(int i=1; i<len;i++)
                initial+= aggregate(26,i);
            
            printf("%d\n", initial);

        }
        data.close();
  
  return 0;
}