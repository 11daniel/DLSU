#include "LASTNAME-Music.c"

/*****
Instructions: DO NOT SUBMIT THIS FILE!!!

This is the main program used to test your submission.

Refer to the folder named EXPECTED OUTPUTS to check your solutions
for 4 available test cases provided to you.
****/


void initArtists(artistList artists,int *numArtists)
{
	FILE *pFile = fopen("artists.music","rt");
	string strLine;
	int nLine, i;
	
	fgets(strLine,sizeof(strLine),pFile);
	sscanf(strLine,"%d",&nLine);
	
	for (i = 0;i < nLine;i++)
	{
		fgets(strLine,sizeof(strLine),pFile);
		strLine[strlen(strLine)-1] = '\0';
		strcpy(artists[i].strArtistName,strLine);
		
		artists[i].nArtistID = i;
	}
	
	*numArtists = nLine;
	
	fclose(pFile);
}

void initSongs(songList songs,int *numSongs)
{
	FILE *pFile = fopen("songs.music","rt");
	string strLine;
	int a, b, songIndex, aID, numEntry, i;
	
	songIndex = 0;
	do
	{
		fgets(strLine,sizeof(strLine),pFile);
		sscanf(strLine,"%d%d",&a,&b);
		
		if (a != -1 && b != -1)
		{
			aID = a;
			numEntry = b;
			for (i = 0;i < numEntry;i++)
			{
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(songs[songIndex].strTitle,strLine);
				songs[songIndex].nSongID = songIndex;
				songs[songIndex].nArtistID = aID;
				songs[songIndex].nPlayDuration = 0;
				songIndex++;
			}
		}
	} while (a != -1 && b != -1);
	
	*numSongs = songIndex;
		
	fclose(pFile);
}

void initPlayLog(playList list,int *numPlayed,int testID)
{
	string fileName,strLine;
	FILE *pFile;
	int a,b,playIndex = 0;
	
	sprintf (fileName,"playLog%d.music",testID);
	pFile = fopen(fileName,"rt");
	
	do
	{
		fgets(strLine,sizeof(strLine),pFile);
		sscanf(strLine,"%d%d",&a,&b);
		
		if (a != -1 && b != -1)
		{
			list[playIndex].nSongID = a;
			list[playIndex].nDuration = b;
			playIndex++;
		}
	} while (a != -1 && b != -1);
	
	*numPlayed = playIndex;
	
	fclose(pFile);
}

int main()
{
	songList songs;
	artistList artists;
	playList list;
	
	int numSongs,numArtists,numPlayed;
	
	int nFavoriteID, i, testID;
		
	/* do NOT modify these lines. These are used to check your printSongInformation*/
	initArtists(artists,&numArtists);
	initSongs(songs,&numSongs);
	
	printf ("%d Songs loaded in the DB\n",numSongs);
	printf ("%-30s","Title");
	printf ("%s\n","Artist");
	printf ("-----------------------------------------------------\n");
	for (i = 0;i < numSongs;i++)
		printSongInformation(songs[i].nSongID,songs,artists,numSongs,numArtists);
	
	printf ("\n");
	
	/* Use this to check your getMostPlayed and recommendMusic functions */
	
	printf ("Enter test case no. 1-4: ");
	scanf ("%d",&testID);
	
	if (testID >= 1 && testID <= 4)
	{
		initPlayLog(list,&numPlayed,testID);
		
		
		nFavoriteID = getMostPlayed(list,songs,numPlayed,numSongs);
		
		printf ("\n\n");
		printf ("Most played song:\n");
		printf ("%-30s","Title");
		printf ("%s\n","Artist");
		printf ("-----------------------------------------------------\n");
		printSongInformation(nFavoriteID,songs,artists,numSongs,numArtists);
		
		recommendMusic(nFavoriteID,songs,artists,numSongs,numArtists);
	}
	else
		printf ("Invalid test case ID no. entered.\n");
		
	return 0;
}
