
#include <string>
#include "quickjs.h"

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

// todo: removeme
#include <iostream>
// end: removeme

namespace { // anonymous

HMODULE lib() {
    static auto res = ::LoadLibraryW(L"quickjs.dll");
    return res;
}

typedef JSRuntime*(*wilton_JS_NewRuntime)();
typedef void(*wilton_JS_FreeRuntime)(JSRuntime*);
typedef JSContext*(*wilton_JS_NewContext)(JSRuntime*);
typedef void(*wilton_JS_FreeContext)(JSContext*);
typedef void(*wilton_JS_SetMemoryLimit)(JSRuntime*, size_t);
typedef void(*wilton_JS_SetGCThreshold)(JSRuntime*, size_t);
typedef void(*wilton_JS_SetMaxStackSize)(JSRuntime*, size_t);
typedef JSValue(*wilton_JS_NewCFunction)(JSContext*, JSCFunction*, const char*, int);
typedef JS_BOOL(*wilton_JS_IsFunction)(JSContext*, JSValueConst);
typedef JSValue(*wilton_JS_Eval)(JSContext*, const char*, size_t, const char*, int);
typedef JSValue(*wilton_JS_GetGlobalObject)(JSContext*);
typedef void(*wilton_JS_FreeValue)(JSContext*, JSValue);
typedef JSValue(*wilton_JS_GetPropertyStr)(JSContext*, JSValueConst, const char*);
typedef int(*wilton_JS_SetPropertyStr)(JSContext*, JSValueConst, const char*, JSValue);
typedef const char*(*wilton_JS_ToCStringLen)(JSContext*, size_t*, JSValueConst);
typedef void(*wilton_JS_FreeCString)(JSContext*, const char*);
typedef JSValue(*wilton_JS_Throw)(JSContext*, JSValue);
typedef JSValue(*wilton_JS_GetException)(JSContext*);
typedef JS_BOOL(*wilton_JS_IsObject)(JSValueConst);
typedef JS_BOOL(*wilton_JS_IsString)(JSValueConst);
typedef JS_BOOL(*wilton_JS_IsException)(JSValueConst);
typedef JSValue(*wilton_JS_NewStringLen)(JSContext*, const char*, size_t);
typedef JSValue(*wilton_JS_NewError)(JSContext*);
typedef JSValue(*wilton_JS_Call)(JSContext*, JSValueConst, JSValueConst, int, JSValueConst*);
typedef void(*wilton_JS_RunGC)(JSRuntime*);
typedef JSValue(*wilton_JS_WiltonUndefined)();
typedef JSValue(*wilton_JS_WiltonNull)();
    
} // namespace

extern "C" {
    
int JS_WiltonInitialize() {
    auto loaded = lib();
    if (nullptr == loaded) {
        return -1;
    }
    return 0;
}    

JSRuntime *JS_NewRuntime(void) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_NewRuntime");
    auto fun = reinterpret_cast<wilton_JS_NewRuntime>(ptr);
    return fun();
}

void JS_FreeRuntime(JSRuntime *rt) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_FreeRuntime");
    auto fun = reinterpret_cast<wilton_JS_FreeRuntime>(ptr);
    fun(rt);
}

JSContext *JS_NewContext(JSRuntime *rt) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_NewContext");
    auto fun = reinterpret_cast<wilton_JS_NewContext>(ptr);
    return fun(rt);
}

void JS_FreeContext(JSContext *s) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_FreeContext");
    auto fun = reinterpret_cast<wilton_JS_FreeContext>(ptr);
    fun(s);
}

void JS_SetMemoryLimit(JSRuntime *rt, size_t limit) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_SetMemoryLimit");
    auto fun = reinterpret_cast<wilton_JS_SetMemoryLimit>(ptr);
    fun(rt, limit);
}

void JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_SetGCThreshold");
    auto fun = reinterpret_cast<wilton_JS_SetGCThreshold>(ptr);
    fun(rt, gc_threshold);
}

void JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_SetMaxStackSize");
    auto fun = reinterpret_cast<wilton_JS_SetMaxStackSize>(ptr);
    fun(rt, stack_size);
}

JSValue JS_NewCFunction(JSContext *ctx, JSCFunction *func, const char *name, int length) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_NewCFunction");
    auto fun = reinterpret_cast<wilton_JS_NewCFunction>(ptr);
    return fun(ctx, func, name, length);
}

JS_BOOL JS_IsFunction(JSContext* ctx, JSValueConst val) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_IsFunction");
    auto fun = reinterpret_cast<wilton_JS_IsFunction>(ptr);
    return fun(ctx, val);
}

JSValue JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_Eval");
    auto fun = reinterpret_cast<wilton_JS_Eval>(ptr);
    return fun(ctx, input, input_len, filename, eval_flags);
}

JSValue JS_GetGlobalObject(JSContext *ctx) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_GetGlobalObject");
    auto fun = reinterpret_cast<wilton_JS_GetGlobalObject>(ptr);
    return fun(ctx);
}

void JS_FreeValue(JSContext *ctx, JSValue v) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_FreeValue");
    auto fun = reinterpret_cast<wilton_JS_FreeValue>(ptr);
    fun(ctx, v);
}

JSValue JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_GetPropertyStr");
    auto fun = reinterpret_cast<wilton_JS_GetPropertyStr>(ptr);
    return fun(ctx, this_obj, prop);
}

int JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_SetPropertyStr");
    auto fun = reinterpret_cast<wilton_JS_SetPropertyStr>(ptr);
    return fun(ctx, this_obj, prop, val);
}

const char *JS_ToCStringLen(JSContext *ctx, size_t *plen, JSValueConst val1) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_ToCStringLen");
    auto fun = reinterpret_cast<wilton_JS_ToCStringLen>(ptr);
    return fun(ctx, plen, val1);
}

void JS_FreeCString(JSContext *ctx, const char *ptr1) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_FreeCString");
    auto fun = reinterpret_cast<wilton_JS_FreeCString>(ptr);
    fun(ctx, ptr1);
}

JSValue JS_Throw(JSContext *ctx, JSValue obj) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_Throw");
    auto fun = reinterpret_cast<wilton_JS_Throw>(ptr);
    return fun(ctx, obj);
}

JSValue JS_GetException(JSContext *ctx) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_GetException");
    auto fun = reinterpret_cast<wilton_JS_GetException>(ptr);
    return fun(ctx);
}

JS_BOOL JS_IsObject(JSValueConst v) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_IsObject");
    auto fun = reinterpret_cast<wilton_JS_IsObject>(ptr);
    return fun(v);
}

JS_BOOL JS_IsString(JSValueConst v) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_IsString");
    auto fun = reinterpret_cast<wilton_JS_IsString>(ptr);
    return fun(v);
}

JS_BOOL JS_IsException(JSValueConst v) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_IsException");
    auto fun = reinterpret_cast<wilton_JS_IsException>(ptr);
    return fun(v);
}

JSValue JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_NewStringLen");
    auto fun = reinterpret_cast<wilton_JS_NewStringLen>(ptr);
    return fun(ctx, str1, len1);
}

JSValue JS_NewError(JSContext *ctx) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_NewError");
    auto fun = reinterpret_cast<wilton_JS_NewError>(ptr);
    return fun(ctx);
}

JSValue JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_Call");
    auto fun = reinterpret_cast<wilton_JS_Call>(ptr);
    return fun(ctx, func_obj, this_obj, argc, argv);
}

void JS_RunGC(JSRuntime *rt) {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_RunGC");
    auto fun = reinterpret_cast<wilton_JS_RunGC>(ptr);
    fun(rt);
}

JSValue JS_WiltonUndefined() {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_WiltonUndefined");
    auto fun = reinterpret_cast<wilton_JS_WiltonUndefined>(ptr);
    return fun();
}

JSValue JS_WiltonNull() {
    auto ptr = ::GetProcAddress(lib(), "wilton_JS_WiltonNull");
    auto fun = reinterpret_cast<wilton_JS_WiltonNull>(ptr);
    return fun();
}

} // extern
