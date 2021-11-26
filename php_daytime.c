#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/pcre/php_pcre.h"
#include "zend_exceptions.h"

#include "Zend/zend_interfaces.h"
#include "Zend/zend_smart_str.h"
#include "Zend/zend_types.h"
#include "daytime_arginfo.h"
#include "src/daytime.h"
#include "php_daytime.h"

zend_object_handlers 	obj_handler_DayTime;

zend_class_entry *zt_ce_DayTime;

#define REGISTER_DAYTIME_CONST_LONG(const_name, value) \
	zend_declare_class_constant_long(zt_ce_DayTime, const_name, sizeof(const_name)-1, (zend_long)value);


PHP_METHOD(DayTime, __construct)
{
	zval *object = ZEND_THIS;
	char* src;
	long  slen;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(src, slen)
	ZEND_PARSE_PARAMETERS_END();
	p_daytime pz = ZP_DAYTIME_P(object);

	char* error = sto_daytime(src, slen, &pz->daytime.tval);
	if (error) {
		zend_throw_exception(zend_ce_exception,error,0);
	}	

}

PHP_METHOD(DayTime, str)
{
	zval *object = ZEND_THIS;
	char* src;
	long  slen;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STRING(src, slen)
	ZEND_PARSE_PARAMETERS_END();
	p_daytime pz = ZP_DAYTIME_P(object);

	char* error = sto_daytime(src, slen, &pz->daytime.tval);
	if (error) {
		zend_throw_exception(zend_ce_exception,error,0);
	}	

}

PHP_METHOD(DayTime, set)
{
	zval *object = ZEND_THIS;
	long hours;
	long mins;
	double secs;	

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(hours)
		Z_PARAM_LONG(mins)
		Z_PARAM_DOUBLE(secs)
	ZEND_PARSE_PARAMETERS_END();
	p_daytime pz = ZP_DAYTIME_P(object);

	char* error = daytime_set(hours,mins,secs, &pz->daytime.tval);	
	
	if (error) {
		zend_throw_exception(zend_ce_exception,error,0);
	}
}


PHP_METHOD(DayTime, split)
{
	zval *object = ZEND_THIS;
	zval*   hours;
	zval*   mins;
	zval*   secs;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_ZVAL(hours)
	Z_PARAM_ZVAL(mins)
	Z_PARAM_ZVAL(secs)
	ZEND_PARSE_PARAMETERS_END();

	int h24, m60;
	double s60;
	p_daytime pz = ZP_DAYTIME_P(object);
	daytime_split(pz->daytime.tval, &h24, &m60, &s60);

	ZVAL_LONG(Z_REFVAL_P(hours), h24);
	ZVAL_LONG(Z_REFVAL_P(mins), m60);
	ZVAL_DOUBLE(Z_REFVAL_P(secs), s60);
}

PHP_METHOD(DayTime, format)
{
	zval *object = ZEND_THIS;
	long 	flags = 0;
	zend_string *result;

	ZEND_PARSE_PARAMETERS_START(0, 1)
	Z_PARAM_OPTIONAL
	Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	p_daytime pz = ZP_DAYTIME_P(object);

	result = daytime_format(pz->daytime.tval,flags);
	ZVAL_STR(return_value, result);

}

PHP_METHOD(DayTime, day)
{
	zval *object = ZEND_THIS;
	double    value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(value);
	ZEND_PARSE_PARAMETERS_END();

	p_daytime pz = ZP_DAYTIME_P(object);

	if (value < 0.0 || value >= 1.0) {
		zend_throw_exception(zend_ce_exception,"Value must be positive fraction",0);
	}

	pz->daytime.tval = value;
}


PHP_METHOD(DayTime, value)
{
	zval *object = ZEND_THIS;

	ZEND_PARSE_PARAMETERS_NONE();

	p_daytime pz = ZP_DAYTIME_P(object);

	ZVAL_DOUBLE(return_value, pz->daytime.tval);
}

PHP_METHOD(DayTime, __toString)
{
	zval *object = ZEND_THIS;
	zend_string *result;

	ZEND_PARSE_PARAMETERS_NONE();
	
	p_daytime pz = ZP_DAYTIME_P(object);
	result = daytime_format(pz->daytime.tval,DAYT_SEC_AUTO);
	ZVAL_STR(return_value, result);

}


static void t_daytime_copy_ctor( p_daytime to, p_daytime from)
{

}

static zend_object *t_daytime_new_ex(zend_class_entry *class_type,
									zend_object *orig, bool clone_orig)
{
	p_daytime 		  	   intern;
	zend_class_entry      *parent = class_type;
	bool                   inherited = false;

	intern = zend_object_alloc(sizeof(t_daytime), class_type);
	intern->daytime.tval = 0.0;


	zend_object_std_init(&intern->std, class_type);

	object_properties_init(&intern->std, class_type);

	if (orig && clone_orig) {
		p_daytime other = p_daytime_from_obj(orig);
		t_daytime_copy_ctor(intern, other);
	}
	while(parent) {
		if (parent == zt_ce_DayTime) {
			intern->std.handlers = &obj_handler_DayTime;
			break;
		}
		parent = parent->parent;
		inherited = true;
	}

	ZEND_ASSERT(parent);

	return &intern->std;
	
}



static zend_object *t_daytime_new(zend_class_entry *class_type)
{
	return t_daytime_new_ex(class_type, NULL, 0);
}

static zend_object *t_daytime_clone(zend_object *old_object)
{
	zend_object *new_object = t_daytime_new_ex(old_object->ce, old_object, 1);

	zend_objects_clone_members(new_object, old_object);

	return new_object;
}

static void t_daytime_free_storage(zend_object *object)
{
	p_daytime intern = p_daytime_from_obj(object);

	zend_object_std_dtor(&intern->std);
}

PHPAPI void 
t_register_std_class(zend_class_entry ** ppce, 
	char * class_name,  
	const zend_function_entry* function_list)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY_EX(ce, class_name, strlen(class_name), function_list);
	*ppce = zend_register_internal_class(&ce);
}

PHP_MINIT_FUNCTION(t_daytime)
{
	t_register_std_class(&zt_ce_DayTime, "DayTime", class_DayTime_methods);

	zt_ce_DayTime->create_object = t_daytime_new;

	memcpy(&obj_handler_DayTime, &std_object_handlers, sizeof(zend_object_handlers));

	obj_handler_DayTime.offset = XtOffsetOf(t_daytime, std);
	obj_handler_DayTime.clone_obj = t_daytime_clone;
	obj_handler_DayTime.dtor_obj  = zend_objects_destroy_object;
	obj_handler_DayTime.free_obj  = t_daytime_free_storage;

	REGISTER_DAYTIME_CONST_LONG("DAYT_SEC_AUTO", (zend_long)DAYT_SEC_AUTO);
	REGISTER_DAYTIME_CONST_LONG("DAYT_SEC_INT", (zend_long)DAYT_SEC_INT);
	REGISTER_DAYTIME_CONST_LONG("DAYT_SEC_DEC", (zend_long)DAYT_SEC_DEC);
	REGISTER_DAYTIME_CONST_LONG("DAYT_SEC_NONE", (zend_long)DAYT_SEC_NONE);
}

PHP_MINIT_FUNCTION(daytime)
{
	PHP_MINIT(t_daytime)(INIT_FUNC_ARGS_PASSTHRU);

}

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(daytime)
{
#if defined(ZTS) && defined(COMPILE_DL_DAYTIME)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(daytime)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "daytime support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ daytime_module_entry */
zend_module_entry daytime_module_entry = {
	STANDARD_MODULE_HEADER,
	"daytime",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	PHP_MINIT(daytime),							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(daytime),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(daytime),			/* PHP_MINFO - Module info */
	PHP_DAYTIME_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_DAYTIME
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(daytime)
#endif