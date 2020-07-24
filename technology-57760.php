<?php
$date = readline();
$m = ($date[5].$date[6]) + 0;
$d = ($date[8].$date[9]) + 0;
$days = $d;
$array = array(
    1    => 0,
    2    => 31,
    3    => 31,
    4    => 31,
    5    => 31,
    6    => 31,
    7    => 31,
    8    => 30,
    9    => 30,
    10    => 30,
    11    => 30,
    12    => 30,
);
for ($i = 1; $i <= $m; $i++) {
    $days += $array[$i];
}
$days = 365 - $days + 1;
echo $days;
?>