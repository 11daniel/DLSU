/* 
    DO NOT CHANGE THIS FILE!

    This file will load data from the BIN_FILE into the Inbox data structure.

    YOU DO NOT NEED TO UNDERSTAND THE CODES IN THIS FILE. 
	
*/

#define BIN_FILE "txtmsgs.bin"

void
Load_Data(struct inboxTag Inbox[])
{
	FILE *fp;
	
	fp = fopen(BIN_FILE, "rb");
	
	if (fp != NULL) {
		fread(Inbox, sizeof(struct inboxTag), 2, fp);  // 2 means there are two inboxes
		fclose(fp);
	} 
	else {
		fprintf(stderr, "ERROR: %s file not found, program terminating... INFORM YOUR TEACHER ABOUT THIS!!!", BIN_FILE);
		exit(1);
	}
}


