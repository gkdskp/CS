#! /bin/awk -f

# Write an awk script to compute gross salary of an employee accordingly to
# rule given below : If basic salary < 10000 then DA = 45% of the basic and 
# HRA =15% of basic If basic salary >= 10000 then DA =50% of the basic and 
# HRA =20% of basic.
#
# Input format:
# Employee1 BasicSalary

BEGIN{
    print "Employee\tGross Salary"
    print "---------------------"
}

{
    if($2 < 10000){
        totalAllowance = $2*(0.45) + $2*(0.15)
        print $1 "\t\t" totalAllowance+$2
    }

    else{
        totalAllowance = $2*(0.50) + $2*(0.20)
        print $1 "\t\t" totalAllowance+$2
    }    

}