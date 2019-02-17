#include <stdio.h>
#include <string.h>

typedef struct WordStruct Word;
struct WordStruct {
  Word * next;
  Word * previous;
  char * string;
  int matchCounter;
};

typedef struct WordListStruct WordList;
struct WordListStruct {
  Word * start;
  Word * cur;
};



void addToList(WordList * wordList, char * token)
{
  /* put token into word struct */
  Word cur;
  cur.string = token;
  cur.next = NULL;

  cur.previous = wordList->cur;
  wordList->cur->next = &cur;
}

WordList createWordList(char * string)
{
  WordList wordList;
  const char s[2] = " ";
  char * token;

  /* get the first token */
  token = strtok(string,s);

  /* put token into word struct */
  Word cur;
  cur.next = NULL;
  cur.previous = NULL;
  cur.string = token;

  /* put word struct into word list */
  wordList.start = &cur;
  wordList.cur = wordList.start;

  /* walk through other tokens */
  while(token != NULL) {
    printf("%s\n",token);
    token = strtok(NULL, s);
    addToList(&wordList,token);
  }

  return wordList;
}

void deleteElement(Word * toDelete)
{
  /* re-link the next element's previous with the current's previous */
  toDelete->next->previous = toDelete->previous;

  /* re-link the previous element's next with the current's next */
  toDelete->previous->next = toDelete->next;

  // no need to free anything since everything's on the stack

  /* since toDelete has been removed from the list, move the pointer on */
  toDelete = toDelete->next;

}

void findMatches(WordList * wordList)
{
  Word * cur, * compare;
  cur = wordList->start;
  while(cur != NULL) {
    compare = wordList->start;
    while(compare != NULL) {
      if(strcmp(cur->string,compare->string)==0) {
        cur->matchCounter++;
        deleteElement(compare);
      } else {
        compare = compare->next;
      }
    }
    cur = cur->next;
  }
}

void printMatches(WordList * wordList)
{
  Word * cur;
  cur = wordList->start;
  while(cur != NULL) {
    printf("%s %i\n",cur->string,cur->matchCounter);
    cur = cur->next;
  }
}

int main()
{
  char inputString[] = {"Hello there. My name is Roy something, and I do nothing \
  for a living. I can't believe that is okay, but I do it anyways."};
  WordList wordList = createWordList(inputString);
  printMatches(&wordList);
  findMatches(&wordList);
  printMatches(&wordList);
  return 0;
}
