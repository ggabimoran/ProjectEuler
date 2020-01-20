#!/usr/bin/php
<?php
$time_start = microtime(true);
function euler48($max){
$N=(int)(log($max/(1+2/sqrt(5)))/log(2+sqrt(5)));
$r_1 = 2 + sqrt(5);
$r_2 = 2 - sqrt(5);
$sum = (1+2/sqrt(5))*(1-pow($r_1,$N+1))/(1-$r_1)+(1-2/sqrt(5))*(1-pow($r_2,$N+1))/(1-$r_2);
return $sum;
}
echo euler48(4000000) . "\n";
$time_end = microtime(true);
$execution_time = ($time_end - $time_start);
echo "Execution time : " . "$execution_time seconds \n";
?>