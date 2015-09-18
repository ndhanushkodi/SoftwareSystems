/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
// char pattern[] is the regex pattern
void find_track_regex(char pattern[])
{
    regex_t regex; //argument for regcomp and regexec
   
    int comp;
    char buffer[100]; //for regerror
    int i;

    comp = regcomp(&regex, pattern, 0); //0 is the flag
    if(comp != 0)
    {
        regerror(comp, &regex, buffer, 100);
        fprintf(stderr, "Could not compile regex\n");
        exit(1); //never goes to the loop
    }

            
    for(i=0;i<NUM_TRACKS;i++){ //loop through the tracks
        int out = regexec(&regex, tracks[i],(size_t) 0, NULL, 0);
        //check the regex 
        if(out == 0){
            //if it matches, print
            printf("Track %i: '%s'\n", i, tracks[i]);
        }

    }
   
    regfree(&regex);
    
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
