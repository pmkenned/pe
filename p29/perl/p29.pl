#!/usr/bin/perl

use strict;
use warnings;

my %hash;

foreach my $a (2..100) {
	foreach my $b (2..100) {
		my $x = $a**$b;
		print $x, " ";
		if(!exists $hash{$x}) {
			$hash{$x} = 1;
		}
	}
}

my $hash_count = keys %hash;
print $hash_count;
