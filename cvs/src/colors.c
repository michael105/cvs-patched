
#include "colors.h"

// colors for the different states
char* _statecolor[] = { "", YELLOW, LRED, CYAN, LBLUE,
				GREEN, LBLUE, MAGENTA, RED, BLUE, LGREEN, "", "","" }; // empty strings, in case
char* _nostatecolor[] = { "", "", "", "", "", 
				"","","","","","","","","" };																						 
char** statecolor = _statecolor;																

char* _normcolor = NORM;
char* _nonormcolor = "";
char* normcolor = NORM;


#if 0

 (the enum, defining the states)

    defines for Classify_File() to determine the current state of a file.
    These are also used as types in the data field for the list we make for
    Update_Logfile in commit, import, and add.

enum classify_type {
	T_UNKNOWN = 1,			/* no old-style analog existed	 */
	T_CONFLICT,				/* C (conflict) list		 */
	T_NEEDS_MERGE,			/* G (needs merging) list	 */
	T_MODIFIED,				/* M (needs checked in) list 	 */
	T_CHECKOUT,				/* O (needs checkout) list	 */
	T_ADDED,				/* A (added file) list		 */
	T_REMOVED,				/* R (removed file) list	 */
	T_REMOVE_ENTRY,			/* W (removed entry) list	 */
	T_UPTODATE,				/* File is up-to-date		 */
	T_PATCH,				/* P Like C, but can patch	 */
	T_TITLE				/* title for node type 		 */
};

#endif



void disablecolors(){
	normcolor = _nonormcolor;
	statecolor = _nostatecolor;
}
	
void enablecolors(){
	normcolor = _normcolor;
	statecolor = _statecolor;
}



