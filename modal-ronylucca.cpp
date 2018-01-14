
//Modal aplication test


#include<cstring>
#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	while(scanf("%s",word)!=EOF){
		len=strlen(word);
		if(!validate()){
			printf("0\n");
			continue;
		}

char limit='a';
		int index=1;
		
		for(int i=0;i<len;i++){
			for(char first=limit;first<word[i];first++)
				index+=count(first,len-i);
			limit=word[i]+1;
		}

		for(int i=1;i<len;i++)
			index+=join(26,i);
		printf("%d\n",index);
	}
	return 0;
}

//inputfile reader


//validate word

//aggregator