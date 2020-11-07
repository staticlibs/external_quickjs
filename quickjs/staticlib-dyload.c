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
 * File:   staticlib-dyload.cpp
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

typedef JSRuntime*(*staticlib_JS_NewRuntime)();
typedef void(*staticlib_JS_FreeRuntime)(JSRuntime*);
typedef JSContext*(*staticlib_JS_NewContext)(JSRuntime*);
typedef void(*staticlib_JS_FreeContext)(JSContext*);
typedef void(*staticlib_JS_SetMemoryLimit)(JSRuntime*, size_t);
typedef void(*staticlib_JS_SetGCThreshold)(JSRuntime*, size_t);
typedef void(*staticlib_JS_SetMaxStackSize)(JSRuntime*, size_t);
typedef JSValue(*staticlib_JS_NewCFunction2)(JSContext*, JSCFunction*, const char*, int, JSCFunctionEnum, int);
typedef JS_BOOL(*staticlib_JS_IsFunction)(JSContext*, JSValueConst);
typedef JSValue(*staticlib_JS_Eval)(JSContext*, const char*, size_t, const char*, int);
typedef JSValue(*staticlib_JS_GetGlobalObject)(JSContext*);
typedef void(*staticlib___JS_FreeValue)(JSContext*, JSValue);
typedef JSValue(*staticlib_JS_GetPropertyStr)(JSContext*, JSValueConst, const char*);
typedef int(*staticlib_JS_SetPropertyStr)(JSContext*, JSValueConst, const char*, JSValue);
typedef const char*(*staticlib_JS_ToCStringLen2)(JSContext*, size_t*, JSValueConst, JS_BOOL);
typedef void(*staticlib_JS_FreeCString)(JSContext*, const char*);
typedef JSValue(*staticlib_JS_Throw)(JSContext*, JSValue);
typedef JSValue(*staticlib_JS_GetException)(JSContext*);
typedef JSValue(*staticlib_JS_NewStringLen)(JSContext*, const char*, size_t);
typedef JSValue(*staticlib_JS_NewError)(JSContext*);
typedef JSValue(*staticlib_JS_Call)(JSContext*, JSValueConst, JSValueConst, int, JSValueConst*);
typedef void(*staticlib_JS_RunGC)(JSRuntime*);
typedef void(*staticlib_JS_SetModuleLoaderFunc)(JSRuntime*, JSModuleNormalizeFunc*, JSModuleLoaderFunc*, void*);
typedef JSValue(*staticlib_JS_NewArray)(JSContext*);
typedef JSValue(*staticlib_JS_EvalFunction)(JSContext*, JSValue);
typedef int(*staticlib_JS_DefinePropertyValueUint32)(JSContext*, JSValueConst, uint32_t, JSValue, int);
typedef int(*staticlib_JS_DefinePropertyValueStr)(JSContext*, JSValueConst, const char*, JSValue, int);
typedef JSValue(*staticlib_JS_GetImportMeta)(JSContext*, JSModuleDef*);

static HMODULE lib = NULL;

int JS_StaticlibInitialize() {
    lib = LoadLibraryW(L"quickjs.dll");
    if (NULL == lib) {
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
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewRuntime");
    staticlib_JS_NewRuntime fun = (staticlib_JS_NewRuntime) ptr;
    return fun();
}

void JS_FreeRuntime(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_FreeRuntime");
    staticlib_JS_FreeRuntime fun = (staticlib_JS_FreeRuntime)(ptr);
    fun(rt);
}

JSContext *JS_NewContext(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewContext");
    staticlib_JS_NewContext fun = (staticlib_JS_NewContext)(ptr);
    return fun(rt);
}

void JS_FreeContext(JSContext *s) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_FreeContext");
    staticlib_JS_FreeContext fun = (staticlib_JS_FreeContext)(ptr);
    fun(s);
}

void JS_SetMemoryLimit(JSRuntime *rt, size_t limit) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_SetMemoryLimit");
    staticlib_JS_SetMemoryLimit fun = (staticlib_JS_SetMemoryLimit)(ptr);
    fun(rt, limit);
}

void JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_SetGCThreshold");
    staticlib_JS_SetGCThreshold fun = (staticlib_JS_SetGCThreshold)(ptr);
    fun(rt, gc_threshold);
}

void JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_SetMaxStackSize");
    staticlib_JS_SetMaxStackSize fun = (staticlib_JS_SetMaxStackSize)(ptr);
    fun(rt, stack_size);
}

JSValue JS_NewCFunction2(JSContext *ctx, JSCFunction *func, const char *name, int length, JSCFunctionEnum cproto, int magic) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewCFunction2");
    staticlib_JS_NewCFunction2 fun = (staticlib_JS_NewCFunction2)(ptr);
    return fun(ctx, func, name, length, cproto, magic);
}

JS_BOOL JS_IsFunction(JSContext* ctx, JSValueConst val) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_IsFunction");
    staticlib_JS_IsFunction fun = (staticlib_JS_IsFunction)(ptr);
    return fun(ctx, val);
}

JSValue JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_Eval");
    staticlib_JS_Eval fun = (staticlib_JS_Eval)(ptr);
    return fun(ctx, input, input_len, filename, eval_flags);
}

JSValue JS_GetGlobalObject(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_GetGlobalObject");
    staticlib_JS_GetGlobalObject fun = (staticlib_JS_GetGlobalObject)(ptr);
    return fun(ctx);
}

void __JS_FreeValue(JSContext *ctx, JSValue v) {
    FARPROC ptr = GetProcAddress(lib, "staticlib___JS_FreeValue");
    staticlib___JS_FreeValue fun = (staticlib___JS_FreeValue)(ptr);
    fun(ctx, v);
}

JSValue JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_GetPropertyStr");
    staticlib_JS_GetPropertyStr fun = (staticlib_JS_GetPropertyStr)(ptr);
    return fun(ctx, this_obj, prop);
}

int JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_SetPropertyStr");
    staticlib_JS_SetPropertyStr fun = (staticlib_JS_SetPropertyStr)(ptr);
    return fun(ctx, this_obj, prop, val);
}

const char *JS_ToCStringLen2(JSContext *ctx, size_t *plen, JSValueConst val1, JS_BOOL cesu8) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_ToCStringLen2");
    staticlib_JS_ToCStringLen2 fun = (staticlib_JS_ToCStringLen2)(ptr);
    return fun(ctx, plen, val1, cesu8);
}

void JS_FreeCString(JSContext *ctx, const char *ptr1) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_FreeCString");
    staticlib_JS_FreeCString fun = (staticlib_JS_FreeCString)(ptr);
    fun(ctx, ptr1);
}

JSValue JS_Throw(JSContext *ctx, JSValue obj) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_Throw");
    staticlib_JS_Throw fun = (staticlib_JS_Throw)(ptr);
    return fun(ctx, obj);
}

JSValue JS_GetException(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_GetException");
    staticlib_JS_GetException fun = (staticlib_JS_GetException)(ptr);
    return fun(ctx);
}

JSValue JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewStringLen");
    staticlib_JS_NewStringLen fun = (staticlib_JS_NewStringLen)(ptr);
    return fun(ctx, str1, len1);
}

JSValue JS_NewError(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewError");
    staticlib_JS_NewError fun = (staticlib_JS_NewError)(ptr);
    return fun(ctx);
}

JSValue JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_Call");
    staticlib_JS_Call fun = (staticlib_JS_Call)(ptr);
    return fun(ctx, func_obj, this_obj, argc, argv);
}

void JS_RunGC(JSRuntime *rt) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_RunGC");
    staticlib_JS_RunGC fun = (staticlib_JS_RunGC)(ptr);
    fun(rt);
}

void JS_SetModuleLoaderFunc(JSRuntime *rt, JSModuleNormalizeFunc *module_normalize, JSModuleLoaderFunc *module_loader, void *opaque) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_SetModuleLoaderFunc");
    staticlib_JS_SetModuleLoaderFunc fun = (staticlib_JS_SetModuleLoaderFunc)(ptr);
    fun(rt, module_normalize, module_loader, opaque);
}

JSValue JS_NewArray(JSContext *ctx) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_NewArray");
    staticlib_JS_NewArray fun = (staticlib_JS_NewArray)(ptr);
    return fun(ctx);
}

JSValue JS_EvalFunction(JSContext *ctx, JSValue fun_obj) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_EvalFunction");
    staticlib_JS_EvalFunction fun = (staticlib_JS_EvalFunction)(ptr);
    return fun(ctx, fun_obj);
}

int JS_DefinePropertyValueUint32(JSContext *ctx, JSValueConst this_obj, uint32_t idx, JSValue val, int flags) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_DefinePropertyValueUint32");
    staticlib_JS_DefinePropertyValueUint32 fun = (staticlib_JS_DefinePropertyValueUint32)(ptr);
    return fun(ctx, this_obj, idx, val, flags);
}

int JS_DefinePropertyValueStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val, int flags) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_DefinePropertyValueStr");
    staticlib_JS_DefinePropertyValueStr fun = (staticlib_JS_DefinePropertyValueStr)(ptr);
    return fun(ctx, this_obj, prop, val, flags);
}

JSValue JS_GetImportMeta(JSContext *ctx, JSModuleDef *m) {
    FARPROC ptr = GetProcAddress(lib, "staticlib_JS_GetImportMeta");
    staticlib_JS_GetImportMeta fun = (staticlib_JS_GetImportMeta)(ptr);
    return fun(ctx, m);
}
