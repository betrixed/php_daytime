/* daytime extension for PHP */

#ifndef PHP_DAYTIME_H
# define PHP_DAYTIME_H

extern zend_module_entry daytime_module_entry;
# define phpext_daytime_ptr &daytime_module_entry

# define PHP_DAYTIME_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_DAYTIME)
ZEND_TSRMLS_CACHE_EXTERN()
# endif



/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif
	

typedef struct _day_time {
	double	tval;
}
day_time;

typedef struct _t_daytime* p_daytime;

typedef struct _t_daytime {
	day_time			 daytime;
	zend_object          std;
} t_daytime;


static inline  p_daytime p_daytime_from_obj(zend_object *obj)
{
	return (p_daytime)((char*)(obj) - XtOffsetOf(t_daytime, std));
}

static inline  p_daytime ZP_DAYTIME_P(zval *zv)
{
	return (p_daytime)((char*) Z_OBJ_P((zv)) - XtOffsetOf(t_daytime, std));
}

#endif	/* PHP_DAYTIME_H */
