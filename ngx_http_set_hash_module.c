
/*
 * Copyright (c) 2009 Marcus Clyne
 */


#include    <ndk.h>


static  ndk_set_var_t      ngx_http_set_md5_hash = {
    NDK_SET_VAR_HASH,
    ndk_md5_hash,
    MD5_DIGEST_LENGTH * 2,
    NULL
};

static  ndk_set_var_t      ngx_http_set_md5_hash_upper = {
    NDK_SET_VAR_HASH,
    ndk_md5_hash_upper,
    MD5_DIGEST_LENGTH * 2,
    NULL
};

static  ndk_set_var_t      ngx_http_set_murmur2_hash = {
    NDK_SET_VAR_HASH,
    ndk_murmur2_hash,
    MURMURHASH2_DIGEST_LENGTH * 2,
    NULL
};

static  ndk_set_var_t      ngx_http_set_murmur2_hash_upper = {
    NDK_SET_VAR_HASH,
    ndk_murmur2_hash_upper,
    MURMURHASH2_DIGEST_LENGTH * 2,
    NULL
};

static  ndk_set_var_t      ngx_http_set_sha1_hash = {
    NDK_SET_VAR_HASH,
    ndk_sha1_hash,
    SHA_DIGEST_LENGTH * 2,
    NULL
};

static  ndk_set_var_t      ngx_http_set_sha1_hash_upper = {
    NDK_SET_VAR_HASH,
    ndk_sha1_hash_upper,
    SHA_DIGEST_LENGTH * 2,
    NULL
};



static ngx_command_t  ngx_http_set_hash_commands[] = {
    {
        ngx_string ("set_md5"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_md5_hash
    },
    {
        ngx_string ("set_md5_upper"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_md5_hash_upper
    },
    {
        ngx_string ("set_murmur2"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_murmur2_hash
    },
    {
        ngx_string ("set_murmur2_upper"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_murmur2_hash_upper
    },
    {
        ngx_string ("set_sha1"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_sha1_hash
    },
    {
        ngx_string ("set_sha1_upper"),
        NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_SIF_CONF|NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE2,
        ndk_set_var_value,
        0,
        0,
        &ngx_http_set_sha1_hash_upper
    },
    ngx_null_command
};


ngx_http_module_t   ngx_http_set_hash_module_ctx = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

ngx_module_t        ngx_http_set_hash_module = {

    NGX_MODULE_V1,
    &ngx_http_set_hash_module_ctx,          // module context
    ngx_http_set_hash_commands,             // module directives
    NGX_HTTP_MODULE,                        // module type
    NULL,                                   // init master
    NULL,                                   // init module
    NULL,                                   // init process
    NULL,                                   // init thread
    NULL,                                   // exit thread
    NULL,                                   // exit process
    NULL,                                   // exit master
    NGX_MODULE_V1_PADDING
};

