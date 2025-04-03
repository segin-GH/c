#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LAZY_LOAD_MIN_INDEX 0
#define LAZY_LOAD_MAX_INDEX 10
#define LAZY_LOAD_MAX_RETRY 3

typedef enum
{
    LAZY_LOAD_OK = 0,
    LAZY_LOAD_ERR_RETRY,
    LAZY_LOAD_INVALID_ARG,
    LAZY_LOAD_WOULD_LOAD,
    LAZY_LOAD_WOULD_UNLOAD,
    LAZY_LOAD_ERR_FATAL,
} lazy_load_err_t;

typedef enum
{
    LAZY_LOAD = 0,
    SHOULD_LOAD,
} lazy_load_type_t;

typedef int (*lazy_load_init_func_t)(void);
typedef int (*lazy_load_deinit_func_t)(void);

typedef struct
{
    lazy_load_init_func_t init_func;
    lazy_load_deinit_func_t deinit_func;
    lazy_load_type_t type;
    bool is_loaded;
    int error_code;
    int retry_count;
} lazy_load_resource_t;

typedef struct
{
    lazy_load_resource_t *lazy_load_resource[LAZY_LOAD_MAX_INDEX];
    int lazy_load_resource_added_count;
    int lazy_load_resource_loaded_count;
    int lazy_load_resource_loading_count;
    int lazy_load_resource_unloading_count;

} lazy_load_t;

lazy_load_err_t lazy_load_init(lazy_load_t *dev);
lazy_load_err_t lazy_load_deinit(lazy_load_t *dev);

lazy_load_err_t lazy_load_add_resource(lazy_load_t *dev, int index, lazy_load_resource_t *resource);
lazy_load_err_t lazy_load_remove_resource(lazy_load_t *dev, int index);

lazy_load_err_t lazy_load(lazy_load_t *dev, int index);
lazy_load_err_t lazy_load_all(lazy_load_t *dev);

lazy_load_err_t lazy_unload(lazy_load_t *dev, int index);
lazy_load_err_t lazy_unload_all(lazy_load_t *dev);

#define LAZY_LOAD_DEV_CHECK(dev)                                                                                       \
    {                                                                                                                  \
        if (!dev)                                                                                                      \
            return LAZY_LOAD_INVALID_ARG;                                                                              \
    }

lazy_load_err_t lazy_load_init(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);

    memset(dev->lazy_load_resource, 0, sizeof(dev->lazy_load_resource));
    dev->lazy_load_resource_loading_count = 0;
    dev->lazy_load_resource_added_count = 0;

    return LAZY_LOAD_OK;
}

lazy_load_err_t lazy_load_deinit(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);

    /*TODO: Add this*/
    return LAZY_LOAD_OK;
}

lazy_load_err_t lazy_load_add_resource(lazy_load_t *dev, int index, lazy_load_resource_t *resource)
{
    LAZY_LOAD_DEV_CHECK(dev);
    dev->lazy_load_resource[dev->lazy_load_resource_added_count++] = resource;

    return LAZY_LOAD_OK;
}

lazy_load_err_t lazy_load_remove_resource(lazy_load_t *dev, int index)
{
    LAZY_LOAD_DEV_CHECK(dev);

    return LAZY_LOAD_OK;
}

static lazy_load_err_t lazy_load_handle_failure(lazy_load_resource_t *resource)
{
    resource->is_loaded = false;
    resource->retry_count++;

    if (resource->retry_count >= LAZY_LOAD_MAX_RETRY)
    {
        return (resource->type == SHOULD_LOAD) ? LAZY_LOAD_ERR_FATAL : LAZY_LOAD_ERR_RETRY;
    }

    return LAZY_LOAD_WOULD_LOAD;
}

lazy_load_err_t lazy_load_all(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);

    if (dev->lazy_load_resource_loading_count < dev->lazy_load_resource_added_count)
    {
        lazy_load_resource_t *resource = dev->lazy_load_resource[dev->lazy_load_resource_loading_count];
        if (!resource->is_loaded && resource->retry_count < LAZY_LOAD_MAX_RETRY)
        {
            resource->error_code = resource->init_func();
            resource->is_loaded = true;

            if (resource->error_code != 0)
            {
                return lazy_load_handle_failure(resource);
            }
        }
        dev->lazy_load_resource_loading_count++;
        dev->lazy_load_resource_loaded_count++;
    }

    if (dev->lazy_load_resource_loading_count == dev->lazy_load_resource_added_count)
    {
        dev->lazy_load_resource_loading_count = 0;
        return LAZY_LOAD_OK;
    }

    return LAZY_LOAD_WOULD_LOAD;
}

int lazy_load_get_current_index(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);
    return dev->lazy_load_resource_loaded_count;
}

int lazy_load_get_error_code(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);
    lazy_load_resource_t *resource = dev->lazy_load_resource[dev->lazy_load_resource_loaded_count];
    return resource->error_code;
}

lazy_load_err_t lazy_unload_all(lazy_load_t *dev)
{
    LAZY_LOAD_DEV_CHECK(dev);

    if (dev->lazy_load_resource_loaded_count > 0)
    {
        lazy_load_resource_t *resource = dev->lazy_load_resource[dev->lazy_load_resource_loaded_count - 1];
        if (resource->is_loaded && resource->retry_count < LAZY_LOAD_MAX_RETRY)
        {
            resource->error_code = resource->deinit_func();
            resource->is_loaded = false;

            if (resource->error_code != 0)
            {
                resource->is_loaded = true;
                resource->retry_count++;

                if (resource->retry_count >= LAZY_LOAD_MAX_RETRY)
                {
                    dev->lazy_load_resource_loaded_count--;
                    return LAZY_LOAD_ERR_RETRY;
                }

                return LAZY_LOAD_WOULD_UNLOAD;
            }
        }
    }

    dev->lazy_load_resource_loaded_count--;
    return (dev->lazy_load_resource_loaded_count < 0) ? LAZY_LOAD_OK : LAZY_LOAD_WOULD_UNLOAD;
}

lazy_load_err_t lazy_load(lazy_load_t *dev, int index)
{
    LAZY_LOAD_DEV_CHECK(dev);

    /*TODO: Add this*/
    return LAZY_LOAD_OK;
}

lazy_load_err_t lazy_unload(lazy_load_t *dev, int index)
{
    LAZY_LOAD_DEV_CHECK(dev);

    /*TODO: Add this*/
    return LAZY_LOAD_OK;
}

// Example init function
//
int example_init_one(void)
{
    printf("Example resource initialized 0\n");
    return 0;
}

int example_deinit_one(void)
{
    printf("Example resource deinitialized 0\n");
    return 1;
}

int example_init_two(void)
{
    printf("Example resource initialized 1\n");
    return 0;
}

int example_deinit_two(void)
{
    printf("Example resource deinitialized 1\n");
    return 0;
}

int example_init_three(void)
{
    printf("Example resource initialized 2\n");
    static int times_called = 1;

    times_called++;

    if (times_called > 2)
        return 0;

    return 2;
}

int example_deinit_three(void)
{
    printf("Example resource deinitialized 2\n");
    return 0;
}

int example_init_four(void)
{
    printf("Example resource initialized 3\n");
    return 3;
}

int example_deinit_four(void)
{
    printf("Example resource deinitialized 3\n");
    return 0;
}

int example_init_five(void)
{
    printf("Example resource initialized 4\n");
    return 0;
}

int example_deinit_five(void)
{
    printf("Example resource deinitialized 4\n");
    return 0;
}

int example_init_six(void)
{
    printf("Example resource initialized 5\n");
    return 5;
}

int example_deinit_six(void)
{
    printf("Example resource deinitialized 5\n");
    return 0;
}

int main(void)
{
    lazy_load_err_t err = LAZY_LOAD_OK;
    lazy_load_t dev;
    bool load_complete = false;

    err = lazy_load_init(&dev);
    if (err != LAZY_LOAD_OK)
    {
        printf("lazy_load_init failed\n");
        return -1;
    }

    lazy_load_add_resource(&dev, 0,
                           &(lazy_load_resource_t){
                               .init_func = example_init_one,
                               .deinit_func = example_deinit_one,
                               .is_loaded = false,
                               .type = LAZY_LOAD,
                           });

    lazy_load_add_resource(&dev, 1,
                           &(lazy_load_resource_t){
                               .init_func = example_init_two,
                               .deinit_func = example_deinit_two,
                               .is_loaded = false,
                               .type = LAZY_LOAD,
                           });

    lazy_load_add_resource(&dev, 2,
                           &(lazy_load_resource_t){
                               .init_func = example_init_three,
                               .deinit_func = example_deinit_three,
                               .is_loaded = false,
                               .type = LAZY_LOAD,
                           });

    lazy_load_add_resource(&dev, 3,
                           &(lazy_load_resource_t){
                               .init_func = example_init_four,
                               .deinit_func = example_deinit_four,
                               .is_loaded = false,
                               .type = LAZY_LOAD,
                           });

    lazy_load_add_resource(&dev, 4,
                           &(lazy_load_resource_t){
                               .init_func = example_init_five,
                               .deinit_func = example_deinit_five,
                               .is_loaded = false,
                               .type = SHOULD_LOAD,
                           });

    lazy_load_add_resource(&dev, 5,
                           &(lazy_load_resource_t){
                               .init_func = example_init_six,
                               .deinit_func = example_deinit_six,
                               .is_loaded = false,
                               .type = SHOULD_LOAD,
                           });

    while (load_complete == false)
    {
        err = lazy_load_all(&dev);
        if (err == LAZY_LOAD_OK)
        {
            printf("All resources loaded successfully\n");
            load_complete = true;
        }
        else if (err == LAZY_LOAD_WOULD_LOAD)
        {
            printf("More resources to load\n");
        }
        else if (err == LAZY_LOAD_ERR_FATAL)
        {
            printf("Fatal error loading resource restart?\n");
            printf("Failed to load index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));

            load_complete = true;
        }
        else if (err == LAZY_LOAD_ERR_RETRY)
        {
            printf("Error at loading a lazy component\n");
            printf("Failed to load index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));
        }
        else
        {
            printf("Unknown error\n");
        }
    }

    load_complete = false;

    while (load_complete == false)
    {
        err = lazy_load_all(&dev);
        if (err == LAZY_LOAD_OK)
        {
            printf("All resources loaded successfully\n");
            load_complete = true;
        }
        else if (err == LAZY_LOAD_WOULD_LOAD)
        {
            printf("More resources to load\n");
        }
        else if (err == LAZY_LOAD_ERR_FATAL)
        {
            printf("Fatal error loading resource restart?\n");
            printf("Failed to load index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));

            load_complete = true;
        }
        else if (err == LAZY_LOAD_ERR_RETRY)
        {
            printf("Error at loading a lazy component\n");
            printf("Failed to load index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));
        }
        else
        {
            printf("Unknown error\n");
        }
    }

    while (load_complete == true)
    {
        err = lazy_unload_all(&dev);
        if (err == LAZY_LOAD_OK)
        {
            printf("All resources unloaded successfully\n");
            load_complete = false;
        }
        else if (err == LAZY_LOAD_WOULD_UNLOAD)
        {
            printf("More resources to unload\n");
        }
        else if (err == LAZY_LOAD_ERR_RETRY)
        {
            printf("Error at unloading a lazy component\n");
            printf("Failed to unload index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));
        }
        else if (err == LAZY_LOAD_ERR_FATAL)
        {
            printf("Fatal error unloading resource restart?\n");
            printf("Failed to unload index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));

            load_complete = false;
        }
        else
        {
            printf("Unknown error\n");
        }
    }

    while (load_complete == false)
    {
        err = lazy_unload_all(&dev);
        if (err == LAZY_LOAD_OK)
        {
            printf("All resources unloaded successfully\n");
            load_complete = false;
        }
        else if (err == LAZY_LOAD_WOULD_UNLOAD)
        {
            printf("More resources to unload\n");
        }
        else if (err == LAZY_LOAD_ERR_RETRY)
        {
            printf("Error at unloading a lazy component\n");
            printf("Failed to unload index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));
        }
        else if (err == LAZY_LOAD_ERR_FATAL)
        {
            printf("Fatal error unloading resource restart?\n");
            printf("Failed to unload index (%d), err (%d)\n", lazy_load_get_current_index(&dev),
                   lazy_load_get_error_code(&dev));

            load_complete = false;
        }
        else
        {
            printf("Unknown error\n");
        }

        sleep(1);
    }

    return 0;
}
