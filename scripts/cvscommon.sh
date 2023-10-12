

# configuration and common functions of the patchwork scripts

# set $1 to S2, if S1 is not defined in the env
function defaultenv(){
	#local var=$1
	#shift
	#eval test -z $"$var" && \
	#	export $var="$*"
	printenv $"$1" > /dev/null
	if [ "$?" != "0" ]; then
		local var=$1
		shift
		export $var="$*"
	fi
}

function setenv(){
	defaultenv $*
}



function error(){
	echo -en "$RED" 
	echo $*
	echo -en $N
	exit 1
}

# Try EDITOR, if this doesn't work, try to find a text editor, and set $EDITOR
function find_editor(){
	$EDITOR --version 2> /dev/null > /dev/null
	if [ "$?" == "0" ]; then
		return
	fi
	echo '$EDITOR not set or missing'
	local i
	for i in $EDITORx pico nano joe vim; do
		echo try $i
		$i --version 2> /dev/null > /dev/null
		if [ "$?" == "0" ]; then
			export EDITOR=$i
				echo using $EDITOR
			return
		fi
	done
}

# open $EDITOR, or try to find a text editor to edit the files 
function edit(){
	find_editor
	$EDITOR $1
}


#CFGFILE=".cvs/config.sh"
defaultenv CVSPROJECTCFG ".cvs_patched.cfg"

function loadcfg(){
	local CPWD=$PWD
	until [ -f "$CVSPROJECTCFG" ]; do 
		chdir ..
		if [ "$PWD" = "/" ]; then
			error "No cvs-patched project found"
		fi
	done
	if [ ! -f "$CVSPROJECTCFG" ]; then
		error "No cvs-patched project found"
	fi
	
	source $CVSPROJECTCFG #|| error "Error in the configfile $CVSPROJECTCFG"
	export CVSPROJECTROOT="$PWD"
	chdir "$CPWD" || error "Couldn't change directory back"
}

if [ -z "$CVSNOCFG" ]; then
	loadcfg
else
	# set environment variables to defaults, if not present
	defaultenv CVSROOT $HOME/CVSROOT
	defaultenv CVSDIRNAME .cvs
fi


N="\033[0;37;40m"
BLACK="\033[0;30m"
GRAY="\033[0;1;30m"
GREY="\033[0;1;30m"
LGREEN="\033[0;1;32m"
GREEN="\033[0;32m"
LRED="\033[0;1;31m"
RED="\033[0;31m"
YELLOW="\033[0;1;33m"
BROWN="\033[0;33m"
LBLUE="\033[0;1;34m"
BLUE="\033[0;34m"
NORM="\033[0;37;40m"
PINK="\033[0;1;35m"
MAGENTA="\033[0;35m"
LMAGENTA="\033[0;1;35m"
CYAN="\033[0;36m"
LCYAN="\033[0;1;36m"
WHITE="\033[0;1;37m"
LGRAY="\033[0;37m"
LGREY="\033[0;37m"
#(first color, then attributes)
CURSIVE="\033[3m"
UNDERLINE="\033[4m"
FAINT="\033[2m"
BOLD="\033[1m"
BLINK="\033[5m"
BLINK2="\033[6m"
INVERSE="\033[7m"



function abortyesno(){
	echo -e "$1 (y/n)"
	if [ "$CONFIRM" = "N" ]; then
		echo y
		return
	fi
	read k
	if [ "$k" != "y" ]; then
		echo Abort
		exit
	fi
}


function verbose(){
	if test -z $opt_quiet; then
		echo -en "$LCYAN" 
		echo $*
		echo -en $N
	fi
}

function v(){
	verbose $*
}


function echov(){
	if test -z $opt_quiet; then
		echo $*
	fi
}


function run(){
	if test -z "$opt_quiet"; then
		echo -en "$BLUE"
		echo $*
		echo -en "$N"
	fi
	if [ "$CONFIRM" = "Y" ]; then
		abortyesno "Continue?"
	fi
	eval "$*"
}

function runC(){
	echo $*
	if [ "$CONFIRM" = "Y" ]; then
		abortyesno "Continue?"
	fi
	eval "$*"
}



opt_quiet=""

# parse global options
oloop=1
while [ -n "$1" ] && [ -n "$oloop" ];do
	case $1 in 
		--quiet) opt_quiet=1;;
		--yes)CONFIRM="N";;
		-H)cvshelp;exit;;
		--help)cvshelp;exit;;
		*) oloop="";;
	esac
	if [ -n "$oloop" ]; then
		shift
	fi
done



