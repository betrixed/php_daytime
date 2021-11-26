--TEST--
Check if daytime extension is loaded, call functions
--SKIPIF--
<?php
if (!extension_loaded('daytime')) {
    echo 'skip';
}
?>
--FILE--
<?php

$s = "12:35:26.151502";

$value = daytime_str($s);
echo "float value = " . $value . PHP_EOL;
echo "time value = " . daytime_format($value,0) . PHP_EOL;

$hours = 0;
$mins = 0;
$secs = 0.0;

daytime_split($value,$hours,$mins,$secs);
echo "split = " . $hours . ":" . $mins . ":" . number_format($secs,6) . PHP_EOL;

$value = daytime_set(18,53,12.5);
echo "val = " . daytime_format($value,0) . PHP_EOL;

?>
--EXPECT--
float value = 0.52460823497685
time value = 12:35:26.151502
split = 12:35:26.151502
val = 18:53:12.500000