/*
    HANDS-ON #2
    PROBLEM: Music Recommendation
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
*/


/* Definitions are included here in music.h.
Go over it before  attempting to write your solution! */
#include "music.h"

/* DO NOT MODIFY THIS FUNCTION */
void printHeader()
{
	printf ("******************************\n");
	printf ("*My Playlist Recommendations!*\n");
	printf ("******************************\n");
	printf ("\n");
	
	printf ("%-30s","Title");
	printf ("%s\n","Artist");
	printf ("-----------------------------------------------------\n");
}
/*
    TO DO: 
    
    Implement the  functions defined in the music.h header file. 
	
	You may define other functions if you want, which can be called by one or more of the 
	required functions.
	
	RESTRICTIONS:
	1. Make sure to follow the function prototypes specified in music.h
	2. Use only the library function that we discussed in class, within
	   the coverage of the exam and in the course material.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	3. None of the codes that you will implement should include
	   scanf() and printf() statements.
	4. Only code constructs within the coverage and in the course material 
	   can be used.  For example, for strings, only strlen(), strcmp(),
	   strcat(), and strcpy() can be used.
	5. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	6. Do NOT add any other header files.
	7. Do NOT modify the parameters of any of the functions indicated below. You may NOT add 
		or remove any of the parameters indicated
*/


/*
 * TO DO #1
 * Write the implementation for this function. (10 points)
 * 
 * Task: You are to output the song’s information, indicating the title and the artist of a given song’s ID
 *
 * List of Parameters:
 * @param nSongID - song ID to search for in songs
 * @param songs - 1D array representing the collection of songs
 * @param artists - 1D array representing the collection of artists
 * @param numSongs - no. of songs in the collection, more specifically the no. of elements in the 1D array of songs
 * @param numArtists - no. of artists in the collection, more specifically the no. of elements in the 1D array of artists
 * 
 * Requirement/Restriction:
 * 1. No scanf() in this function. 
 * 2. Neither songs nor artists should be modified within this function
*/
void 
printSongInformation(int nSongID,
                     songList songs,
                     artistList artists,
                     int numSongs, int numArtists)
{
	// TODO: Display the song information
	// DO NOT modify the formatting of the printf statements
	printf ("%-30s","BLACK"); // Replace "BLACK" the proper parameter representing the title of the song with nSongID
	printf ("%s\n","PINK"); // Replace "PINK" with the proper parameter representing the proper artist name
}

/*
 * TO DO #2
 * Write the implementation for this function. (20 points)
 *
 * Task: This function will return the nSongID that has been played for the longest time.
 * You may assume that NO TWO SONGS will end up with the same playtime.
 *
 * List of Parameters:
 * @param list - 1D array representing the list of songs that have been played
 * @param songs - 1D array representing the list of songs
 * @param numPlayed - no. of entries in the played list information, specifically the no. of elements in list
 * @param numSongs - no. of songs in the collection, more specifically the no. of elements in the 1D array of songs
 * 
 * Requirement/Restriction:
 * 1. No printf() or scanf() in this function. 
 * 2. all given parameters should not be modified within this function
 * 3. This function should return the nSongID of the song entry within songList that has the highest total duration played
 */
int 
getMostPlayed(playList list,
              songList songs,
              int numPlayed,
              int numSongs)
{
	return -999; // Implement the function
}

/*
 * TO DO #3
 * Write the implementation for this function. (20 points)
 *
 * TasK: Given a favoriteSongID, identify the songs within the collection of songs where the
 * artists matches the artist indicated in the song with a songID that matches their favoriteSongID.
 * Print all these out
 *
 * @param favoriteSongID - songID to base the list of music recommendations off of
 * @param songs - 1D array representing the collection of songs
 * @param artists - 1D array representing the collection of artists
 * @param numSongs - no. of songs in the collection, more specifically the no. of elements in the 1D array of songs
 * @param numArtists - no. of artists in the collection, more specifically the no. of elements in the 1D array of artists
 * 
 * 
 * Requirement/Restriction:
 * 1. No scanf() in this function. 
 * 2. None of the parameters should be modified in this function
 * 3. You MAY call the function printSongInformation() that you just implemented. If you do not, make sure
 *    to follow the output format properly
 */
void 
recommendMusic(int favoriteSongID,
               songList songs,
               artistList artists,
               int numSongs,
               int numArtists)
{
	printHeader(); /* DO NOT REMOVE */
	/* TODO Implement the function and add songs. See the sample test*/

	printf ("%-30s","BLACK"); // DO NOT MODIFY THE FORMAT STRING. Replace "BLACK" with the proper title of the song with nSongID
	printf ("%s\n","PINK"); // DO NOT MODIFY THE FORMAT STRING. Replace "PINK" with the proper artist name
}

/* 

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/
