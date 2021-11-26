# php-daytime
PHP C-extension. Provides ability to store 24 hour time values as fraction 0.0 <= f < 1.0. 
Small extension provides a class and functions to manipulate, store and format time of day as double.

```php
class DayTime {
    // format flags
    const DAYT_SEC_AUTO = 0;
    const DAYT_SEC_INT = 1;
    const DAYT_SEC_DEC = 2;
    const DAYT_SEC_NONE = 3;
    
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
```
