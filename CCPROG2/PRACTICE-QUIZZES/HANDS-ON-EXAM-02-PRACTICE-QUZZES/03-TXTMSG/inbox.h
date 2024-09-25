/* 
    Data Structure for Hands-on #1, Problem #1. Text Messages 
	
    DO NOT change the contents of this header file.
*/

#define BLACK_BOX       (1)

#define MAX_INBOX_SIZE  25



typedef char string[256];

struct dateTag {
   int month, day, year;
};

struct msgTag {
   int sender;            // cel number of sender
   string msg;            // the actual text msg itself
   struct dateTag date;   // msg was received on this date
   int time;              // msg was received at this time 24hour format 1145 is 11:45AM  1800 is 6:00PM
   int read_flag;         // read_flag is 0 if the msg is not yet read (unread message)
                          // read_flag is 1 if the msg has been read 
};

struct inboxTag {
   int n_msgs;                         // number of messages
   struct msgTag Msg[MAX_INBOX_SIZE];  // array of messages, MAX_INBOX_SIZE is the maximum number of messages in the Inbox
  
   // NOTES: 
   // -  Message values (with data type of struct msgTag) are added/stored in the Msg[] array starting from index 0. 
   //    The 1st message is thus stored in Msg[0], the 2nd message in Msg[1], the 3rd message in Msg[2] and so on...
   // -  The n_msgs member indicates the number of messages stored in the Msg[] array.  For example, when the value of
   //    n_msgs is 3, it means that there are three messages which are stored in Msg[0], Msg[1] and Msg[2].
   // - The oldest message, in terms of date and time, in Msg[0].  The most recent message is stored in Msg[n_msgs - 1].   
};



