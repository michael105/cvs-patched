#ifndef cvs_colors_h
#define cvs_colors_h

#define NORM "\033[0;38;40m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BROWN "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define MARINE "\033[0;36m"
#define CYAN "\033[0;36m"
#define LGREY "\033[0;37m"
#define WHITE "\033[0;38m"

#define GREY "\033[1;30m" 
#define LRED "\033[1;31m" 
#define LGREEN "\033[1;32m" 
#define YELLOW "\033[1;33m"
#define LBLUE "\033[1;34m"
#define LMAGENTA "\033[1;35m"
#define LMARINE "\033[1;36m"
#define LCYAN "\033[1;36m"
#define LWHITE "\033[1;37m"

extern char** statecolor;
extern char* normcolor;
extern char** _colors;

#define COLORVARS norm,smalldash,doubledash,commitfilename,deletefilename,difffilename,logfilename


const char* _getcolor(int number);
const char* _getstatecolor(int number);

#define COLOR(color) ({ enum { COLORVARS }; _getcolor(color); })

#define STATECOLOR(color) ({ _getstatecolor(color); })

// this expands to the string "", if nocolor is active
#define NORMCOLOR normcolor

void disablecolors();
	
void enablecolors();


	
#endif
