use strict;
use warnings;
#strict is forces us to use my keyword to determine scope of variable.
#Scalar Variable
my $x = "I am a string.";
$x = 5;
$x =5.8;

print "x is a scalar variable. $x\n";
#array
my @array = ("Ali" , 5 , 7.34);

print "My name is $array[0].\n";

print @array ,"\n";
foreach my $elem (@array){
    print $elem ,"\n";

}

#If you cast array variable into scalar variable it assign length of the array.
my $length = @array;
print "length is $length\n";

for(my $i =0;$i<$length; $i++ ){
    print "$array[$i] ";
}
print "\n";

#hashes are similar to dictionary they also called as associative array.

#my %grades = ("Ali",55,"Büşra",90,"Hasan",45)
my %grades = ("Ali" => 55,"Büşra" => 90,"Hasan" => 45);

print $grades{"Büşra"},"\n";

$grades{"Erdem"} = 65;
print $grades{"Erdem"},"\n";

my %GoT =("Lannister"=> ["Jamie","Cercei","Tyrion"],"Stark"=>["Ned","Arya","Brandon"]);

print $GoT{"Stark"} ,"\n";

print @{$GoT{"Stark"}},"\n";

print @{$GoT{"Stark"}}[0],"\n";

my $str1 = "Hello";
my $str2 = "World";
my $str3 = $str1 ." ". $str2;
print $str3,"\n";
my $str4 = "$str1 $str2"; #interpolation
print $str4,"\n";

my $mail = "hasanaliozkan\@posta.\$mu.edu.tr";#escape character is \
print $mail ,"\n";


