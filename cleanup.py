from sys import argv
from os import listdir as ls, chdir as cd, path, remove

BAD = (
    ".out",
    ".exe",
    ".gch",
)

def deletable(directory):
    return (
    path.join(directory, item)
    for item in ls(directory)
    for bad in BAD
    if path.splitext(item)[1] == bad
    )    

def main():

    print(f"Cleaning up {argv[1]}...")
    for item in deletable(argv[1]): print(f"Removed item {item}..."); remove(item);
        
if __name__ == "__main__": 

    cd( path.dirname( path.realpath(__file__) ) )
    main()
