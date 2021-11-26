--TEST--
Daytime object options
--SKIPIF--
<?php
if (!extension_loaded('daytime')) {
    echo 'skip';
}
?>
--FILE--
<?php
$obj = new DayTime("16:42:42.42");
echo $obj . PHP_EOL;
$obj->day(0.5);
echo $obj . PHP_EOL;
$obj->str("15:01:00.000001");
echo $obj . PHP_EOL;
$hours = 0;
$mins = 0;
$secs = 0.0;
$obj->split($hours,$mins,$secs);
echo sprintf("%02d:%02d:%8.6f",$hours,$mins,$secs) . PHP_EOL;

echo $obj->format(DayTime::DAYT_SEC_AUTO). PHP_EOL;;
echo $obj->format(DayTime::DAYT_SEC_INT). PHP_EOL;;
echo $obj->format(DayTime::DAYT_SEC_DEC). PHP_EOL;;
echo $obj->format(DayTime::DAYT_SEC_NONE). PHP_EOL;;

?>
--EXPECT--
16:42:42.420000
12:00
15:01:0.000001
15:01:0.000001
15:01:0.000001
15:01:00
15:01:0.000001
15:01
