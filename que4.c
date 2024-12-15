#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Define the maximum number of rows
#define MAX_LINES 100
//Definethe maximum length of a word
#define MAX_WORD_LEN 50
//Define a structure to store word information
typedef struct {
char word[MAX_WORD_LEN];//store wordd
int totalCount;//total num. of occurence of the word
int lineCount[MAX_LINES];}WordInfo;//the num. of occurrence of the word in each line

//wordInfos:Array of structures to store word information
//wordCount:the number of words stored
//word:the word to check
int isWordInArray(WordInfo wordInfos[],int wordCount,char *word)
{
    for(int i=0;i<wordCount;i++)
  {
    if(strcmp(wordInfos[i].word,word)==0){return i;} 
  }
    return -1;
}

void countWords(char *lines[],int lineCount,WordInfo *wordInfos,int *wordCount) 
{ 
    for(int i=0;i<lineCount;i++)
 {char *token=strtok(lines[i]," ");//get words by space division
    while(token!=NULL){
    int index=isWordInArray(wordInfos,*wordCount,token);//check if the word already exists
    if (index!=-1){
    wordInfos[index].lineCount[i]++;
    wordInfos[index].totalCount++;
    }else{ if(*wordCount<MAX_LINES){
    strcpy(wordInfos[*wordCount].word,token);//copy words into structure
    memset(wordInfos[*wordCount].lineCount,0,sizeof(int)*MAX_LINES);
    wordInfos[*wordCount].lineCount[i]=1;
    wordInfos[*wordCount].totalCount=1;
    (*wordCount)++;}  }
    token=strtok(NULL," ");}//get the next word
 }
}
int main()
{   char *lines[MAX_LINES];   
    int lineCount=0;
    printf("shu ru:\n");
    //loop to receive multi-line strings of user input
    while (lineCount<MAX_LINES){
    lines[lineCount]=(char*)malloc(MAX_WORD_LEN);
    scanf("%[^\n]%*c",lines[lineCount]);
    if (strcmp(lines[lineCount],"END")==0){break;}
    lineCount++;}
    WordInfo
    wordInfos[MAX_LINES];
    int wordCount=0;
    countWords(lines,lineCount,wordInfos,&wordCount);
    printf("word\t total rows\t num. per line\n");
    for(int i=0;i<wordCount;i++){
    printf("%s\t%d\t",wordInfos[i].word,wordInfos[i].totalCount);
    for(int j=0;j<lineCount;j++){
    printf("%d",wordInfos[i].lineCount[j]);}printf("\n");}
    //release the memory allocated for each row
    for(int i=0;i<lineCount;i++){free(lines[i]);}
    return 0;
}
