import uuid
import os
import platform
from pathlib import Path
from datetime import datetime
import argparse
NOW = datetime.now()
####################  Make Customizations  here#########################

## the the template files path whic you want to replicate everytime, an be global path or relative to cwd
template_path = "Templates/Template.cpp" 
## change to .java for java (or anything)
extension = ".cpp" 

## these keys will be added as command arguments and values will be directory name

## line having this string as a substring will be replaces by "time_signature"
timing_keyward = "Created"

## line having "timing_keyward" as a substring will be replaces by this signature
time_signature = " * Created: "+str(NOW.strftime("%Y-%m-%d %H:%M:%S"))+str("\n")

## Naming of the files
starting_from = int(65) #ASCII of 'A'
########################################################################################

slash = "/" if platform.system() == "Linux" else "\\"
time = NOW.strftime("%Y-%m-%d %H:%M:%S")
unique_id =  NOW.strftime("%Y-%m-%d-%H-%M-%S-%f")
today = NOW.strftime("%Y-%m-%d")

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


def run():
	print()
	lines = get_template(template_path)
	path = Path(str(unique_id))
	path.mkdir(parents=True, exist_ok=True)	

	existing = list(path.glob("*"+extension))
	
	for i in range(0, len(existing)):
		existing[i] = str(existing[i])

	count, replaced, files = int(0) , int(0), []

	for i in range(starting_from, starting_from+int(10)):
		filename = str(path /  str(chr(i) + extension))

		file1 = open(filename, 'w')
		file1.writelines(lines)
		file1.close()
		count += 1
		if filename in existing:
			files.append(filename)
			replaced += 1

	print(f"[ INFO ] {count} file" + str("s" if count > 1 else "") + f" created inside '{os.getcwd() + slash+ str(path)}'")

if __name__ == "__main__":
	run()