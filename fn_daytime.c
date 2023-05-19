/**
 * 
 * to be inline included by php_daytime.c
 */

ZEND_FUNCTION(daytime_format) 
{
	long 	flags = 0;
	double  value;
	zend_string *result;

	ZEND_PARSE_PARAMETERS_START(1, 2)
	Z_PARAM_DOUBLE(value)
	Z_PARAM_OPTIONAL
	Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	result = daytime_format(value,flags);
	ZVAL_STR(return_value, result);
}

ZEND_FUNCTION(daytime_split)
{
	double value;
	zval*   hours;
	zval*   mins;
	zval*   secs;
	int h24, m60;
	double s60;

	ZEND_PARSE_PARAMETERS_START(4, 4)
	Z_PARAM_DOUBLE(value)
	Z_PARAM_ZVAL(hours)
	Z_PARAM_ZVAL(mins)
	Z_PARAM_ZVAL(secs)
	ZEND_PARSE_PARAMETERS_END();

	daytime_split(value, &h24, &m60, &s60);

	ZVAL_LONG(Z_REFVAL_P(hours), h24);
	ZVAL_LONG(Z_REFVAL_P(mins), m60);
	ZVAL_DOUBLE(Z_REFVAL_P(secs), s60);

}

ZEND_FUNCTION(daytime_set)
{
	long hours;
	long mins;
	double secs;
	double ret;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(hours)
		Z_PARAM_LONG(mins)
		Z_PARAM_DOUBLE(secs)
	ZEND_PARSE_PARAMETERS_END();

	char* error = daytime_set(hours,mins,secs, &ret);	

	if (error) {
		zend_throw_exception(zend_ce_exception,error,1);
	}

	ZVAL_DOUBLE(return_value, ret);
}

ZEND_FUNCTION(daytime_str) {
	char* src;
	long  slen;
	double ret;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(src, slen)
	ZEND_PARSE_PARAMETERS_END();

	char* error = sto_daytime(src, slen, &ret);
	ZVAL_DOUBLE(return_value, ret);

	if (error) {
		zend_throw_exception(zend_ce_exception,error,1);
	}
}