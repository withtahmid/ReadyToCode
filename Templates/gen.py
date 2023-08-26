"""
	Author: withtahmid
		
	Motivation: 
		Before contest time this is a very repetitive process 
		to copy the coding template and create different files 
		into the right directory by hand every time. This python
		the script is written to save time just before any contest starts
		by creating ready-to-write template codes in the appropriate 
		folder with the correct naming.
			
	Works on both Windows and Linux filesystems. Works for any programing language
		
	Workflow: 
	 		From user-provided parameters, it will determine various contest
	 		platform by the chosen argument and creates a folder accordingly. 
	 		by the argument's value, it creates a directory inside the platform.
	 		From the provided template path, it copies a template file 
	 		and generates ready-to-write code files inside the correct directory. 

	Commands: 'gen.py' is the name of the script here
		 python gen.py --cf 850 --n 2
		 python gen.py --cf 850 --n 2 --type 2
		 python gen.py --at 250 --n 3 --type b --mark anything
	
	Output:
		[ INFO ] 2 files created inside '(curent working directory)/Codeforces/2023-04-06_850'
		[ INFO ] 2 files created inside '(curent working directory)/Codeforces/2023-04-06_[Div-2]_850'
		[ INFO ] 3 files created inside '(curent working directory)/Atcoder/2023-04-06_[Beginner]_250_(anything)'
	
	Created Directories:
		/Codeforces/2023-04-06_850
		/Codeforces/2023-04-06_[Div-2]_850
		/Atcoder/2023-04-06_[Beginner]_250_(anything)

	Explanation:
		From the platform argument, it decides the platform, here --cf for Codeforces
		and --at for Atcoder. Currently added:
			--cf -> Codeforces
			--at -> Atcoder
			--vj -> Vjudge
			--rn -> Random
			--ps -> NSUPS
		This argument and directory names are Fully customizable. (Look for 'folders' dictionary)
		Creates the directory Codeforces in cwd if not exist. 
		It detects folder and file conflicts and asks for permission to overwrite
		the existing file or directory while creating or deleting a file.

		Then the value of the argument refers to the contest name or round number. Here 850 is 
		shown for the first example. So we need to create another directory inside the platform
		directory to keep everything organized. The naming of this directory follows:
			currentDate_[type]_contestName__(mark)
		--type, optional argument taken for the type or difficulty of the contest (look for 'types' dictionary)
		--mark, optional argument adds any additional information about the contest
		these additional arguments are also customizable (look for 'additional' list)

		--n mandatory argument determines how many files are to be created inside the target directory.
		starts from customizable ASCII and increases by one. example A.cpp, B.cpp, C.cpp
		

	Syntax:			
		only one platform parameter should be passed at once (or --clear, described below), will throw an error
		otherwise saying multiple platforms are chosen or zero if not chosen.
		type, mark and n is optional but not calling n will be same as callig with 1

	Shortcut:
		 python gen.py --cf "" 
			
			without taking an exact round name, it will create a folder by current data into 
			the appropriate folder to save more time an dcreate a file, look for 'default_directories' to add 
			any string to work as an auto. 

	Random:
		 python gen.py --rn "dont_care"
			this command will instantly create a file inside Random Folder and will create 
			a template file with the current date and time, no need to think of a random filename,
			all will be sorted automatically
		
	Trash:
		While coding time, inside all folders, binary files are generated which are not
		supposed to be stored in GitHub or locally, --clear "extension" (.exe for example) 
		will list all the candidate files that match the extension or don't have any extension
		to be moved into the trash directory in cwd. all in one place, to look at and delete by hand 
		to prevent accidental loss.
		Command as follows:

		Command:
			python gen.py --clear .exe
	        
		        (current working directory)/Codeforces/810/B.exe
		        (current working directory)/Codeforces/810/C.exe
		        (current working directory)/Codeforces/810/D.exe
			[ INFO ] Listed 3 files above to delete.
			[ NOTE ] Files won't be deleted permanently. Will be moved into Trash
			Do you want to continue? [Y/n] y
			Trash location-> (current working directory)/Trash

"""

import uuid
import os
import platform
from pathlib import Path
from datetime import datetime
import argparse
NOW = datetime.now()
####################  Make Customizations  here#########################

## the the template files path whic you want to replicate everytime, an be global path or relative to cwd
template_path = "Template.cpp" 
## change to .java for java (or anything)
extension = ".cpp" 

## these keys will be added as command arguments and values will be directory name
folders = {
	"cf": "Codeforces",
	"at":"Atcoder", 
	"vj":"Vjudge",
	"rn":"Random", 
	"ps":"NSUPS"
  }
types = {
	"cf": {"1":"Div-1", "2": "Div-2", "3":"Div-3", "4": "Div-4"},
	"at": {"b": "Beginner", "r": "Regular"},
	"ps": {"i": "Individual", "t":"Team", "d": "Discussion"}
}
purposes = {
	"clear":"clear"
}

additional = ["type", "mark"]

## line having this string as a substring will be replaces by "time_signature"
timing_keyward = "Created"

## line having "timing_keyward" as a substring will be replaces by this signature
time_signature = " * Created: "+str(NOW.strftime("%Y-%m-%d %H:%M:%S"))+str("\n")

##b these strings a platform argument will be refer to current date
default_directories = ["auto", "today", "Auto", "Today", ""]

# will ask to proceed further by asking this 
warning_text = "Do you want to continue? [Y/n] "

## writing these will be considered as yes
agree = ["Y", "y", "YES", "yes", "Yes"]

## to find language name by extension
language = {".cpp": "C++", ".java":"Java", ".py":"Python"}

## Naming of the files
starting_from = int(65) #ASCII of 'A'
########################################################################################

slash = "/" if platform.system() == "Linux" else "\\"
time = NOW.strftime("%Y-%m-%d %H:%M:%S")
unique_id =  NOW.strftime("%Y-%m-%d-%H-%M-%S-%f")
today = NOW.strftime("%Y-%m-%d")
parser = argparse.ArgumentParser(description="File creation")
##platforms arguments
for i in list(folders) + list(purposes) + additional:
	parser.add_argument(str("--")+i, type = str, help = "", default = None)
#static argumen
parser.add_argument("--n", type = int, help ="", default= 1)
args = parser.parse_args()

def list_executables(dirpath:str, filenames:list, ext:str) -> list:
	delete_list = []
	for filename in filenames:
		if '.' not in filename :
			delete_list.append(str(dirpath + slash + filename))
	if ext != "" and ext != None:
		for filename in filenames:
			if filename.endswith(ext):
				delete_list.append(str(dirpath + slash + filename))
	return delete_list

def clear(path:str, ext:str):
	trash_path = Path(path+ slash+ "Trash")
	delete_list = []
	for dirpath, dirnames, filenames in os.walk(path):
		if dirpath == str(trash_path) or dirpath == path:
			continue
		delete_list = delete_list + list_executables(dirpath, filenames, ext)
	
	if len(delete_list) == 0:
		print(f"No file found to delete")
		return

	for i in delete_list:
		print("\t"+i)
	
	print(f"[ INFO ] Listed {len(delete_list)} file"+str("s" if len(delete_list)> 1 else "")+" above to delete.")
	print(f"[ NOTE ] Files wont be deleted parmanently. Will be moved into Trash")
	
	if input(warning_text) not in agree:
		print(f"[ MESSAGE ] Program terminated")
		return
	if not trash_path.is_dir():
		trash_path.mkdir(parents=True, exist_ok=True)

	for src_file in delete_list:
		spl = src_file.split(slash)
		file = trash_path / (str(today) +"_"+  str(spl[len(spl)-1]) + str("_" + str(uuid.uuid1())))
		Path(src_file).rename(Path(file))
	print(f"Trash location-> {trash_path}")

def get_template(template_path):

	assert template_path.endswith(extension), f"Expeting {language[extension]} file as template"
	try:
		temp = open(template_path, "r")

	except:
		assert True, f"[ ERROR ] Couldn't open template file"
	lines = temp.readlines()
	for i in range(0, len(lines)):
		if timing_keyward != None and  timing_keyward in lines[i]:
			lines[i] = time_signature
	temp.close()
	return lines


def get_type(level:str, platform:str):
	level = level.lower()
	assert level[0] in types[platform], f"[ ERROR ] Wrong type is choosen for {platform}\nTry with-> {types[platform]}"
	return f"[{types[platform][level[0]]}]"

def run():
	print()
	platforms = [i for i in list(folders)+list(purposes)]
	platform =  [i for i in platforms if args.__dict__[i] != None]

	assert len(platform) == 1, f"[ ERROR ] " + ("Multiple platforms are" if len(platform) > 1 else "No platform is") +"  choosen"

	platform = str(platform[0])

	if platform == "clear":
		clear(os.getcwd(), args.__dict__[platform])
		return
	add = ""
	div = ""
	for i in additional:
		if args.__dict__[i] != None:
			if i == "type":
				div = "_"+ get_type(args.__dict__[i], platform)
				continue
			add = add + args.__dict__[i]
	dir_name = "" if args.__dict__[platform] in default_directories else "_"+ args.__dict__[platform]

	path = Path(
			str(folders[platform]) 
			+ ((str(slash) 
			+ str(
				str(today)
				+ str(div) 
				+ dir_name
				+ str(f"_({add})" if len(add)>0 else "")
				+ slash) if platform != "rn" else "")
			)
		)
	if args.n > 10:
		print(f"[ WARNING ] Number of files to generate: '{args.n}' is too much!!!")
		if input(warning_text) not in agree:
			print(f"[ MESSAGE ] Program terminated")
			return

	if path.is_dir() and platform != "rn":
		print(f"[ CONFLICT ] Path exists -> '{os.getcwd()+slash+str(path)}'")
		existing = list(path.glob(str("*"+extension)))
		print(f"[ WARNING ] Existing directory contains {len(existing)} {language[extension]} files!!")
		if input(warning_text) not in agree:
			print(f"[ MESSAGE ] Program terminated")
			return
	
	

	lines = get_template(template_path)
	
	path.mkdir(parents=True, exist_ok=True)	

	existing = list(path.glob("*"+extension))
	
	for i in range(0, len(existing)):
		existing[i] = str(existing[i])

	count, replaced, files = int(0) , int(0), []
	for i in range(starting_from, starting_from+int(args.n)):
		filename = str(path /  str(
			(str(unique_id + "_") if platform == "rn" else str(""))
			+ chr(i)+extension))

		file1 = open(filename, 'w')
		file1.writelines(lines)
		file1.close()
		count += 1
		if filename in existing:
			files.append(filename)
			replaced += 1

	print(f"[ INFO ] {count} file" + str("s" if count > 1 else "") + f" created inside '{os.getcwd() + slash+ str(path)}'")
	if(replaced>0):
		print(f"[ NOTE ] Overriting on existing directory replaced following {len(files)} file"+str("s" if replaced>1 else "")+":")
		for i in files:
			print(f"\t{i}")

if __name__ == "__main__":
	run()