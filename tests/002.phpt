--TEST--
Create and output DayTime object, check exception
--SKIPIF--
<?php
if (!extension_loaded('daytime')) {
    echo 'skip';
}
?>
--FILE--
<?php
$obj = new DayTime("14:30");
echo $obj . PHP_EOL;
try {
    $obj->day(-0.5);
}
catch(Exception $ex) {
    echo "Caught " . $ex->getMessage() . PHP_EOL;
}
?>
--EXPECT--
14:30
Caught Value must be positive fraction