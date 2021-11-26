<?php

/** @generate-function-entries */
class DayTime {


    public function __construct(string $t24);

    public function str(string $t24) : void {}
    public function day(float $t24) : void {}
    public function value() : float {}

    public function set(int $hours, int $mins, float $seconds) : void {}
    public function split(int &$h24, int &$min, float &$sec) : void {}
    public function format(int $flags = 0) : string {}
    
    public function __toString() : string {}

}

function daytime_set(int $hours, int $mins, float $seconds) : float {}
function daytime_str(string $t24) : float {}
function daytime_split(float $value, int &$h24, int &$min, float &$sec) : void {}
function daytime_format(float $value, int $flags = 0) : string {}
