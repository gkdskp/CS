#! /bin/awk -f

# Write an awk script to delete duplicated line from a text file. The 
# order of the original lines must remain unchanged

{
    if(!found[$0]){
        found[$0]++
        print $0
    }
}