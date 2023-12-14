#include <stdio.h>
#include <stdlib.h>

struct playlistNode //Singly Linked List for Playlist
{
char song_name[10]; char artist_name[20]; long int duration;
struct playlistNode *next1;
}*start1 = NULL;//Starting address of playlistNode List


struct libraryNode //Singly Linked List for Music Library
{
char song_name[10]; char artist_name[20]; long int duration;
struct libraryNode *next2;
}*start2 = NULL;//Starting address of libraryNode List

void insert_end(char[], char[], long int); //Insertion into music library
void traverse_library(); //Traversal through music library
void search_by_title_in_library(); //To search in the music library using title
void insert_into_playlist(); //To insert a pre-existing song from music library into playlist
void traverse_playlist(); //Traversal through playlist
void show_duration_of_the_playlist(); //Calculating the total duration of playlist
void search_by_title_in_playlist(); //To search in the playlist using title
void swap_using_songname_in_a_playlist(); //Swapping positions of two songs in a playlist using their title
void shuffle(int); //To shuffle the playlist
void remove_a_song_from_the_playlist(int); //To remove a song from the playlist using it's Sr No.
void repeat_song(); //To play a song on loop

int main()
{
int choice, x = 1, choices, m = 1, position, q = 1, choice1,l=0; long int duration1;
char songname[10], artistname[20]; printf("\n");






printf("\n \t\t WELCOME TO MUSIC PLAYER \n");
printf("\n\n");

C: //Displaying choices for Main Menu

printf("\n\t\t\t** MAIN MENU **\n\tPRESS 1: Go to Music Library\n\tPRESS 2: Go to Playlist\n\tPRESS 3: Exit from App\n\n"); //Functions for the Main Menu

while(q)
{
printf("Enter the choice: "); scanf("%d", &choice1);

switch(choice1) //User choice for Main Menu
{
case 1:
{
goto A; break;
}

case 2:
{
goto B; break;
}

case 3:
{
printf("\n	\t\t THANK YOU	\n\n");
return 0; break;




}

default:
{
printf("\t\t\tInvalid Choice\n"); printf("\t\tPlease choose again\n\n\n");
goto C;
break;
}
}
}


A: //Displaying choice for Music Library
printf("\n\n\n\t\t\t*Menue for MUSIC LIBRARY*\n\tPress 1: Insert songs into the Main Library\n\tPress 2: Display all songs in Main Library\n\tPress 3: Search by Title\n\tPress 4: Insert song in Playlist\n\tPress 5: Enter to put song on Repeat\n\tPress 6: Go to the Playlist Menu\n\tPress 7: Return to Main Menu\n\n");

while(x)
{
printf("\nEnter choice: "); scanf("%d", &choice);

switch(choice) //User choice for Music Library
{
case 1:
{
l++;	// Counter to generate Sr No.
printf("Sr No.: ");
printf("%d\n",l);	//printing auto-generated Sr No.
printf("Song Name: ");
scanf("%s",&songname); printf("Artist Name: "); scanf("%s",&artistname); printf("Duration(in seconds): "); scanf("%ld",&duration1);
insert_end(songname, artistname, duration1); goto A;
break;
}

case 2:
{




traverse_library(); goto A;
break;
}

case 3:
{
search_by_title_in_library(); goto A;
break;
}

case 4:
{
insert_into_playlist(); goto A;
break;
}
case 5:
{
repeat_song(); goto A; break;
}

case 6:
{

B: //Displaying choice for Playlist
printf("\n\t\t\t**FOR PLAYLIST**\n");
printf("\n\n\n\t\t\t * Menue for PLAYLIST *\n\tPress 1: Insert a song into playlist\n\tPress 2: Display the playlist\n\tPress 3: Display total duration\n\tPress 4: Search by Title\n\tPress 5: Shuffle playlist\n\tPress 6: Swap\n\tPress 7: Delete a song from playlist\n\tPress 8: Return to Music Library\n\tPress 9: Return to Main Menu\n\n");
while(m)
{
printf("\nEnter choice: "); scanf("%d", &choices);

switch(choices) //User choices for Playlist
{
case 1:
{




insert_into_playlist(); goto B;
break;
}
case 2:
{
traverse_playlist(); goto B;
break;
}

case 3:
{
show_duration_of_the_playlist(); goto B;
break;
}

case 4:
{
search_by_title_in_playlist(); goto B;
break;
}

case 5:
{
shuffle(l); goto B; break;
}
case 6:
{
swap_using_songname_in_a_playlist(); goto B;
break;
}

case 7:
{
printf("Enter the Sr No. of the song to be delete:\n"); scanf("%d", &position); //Input Sr No. of song to be deleted
remove_a_song_from_the_playlist(position);
goto B;




break;
}

case 8:
{
goto A; break;
}

case 9:
{
goto C; break;
}

default:
{
printf("\t\tInvalid Choice\n"); printf("\t\tPlease choose again\n\n\n"); goto B;
break;
}
}
}
}

case 7:
{
goto C; break;
}

default:
{
printf("\t\tInvalid Choice.\n"); printf("\t\tPlease choose again\n\n\n"); goto A;
break;
}
}
}
}






void insert_end(char songname[], char artistname[], long int duration1)
{
struct libraryNode *newnode,*temp; //creating a newnode and temp pointer of the libraryNode list
newnode = (struct libraryNode*)malloc(sizeof(struct libraryNode)); //allocating a memory for newnode pointer of the libraryNode list
strcpy(newnode->song_name, songname); //copying the song name into newnode pointer
strcpy(newnode->artist_name, artistname);//copying the artist name into newnode pointer
newnode->duration = duration1;//assigning song duration into newnode pointer
newnode->next2 = NULL;

if(start2 == NULL) //to check if the libraryNode list is empty
    start2 = newnode; //storing the starting address

else
{
temp = start2;
while(temp->next2 != NULL) //loop will be executed till it reaches last node of the libraryNode list
{
temp = temp->next2; //the address of the next node will be assigned
}

temp->next2 = newnode; //the address of the newnode pointer will be assigned to the next temp pointer
}
printf("\nInsertion of Song Successful\n\n");
}


void traverse_library()
{
int f=0;
struct libraryNode*temp; //creating a temp pointer to traverse the libraryNode
temp = start2; //assigning the address of the start pointer of the libraryNode to thetemp pointer of the libraryNode

if(temp == NULL) //to check if the list is empty
{
printf("Library is empty.\n"); printf("Try again please\n\n\n");
}




else
{
printf("	Sr No. \t	Song Name\t	Artist Name\t	Duration(in seconds)\n");
while (temp!=NULL) //loop will execute till it reaches the last node of the libraryNode list
{
f++; //Counter for Sr No.
printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
temp = temp->next2; //assign the address of the next of current temp pointer to the current temp pointer
}
}
}

void search_by_title_in_library()
{
int c = 1,f=0; char n[20];
printf("Enter the Song Name to be searched: "); scanf("%s", &n); //Entering the song name to be searched
struct libraryNode*temp; //creating a temp pointer of the libraryNode list
temp = start2; //assigning the address of the start pointer of the libraryNode list to the temp pointer of the libraryNode list

if(start2 == NULL) //to check if the list is empty
{
printf("Library is empty.\n"); printf("Please try again \n\n");
}

else
{
printf("	Sr No. \t	Song Name\t	Artist Name\t Duration(in seconds)\n"); while(temp!= NULL)
{
c = strcmp(n, temp->song_name); //to compare the input song name with the search song name
if(c==0) //if both the song names are same
{
f++;





printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
break;
}
temp = temp->next2;
}

if(c!=0) //if song name not found
{
printf("	\n"); printf("Data not available.\n");
printf("Please try again \n\n");
}
}

}

void insert_into_playlist()
{
struct playlistNode*newnode, *temp1;
newnode = (struct playlistNode*)malloc(sizeof(struct playlistNode));
temp1 = start1; //assigning the address of the start1 pointer of the playlistNode list to the temp1 pointer of the playlistNode list
int c = 1, counter = 0; char n[20];
printf("Enter the song title to be added to the playlist: "); scanf("%s", &n); //Enter the song name to be added to the playlist

while(temp1!=NULL)
{
if(!strcmp(temp1->song_name, n)) //comparing the input song name with the song name of the current node
{
counter++; //incrementing the counter
}

temp1 = temp1->next1; //assigning the address of the next of current temp pointer to the current node pointer
}

if(counter == 0) //to check if the input song name is different than the song names in the playlistNode list
{
struct libraryNode*temp;




temp = start2;

if(start2 == NULL)
{
printf("Library is empty.\n"); printf("Please try again \n\n"); return;
}

else
{
printf(" Song Name\t	Artist Name\t Duration(in seconds)\n"); while(temp!= NULL)
{
c = strcmp(n, temp->song_name); //comparing the input song name with the song name of the current node
if(c==0) //if they both are the same
{
printf("\t%s\t\t %s\t\t%ld\n" ,temp->song_name, temp->artist_name, temp->duration);
break;
}
temp = temp->next2;
}


if(c!=0) //if they both are different
{
printf("Data not available.\n"); printf("Please try again \n\n"); return;
}
}

strcpy(newnode->song_name, temp->song_name); strcpy(newnode->artist_name, temp->artist_name); newnode->duration = temp->duration;
newnode->next1 = NULL;

if(start1 == NULL) start1 = newnode;

else
{




newnode->next1 = start1; start1 = newnode;
}
printf("\n Insertion of song successful\n\n");
}

else
{
printf("\nData is already in the playlist\n"); return;
}


}

void traverse_playlist()
{
struct playlistNode*temp;
temp = start1; //assigning the address of the start pointer of the playlistNode list to the temp pointer of the playlistNode list
int f=0;

if(temp == NULL)
{
printf("Playlist is empty.\n"); printf("Please try again \n\n");
}

else
{
printf("	Sr No. \t	Song Name\t	Artist Name\t	Duration(in seconds)\n"); while (temp!=NULL)
{
f++;
printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
temp = temp->next1;
}
}
}

void show_duration_of_the_playlist()
{
struct playlistNode *temp;




long int sum = 0, n;
temp = start1; if(temp == NULL)
{
printf("Playlist is empty.\n"); printf("Please try again \n\n");
}

else
{
while(temp!=NULL)
{
n = temp->duration; //assigning the duration of the current node to n
sum = sum + n; // adding the new duration of song to the pre-existing total duration
temp = temp->next1;
}
}

printf("\nPlaylist Duration(in seconds): %ld sec\n", sum); //printing the total duration of the playlistNode list
}

void search_by_title_in_playlist()
{
int c = 1,f=0; char n[20];
printf("Enter the song name to be searched: "); scanf("%s", &n);
struct playlistNode*temp; temp = start1;
if(start1 == NULL)
{
printf("Playlist is empty.\n"); printf("Please try again \n\n");
}

else
{
printf("	Sr No. \t	Song Name\t	Artist Name\t Duration(in seconds)\n"); while(temp!= NULL)
{




c = strcmp(n, temp->song_name); //comparing the input song name with the song name of the current node
if(c==0) //if they both are same
{
f++; //incrementing the counter
printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
break;
}
temp = temp->next1;
}

if(c!=0) //if song not found
{
printf("	\n"); printf("Data not available.\n");
printf("Please try again \n\n");
}
}

}

void swap_using_songname_in_a_playlist()
{
char n1[10], n2[10];

printf("\nBefore Swapping:\n\n");
traverse_playlist(); //printing the playlistNode list before swapping

struct playlistNode*temp1, *temp2, *temp3; //creating three temporary pointers: temp1, temp2 and temp3 of the playlistNode list
temp1 = start1;
temp2 = start1; //assigning the starting node address to temp1 and temp2
temp3 = (struct playlistNode*)malloc(sizeof(struct playlistNode)); //allocatingmemory for temp3 pointer of the playlistNode list

printf("Enter the song names to be swapped:\n"); scanf("%s %s", n1, n2);


if(temp1 == NULL) // to check if the playlistNode list is empty
{
printf("Playlist is empty.\n"); printf("Try again please\n\n\n");




}

else
{
while (temp1!=NULL) //loop will execute till temp1 pointer reaches the last node of the playlistNode list
{
if(!strcmp(temp1->song_name, n1)) //if both the song names are same
{
while (temp2!=NULL) //it will keep on executing till temp2 pointer reaches the last node of the playlistNode list
{
if(!strcmp(temp2->song_name, n2)) //if both the song names are same
{
strcpy(temp3->song_name, temp2->song_name); // swapping the information of the two selected nodes
strcpy(temp3->artist_name, temp2->artist_name); temp3->duration = temp2->duration;

strcpy(temp2->song_name, temp1->song_name); strcpy(temp2->artist_name, temp1->artist_name); temp2->duration = temp1->duration;

strcpy(temp1->song_name, temp3->song_name); strcpy(temp1->artist_name, temp3->artist_name); temp1->duration = temp3->duration;

}

temp2 = temp2->next1;
}
}

temp1 = temp1->next1;
}
}

printf("\n\nAfter Swapping:\n\n");
traverse_playlist(); //traversing the playlistNode list after swapping
}

void remove_a_song_from_the_playlist(int position)
{





struct playlistNode *temp1, *temp2; //creating temp1 and temp2 pointers for the playlistNode list
int i;
temp1 = start1;
temp2 = start1; //asssigning the address of the starting node to temp1 and temp2 pointers of the playlistNode list
if(start1 == NULL) //to check if the playlistNode list is empty
{
printf("Playlist is empty.\n"); printf("Please try again \n\n");
}
else
{
for(i = 1; i<position - 1; i++) //to find the position entered by the user
{
temp1 = temp1->next1; temp2 = temp2->next1;
}

temp2 = temp2->next1;
temp1->next1 = temp2->next1;
free(temp2); //deleting the node from the playlistNode list
}
printf("\nDeletion successful\n"); printf("New playlist\n");
traverse_playlist(); //traversing the playlistNode list after deletion

}

void repeat_song()
{
int c = 1,i =1,k=1,f=0; char n[20];
printf("Enter the song name to put on loop: "); scanf("%s", &n);
printf("Number of times you want to loop a song : "); scanf("%d",&k);
struct libraryNode*temp; temp = start2;
if(start2 == NULL) //to check if the libraryNode list is empty
{
printf("Library is empty.\n"); printf("Please try again \n\n");
}




else
{
printf("	Loop No. \t	Song Name\t	Artist Name\t Duration(in seconds)\n"); while(temp!= NULL) //it will keep on executing till it reaches the last node of the libraryNode list
{
c = strcmp(n, temp->song_name); //comparing the input song name with the song name of the current node
if(c==0) //if both the song name are same
{
for(i=1;i<=k;i++) //loop will run for as many times the user has entered
{
f++; //incrementing the counter for loop No.
printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
}
break;
}
temp = temp->next2;
}

if(c!=0) //if song not found
{
printf("	\n"); printf("Data not available.\n");
printf("Please try again \n\n");
}
}
}




void shuffle (int l)
{
int c = 1,a=0,n,j=0,ch,i; struct playlistNode*temp; temp = start1;
srand(time(0)); //to generate random numbers every time the code is run
if(temp == NULL) //to check if the playlistNode list is empty
{
printf("playlist is empty.\n");
printf("Try again please\n\n\n");
}
else
{
printf("Song Name \t Artist Name\t	Duration(in seconds)\n"); for (c = 1; c <=10; c++) //to shuffle 10 times
{
ch = rand() % l+ 1; //generates random number temp = start1;
j=0;
while(temp!= NULL)
{
j++; //incrementing the counter
if(j==ch) //if random generated number matches the counter variable
{
printf("%s\t\t %s\t\t%ld\n" , temp->song_name, temp->artist_name, temp->duration);
break;
}
temp = temp->next1;
}

}
}
}
