/*
 * Copyright 2020, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   wilton-dyload.cpp
 * Author: alex
 *
 * Created on July 1, 2020, 1:10 PM
 */

#ifndef UNICODE
#define UNICODE
#endif // UNICODE

#ifndef _UNICODE
#define _UNICODE
#endif // _UNICODE

#ifndef NOMINMAX
#define NOMINMAX
#endif // NOMINMAX

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "quickjs.h"

HMODULE lib() {
    static auto ;
    return res;
}

typedef JSRuntime*(*wilton_JS_NewRuntime)();
typedef void(*wilton_JS_FreeRuntime)(JSRuntime*);
typedef JSContext*(*wilton_JS_NewContext)(JSRuntime*);
typedef void(*wilton_JS_FreeContext)(JSContext*);
typedef void(*wilton_JS_SetMemoryLimit)(JSRuntime*, size_t);
typedef void(*wilton_JS_SetGCThreshold)(JSRuntime*, size_t);
typedef void(*wilton_JS_SetMaxStackSize)(JSRuntime*, size_t);
typedef JSValue(*wilton_JS_NewCFunction2)(JSContext*, JSCFunction*, const char*, int, JSCFunctionEnum, int);
typedef JS_BOOL(*wilton_JS_IsFunction)(JSContext*, JSValueConst);
typedef JSValue(*wilton_JS_Eval)(JSContext*, const char*, size_t, const char*, int);
typedef JSValue(*wilton_JS_GetGlobalObject)(JSContext*);
typedef void(*wilton___JS_FreeValue)(JSContext*, JSValue);
typedef JSValue(*wilton_JS_GetPropertyStr)(JSContext*, JSValueConst, const char*);
typedef int(*wilton_JS_SetPropertyStr)(JSContext*, JSValueConst, const char*, JSValue);
typedef const char*(*wilton_JS_ToCStringLen2)(JSContext*, size_t*, JSValueConst, JS_BOOL);
typedef void(*wilton_JS_FreeCString)(JSContext*, const char*);
typedef JSValue(*wilton_JS_Throw)(JSContext*, JSValue);
typedef JSValue(*wilton_JS_GetException)(JSContext*);
typedef JSValue(*wilton_JS_NewStringLen)(JSContext*, const char*, size_t);
typedef JSValue(*wilton_JS_NewError)(JSContext*);
typedef JSValue(*wilton_JS_Call)(JSContext*, JSValueConst, JSValueConst, int, JSValueConst*);
typedef void(*wilton_JS_RunGC)(JSRuntime*);
typedef JSValue(*wilton_JS_WiltonUndefined)();
typedef JSValue(*wilton_JS_WiltonNull)();

static HMODULE lib = NULL;

int JS_WiltonInitialize() {
    lib = LoadLibraryW(L"quickjs.dll")
    if (NULL != lib) {
        int err = (int) GetLastError();
        if (0 == err) {
            return -1;
        } else {
            return err;
        }
    }
    return 0;
}

JSRuntime *JS_NewRuntime(void) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_NewRuntime");
    wilton_JS_NewRuntime fun = (wilton_JS_NewRuntime) ptr;
    return fun();
}

void JS_FreeRuntime(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_FreeRuntime");
    wilton_JS_FreeRuntime fun = (wilton_JS_FreeRuntime)(ptr);
    fun(rt);
}

JSContext *JS_NewContext(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_NewContext");
    wilton_JS_NewContext fun = (wilton_JS_NewContext)(ptr);
    return fun(rt);
}

void JS_FreeContext(JSContext *s) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_FreeContext");
    wilton_JS_FreeContext fun = (wilton_JS_FreeContext)(ptr);
    fun(s);
}

void JS_SetMemoryLimit(JSRuntime *rt, size_t limit) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_SetMemoryLimit");
    wilton_JS_SetMemoryLimit fun = (wilton_JS_SetMemoryLimit)(ptr);
    fun(rt, limit);
}

void JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_SetGCThreshold");
    wilton_JS_SetGCThreshold fun = (wilton_JS_SetGCThreshold)(ptr);
    fun(rt, gc_threshold);
}

void JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_SetMaxStackSize");
    wilton_JS_SetMaxStackSize fun = (wilton_JS_SetMaxStackSize)(ptr);
    fun(rt, stack_size);
}

JSValue JS_NewCFunction2(JSContext *ctx, JSCFunction *func, const char *name, int length, JSCFunctionEnum cproto, int magic) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_NewCFunction2");
    wilton_JS_NewCFunction2 fun = (wilton_JS_NewCFunction2)(ptr);
    return fun(ctx, func, name, length, cproto, magic);
}

JS_BOOL JS_IsFunction(JSContext* ctx, JSValueConst val) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_IsFunction");
    wilton_JS_IsFunction fun = (wilton_JS_IsFunction)(ptr);
    return fun(ctx, val);
}

JSValue JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_Eval");
    wilton_JS_Eval fun = (wilton_JS_Eval)(ptr);
    return fun(ctx, input, input_len, filename, eval_flags);
}

JSValue JS_GetGlobalObject(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_GetGlobalObject");
    wilton_JS_GetGlobalObject fun = (wilton_JS_GetGlobalObject)(ptr);
    return fun(ctx);
}

void __JS_FreeValue(JSContext *ctx, JSValue v) {
    FARPROC ptr = GetProcAddress(lib(), "wilton___JS_FreeValue");
    wilton___JS_FreeValue fun = (wilton___JS_FreeValue)(ptr);
    fun(ctx, v);
}

JSValue JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_GetPropertyStr");
    wilton_JS_GetPropertyStr fun = (wilton_JS_GetPropertyStr)(ptr);
    return fun(ctx, this_obj, prop);
}

int JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_SetPropertyStr");
    wilton_JS_SetPropertyStr fun = (wilton_JS_SetPropertyStr)(ptr);
    return fun(ctx, this_obj, prop, val);
}

const char *JS_ToCStringLen2(JSContext *ctx, size_t *plen, JSValueConst val1, JS_BOOL cesu8) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_ToCStringLen2");
    wilton_JS_ToCStringLen2 fun = (wilton_JS_ToCStringLen2)(ptr);
    return fun(ctx, plen, val1, cesu8);
}

void JS_FreeCString(JSContext *ctx, const char *ptr1) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_FreeCString");
    wilton_JS_FreeCString fun = (wilton_JS_FreeCString)(ptr);
    fun(ctx, ptr1);
}

JSValue JS_Throw(JSContext *ctx, JSValue obj) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_Throw");
    wilton_JS_Throw fun = (wilton_JS_Throw)(ptr);
    return fun(ctx, obj);
}

JSValue JS_GetException(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_GetException");
    wilton_JS_GetException fun = (wilton_JS_GetException)(ptr);
    return fun(ctx);
}

JSValue JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_NewStringLen");
    wilton_JS_NewStringLen fun = (wilton_JS_NewStringLen)(ptr);
    return fun(ctx, str1, len1);
}

JSValue JS_NewError(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_NewError");
    wilton_JS_NewError fun = (wilton_JS_NewError)(ptr);
    return fun(ctx);
}

JSValue JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_Call");
    wilton_JS_Call fun = (wilton_JS_Call)(ptr);
    return fun(ctx, func_obj, this_obj, argc, argv);
}

void JS_RunGC(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib(), "wilton_JS_RunGC");
    wilton_JS_RunGC fun = (wilton_JS_RunGC)(ptr);
    fun(rt);
}

} // extern
