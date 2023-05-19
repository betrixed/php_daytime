dnl config.m4 for extension daytime


PHP_ARG_ENABLE([daytime],
  [whether to enable daytime support],
  [AS_HELP_STRING([--enable-daytime],
    [Enable daytime support])],
  [no])

if test "$DAYTIME" != "no"; then
  AC_DEFINE(HAVE_DAYTIME, 1, [ Have daytime support ])
  PHP_ADD_INCLUDE(daytime)
  PHP_NEW_EXTENSION(daytime, \
    php_daytime.c src/daytime.c \
    , $ext_shared)
  PHP_SUBST(DAYTIME_SHARED_LIBADD)
  CFLAGS="$CFLAGS -std=c17"
fi
