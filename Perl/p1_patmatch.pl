#! /usr/bin/env perl

# Create a text file and answer the following queries :
# 	a) Search for the pattern ‘apple’ in the file and display
#   the number of occurences.
# 	b) Count the number of words that ends with ‘e’
# 	c) Count the number of words that starts with ‘ap’
# 	d) Search for words containing ‘a’ or ‘s’
# 	e) Search for words containing zero or more occurrence of ‘e’
# 	f) Search for words containing one or more occurrence of ‘e’
# 	g) Search for words containing the letters ‘l’ and ‘m’, with 
# 	any number of characters in between.


use strict;
use warnings;
  
open my $file, "<", "data.txt" or die "Couldnt find file data.txt";  

my $apple = 0;
my $e = 0;
my $ap = 0;
my $as = 0;

while(<$file>) {
	my $line = $_;
	my @arr = split /\s+/, $line;
	for my $word (@arr) {
                $apple += () = $word =~ m\apple\gi;
		$e += () = $word =~ m\.*e$\gi;
		$ap += () = $word =~ m\^ap\gi;
	}
}

print "Number of occurences of apple: $apple\n";
print "Number of words that ends with e: $e\n";
print "Number of words that ends with ap: $ap\n";

seek $file, 0, 0;
print "\nWords with either a or s:\n";
while(<$file>) {
        my $line = $_;
        my @arr = split /\s+/, $line;
        for my $word (@arr) {
                if($word =~ m\.*[as].*\){
                        print "$&\n";
                }
        }
}

seek $file, 0, 0;
print "\nWords containing 0 or more e:\n";
while(<$file>) {
        my $line = $_;
        my @arr = split /\s+/, $line;
        for my $word (@arr) {
                if($word =~ m\.*e?.*\){
                        print "$&\n";
                }
        }
}

seek $file, 0, 0;
print "\nWords containing 1 or more e:\n";
while(<$file>) {
        my $line = $_;
        my @arr = split /\s+/, $line;
        for my $word (@arr) {
                if($word =~ m\.*e.*\){
                        print "$&\n";
                }
        }
}

seek $file, 0, 0;
print "\nWords with l & m and characters in between:\n";
while(<$file>) {
        my $line = $_;
        my @arr = split /\s+/, $line;
        for my $word (@arr) {
                if($word =~ m\.*l.*m.*\){
                        print "$&\n";
                }
        }
}
close($file);
