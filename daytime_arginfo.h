/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: cb7d34b7b68067cb77049b462fd76a23b26e7ce5 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_daytime_set, 0, 3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, hours, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mins, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_daytime_str, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, t24, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_daytime_split, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, h24, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, min, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, sec, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_daytime_format, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_DayTime___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, t24, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_str, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, t24, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_day, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, t24, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_value, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_set, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hours, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mins, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_split, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, h24, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, min, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, sec, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime_format, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_DayTime___toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(daytime_set);
ZEND_FUNCTION(daytime_str);
ZEND_FUNCTION(daytime_split);
ZEND_FUNCTION(daytime_format);
ZEND_METHOD(DayTime, __construct);
ZEND_METHOD(DayTime, str);
ZEND_METHOD(DayTime, day);
ZEND_METHOD(DayTime, value);
ZEND_METHOD(DayTime, set);
ZEND_METHOD(DayTime, split);
ZEND_METHOD(DayTime, format);
ZEND_METHOD(DayTime, __toString);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(daytime_set, arginfo_daytime_set)
	ZEND_FE(daytime_str, arginfo_daytime_str)
	ZEND_FE(daytime_split, arginfo_daytime_split)
	ZEND_FE(daytime_format, arginfo_daytime_format)
	ZEND_FE_END
};


static const zend_function_entry class_DayTime_methods[] = {
	ZEND_ME(DayTime, __construct, arginfo_class_DayTime___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, str, arginfo_class_DayTime_str, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, day, arginfo_class_DayTime_day, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, value, arginfo_class_DayTime_value, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, set, arginfo_class_DayTime_set, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, split, arginfo_class_DayTime_split, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, format, arginfo_class_DayTime_format, ZEND_ACC_PUBLIC)
	ZEND_ME(DayTime, __toString, arginfo_class_DayTime___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
