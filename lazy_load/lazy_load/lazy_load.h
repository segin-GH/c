#ifndef LAZY_LOAD_H
#define LAZY_LOAD_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define LAZY_LOAD_MIN_INDEX 0
#define LAZY_LOAD_MAX_INDEX 10
#define LAZY_LOAD_MAX_RETRY 3

    typedef enum
    {
        LAZY_LOAD_OK = 0,
        LAZY_LOAD_ERR,
        LAZY_LOAD_INVALID_ARG,
        LAZY_LOAD_WOULD_LOAD,
    } lazy_load_err_t;

    typedef int (*lazy_load_init_func_t)(void);
    typedef int (*lazy_load_deinit_func_t)(void);

    typedef struct
    {
        lazy_load_init_func_t init_func;
        lazy_load_deinit_func_t deinit_func;
        bool is_loaded;
        int error_code;
        int retry_count;
    } lazy_load_resource_t;

    typedef struct
    {
        lazy_load_resource_t *lazy_load_resource[LAZY_LOAD_MAX_INDEX];
        int lazy_resource_added_count;
        int lazy_loaded_count;
    } lazy_load_t;

    lazy_load_err_t lazy_load_init(lazy_load_t *dev);
    lazy_load_err_t lazy_load_deinit(lazy_load_t *dev);

    lazy_load_err_t lazy_load_add_resource(lazy_load_t *dev, int index, lazy_load_resource_t *resource);
    lazy_load_err_t lazy_load_remove_resource(lazy_load_t *dev, int index);

    lazy_load_err_t lazy_load(lazy_load_t *dev, int index);
    lazy_load_err_t lazy_load_all(lazy_load_t *dev);

    lazy_load_err_t lazy_unload(lazy_load_t *dev, int index);
    lazy_load_err_t lazy_unload_all(lazy_load_t *dev);

#ifdef __cplusplus
}
#endif

#endif
