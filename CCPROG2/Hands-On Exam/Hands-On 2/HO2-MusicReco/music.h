/* You are NOT allowed to modify the contents of this file */

#include <stdio.h>
#include <string.h>

#define MAX 101
#define MAX_SONGS 100 // Constant declaring the no. of songs at most
#define MAX_ARTISTS 50 // Constant declaring the maximum no. of artists
#define MAX_PLAY_ENTRIES 200 // Constant declaring the maximum no. of played entries

typedef char string[MAX]; // All strings contain at most 100 characters, not including the '\0' character at the end!

//Refer to the pdf file for the descriptions of the structures
struct artistTag
{
    int nArtistID;
	string strArtistName; 
};

typedef struct artistTag artistTag;
typedef artistTag artistList[MAX_ARTISTS];

struct songTag
{
    int nSongID;
	string strTitle;
	int nArtistID;
	int nPlayDuration;
};

typedef struct songTag songTag;
typedef songTag songList[MAX_SONGS];

struct playedTag
{
    int nSongID;
	int nDuration;
};

typedef struct playedTag playedTag;
typedef playedTag playList[MAX_PLAY_ENTRIES];

/* Function prototypes */

void printSongInformation(int,songList songs,artistList artists,int,int);
int getMostPlayed(playList list,songList songs,int,int);
void recommendMusic(int,songList songs,artistList artists,int,int);
