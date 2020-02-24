#! /bin/awk -f

# Write an awk script to find out total number of books sold in each discipline
# as well as total book sold based on the given table (stored in a data file)
# electrical 34
# mechanical 67
# electrical 80
# computers 43
# mechanical 65
# civil 198
# computers 64

{
    totalByDisc[$1] += $2
    total += $2
}

END{
    print "Dept: Total"
    print "----------"

    for(i in totalByDisc){
        print i ": " totalByDisc[i]
    }

    print "----------"
    print "Total: " total
}