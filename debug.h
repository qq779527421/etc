#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

/* %s, %d, %s__FILE__,__LINE__,FUNCTION__ */
