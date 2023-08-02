
#### cvs-patched


Currently this is a backup of some work. 

Should be usable, I use it myself, but there could be changes.

Ehm, there should be changes as well. E.g., diff is the old version of some time ago.
This started with another problem with git, I tried svn, then cvs, and realized -
the repository is readable. And editable. So I started with some modifications.

Since I tend to forget the different commands, I added the help texts.

The code isn't the cleanest, but, to be honest, it's the same with cvs itself.
However, it works. So. 


-----

A patched version of cvs, including several patchwork scripts.

The intention is to have a intuitive framework for a mature source control system,
which doesn't need to be configured, has complicated options,
or will make you shoot into your feet. 
Just a (local) backup and history of the work.

cvs has got the advantage to have a repository, consisting of plain text files.
It's possible to change the last log message with a text editor, for example.
While testing, I accidentally removed the central .cvs directory.
Writing its contents again with a texteditor was done within minutes.

Further, cvs is a mature source control systems.

And it is possible with the supplied scripts to have a source control system 
running within seconds.

Using it in parallel with git or svn is possible as well.
Have cvs for the backup of all modifications, and use git 
to push the work online, for example.

I didn't modify the logic of cvs itself, or did graving changes to the source code;
tried to do the modifications without changing the running system.
I don't advertise this as a replacement for git or svn.


-----

start a project with cvs-patched


cvsnew testproject [FILE FILE2 ...]

	create a new project 'testproject' in the current directory,
	which doesn't need to be empty.
	Initialize a repository, if not present,
	default location: $HOME/CVSROOT/testproject
	Create the project directory, named per default ($CVSDIRNAME) '.cvs'
	
	Add and commit optionally supplied files and directories.


cvsadd DIR/FILE ... 
   
	Add files and directories to the project,
	commit them into the repository.
	
	If files are within a subdirectory, the directory hierarchy
	is added recursively after confirmation.


cvsam [log message]
	
	Commit all modifications of versioned files into the repository,
	with a optional log message.
	

cvst 

	Show the status of modified (or all, -a) files
	within the project.


All functions of cvs are available, having a log, diffs to older revisions, etc.
The documentation of cvs is quite straightforward (link)

'cvs log FILE', 'cvs diff -r 1.3 FILE',..

-----

cvshelp 

   info about the scripts


-----

To build and install type 'make', and 'make install'.

Per default server and client support of cvs is disabled.

To change that, either cd into cvs and run configure yourself,
or edit the makefile.


-----


### Changes


##### New


The wrappers in 'scripts'.

	Written in shell script.

	The intention is to don't need to lookup the documentation for cvs,
	when doing the most common actions.

	Namely, creating a new project (including the setup of the local repository),
	adding files, commit changes, moving files (without loosing the history).


Some colors in the output

Scriptable output for 'ls' and 'status'

Compatibility with uClibc and musl.




environment variables


CVSDIRNAME	

   The directory, cvs stores its information within projects. (default '.cvs')
   Consequently it is possible to have overlappping projects, by changing 'CVSDIRNAME'.


CVSORIGIN   

	If set, cvs-patched has the default behaviour of the unchanged cvs. 
   The output is unchanged, CVSDIRNAME defaults to 'CVS', colors disabled.
	All new options still work.


CVSNOCOLOR

   Disable all colors


#### Modifications


Permanent ignore patterns: '.svn', '.git'


##### New options:


global option

	-C Don't colorize the output

	-O original output of cvs.
		There might be lots of script around.
		This uses an unchanged output, what might be neccessary for other tools.


cvs ls

	-f Show full path, relative to the current directory

	-w like -f, and display the name of the repository file 
	
	-F Show full path, list only files

	-p Show full path, list only directories


cvs status

   -m List only locally modified files

   -Q Print only filename and status.

   -q short format


cvs log

	-q brief output



-----

About git - it is a great system.
However, it's obviously written with the linux kernel development in mind.
So it doesn't suit my needs to simply backup the history of my changes,
without having to look at the net for a solution of a detached head, 
or whatever.

Thanks, git, for several interesting experiences...
I know it's me - but I couldn't know, since I didn't study the manual,
this or that would destroy the work of, well, erased my. Nevermind.

As well it's possible to have git and cvs running in parallel,
using cvs for the local backup of modifications.

Anyways, git or svn are the better tools for distributed cooperation,
or larger projects.
For local projects, I do prefer something prooved and simple, 
where I'm able to modify in question the repository files themselves with a text editor,
copy the whole repository around, and I get through the docs
within short time.

---

miSc, 2023, github.com/michael105



