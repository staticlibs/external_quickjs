
#include "quickjs.h"

__declspec(dllexport)
JSRuntime *wilton_JS_NewRuntime(void) {
    return JS_NewRuntime();
}

__declspec(dllexport)
void wilton_JS_FreeRuntime(JSRuntime *rt) {
    JS_FreeRuntime(rt);
}

__declspec(dllexport)
JSContext *wilton_JS_NewContext(JSRuntime *rt) {
   return JS_NewContext(rt); 
}

__declspec(dllexport)
void wilton_JS_FreeContext(JSContext *s) {
    JS_FreeContext(s);
}

__declspec(dllexport)
void wilton_JS_SetMemoryLimit(JSRuntime *rt, size_t limit) {
    JS_SetMemoryLimit(rt, limit);
}

__declspec(dllexport)
void wilton_JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold) {
    JS_SetGCThreshold(rt, gc_threshold);
}

__declspec(dllexport)
void wilton_JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size) {
    JS_SetMaxStackSize(rt, stack_size);
}

__declspec(dllexport)
JSValue wilton_JS_NewCFunction(JSContext *ctx, JSCFunction *func, const char *name, int length) {
    return JS_NewCFunction(ctx, func, name, length);
}

__declspec(dllexport)
JS_BOOL wilton_JS_IsFunction(JSContext* ctx, JSValueConst val) {
    return JS_IsFunction(ctx, val);
}

__declspec(dllexport)
JSValue wilton_JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags) {
    return JS_Eval(ctx, input, input_len, filename, eval_flags);
}

__declspec(dllexport)
JSValue wilton_JS_GetGlobalObject(JSContext *ctx) {
    return JS_GetGlobalObject(ctx);
}

__declspec(dllexport)
void wilton_JS_FreeValue(JSContext *ctx, JSValue v) {
    JS_FreeValue(ctx, v);
}

__declspec(dllexport)
JSValue wilton_JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop) {
    return JS_GetPropertyStr(ctx, this_obj, prop);
}

__declspec(dllexport)
int wilton_JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val) {
    return JS_SetPropertyStr(ctx, this_obj, prop, val);
}

__declspec(dllexport)
const char *wilton_JS_ToCStringLen(JSContext *ctx, size_t *plen, JSValueConst val1) {
    return JS_ToCStringLen(ctx, plen, val1);
}

__declspec(dllexport)
void wilton_JS_FreeCString(JSContext *ctx, const char *ptr) {
    JS_FreeCString(ctx, ptr);
}

__declspec(dllexport)
JSValue wilton_JS_Throw(JSContext *ctx, JSValue obj) {
    return JS_Throw(ctx, obj);
}

__declspec(dllexport)
JSValue wilton_JS_GetException(JSContext *ctx) {
    return JS_GetException(ctx);
}

__declspec(dllexport)
JS_BOOL wilton_JS_IsObject(JSValueConst v) {
    return JS_IsObject(v);
}

__declspec(dllexport)
JS_BOOL wilton_JS_IsString(JSValueConst v) {
    return JS_IsString(v);
}

__declspec(dllexport)
JS_BOOL wilton_JS_IsException(JSValueConst v) {
    return JS_IsException(v);
}

__declspec(dllexport)
JSValue wilton_JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1) {
    return JS_NewStringLen(ctx, str1, len1);
}

__declspec(dllexport)
JSValue wilton_JS_NewError(JSContext *ctx) {
    return JS_NewError(ctx);
}

__declspec(dllexport)
JSValue wilton_JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv) {
    return JS_Call(ctx, func_obj, this_obj, argc, argv);
}

__declspec(dllexport)
void wilton_JS_RunGC(JSRuntime *rt) {
    JS_RunGC(rt);
}

__declspec(dllexport)
JSValue wilton_JS_WiltonUndefined() {
    return JS_WiltonUndefined();
}

__declspec(dllexport)
JSValue wilton_JS_WiltonNull() {
    return JS_WiltonNull(); 
}
