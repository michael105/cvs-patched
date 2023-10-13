
#include "colors.h"
#include "cvs.h"
#include <stdlib.h>

// colors for the different states
char* _statecolor[] = { "", // the classify enum starts with 1, the array with "0"..
	RED, LRED, LMAGENTA, LCYAN,
	LGREEN, LBLUE, MAGENTA, RED, 
	GREEN, YELLOW, BROWN, "","" }; // empty strings, in case

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


char** statecolor = _statecolor;																
char* _nocolor = "";
 
//#define COLORVARS norm,smalldash,doubledash,commitfilename,deletefilename,difffilename
char* __colors[] = { NORM, LGREEN, BLUE, LGREEN, RED, YELLOW, LGREEN };
char** _colors = __colors;


const char* _getcolor(int number){
	if ( nocolor )
		return( _nocolor );
	return( _colors[number] );
}

const char* _getstatecolor(int number){
	if ( nocolor )
		return( _nocolor );
	return( _statecolor[number] );
}


#define DEFCOLOR(var,color) char* _##var = color; char* var = color
DEFCOLOR( normcolor, NORM );


void disablecolors(){
	if ( nocolor )
		return;

	nocolor = 1;
	normcolor = _nocolor;

	// i know. but this is the quickest way, to make the setting globally
	// available, also to sub processes.
	setenv("CVSNOCOLOR","1",1);

	statecolor = malloc( sizeof( _statecolor ) );
	for ( int i=0; i<sizeof(_statecolor)/sizeof(char*); i++ )
		statecolor[i] = _nocolor;
}
	
void enablecolors(){
	if ( !nocolor )
		return;
	nocolor = 0;

	unsetenv("CVSNOCOLOR");
	if ( normcolor == _nocolor )
		free(statecolor);
	normcolor = _normcolor;
	statecolor = _statecolor;
}



