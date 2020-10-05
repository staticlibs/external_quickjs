
#include <string>
#include "quickjs.h"

extern "C" {

JSRuntime *JS_NewRuntime(void) {
    return nullptr;
}

void JS_FreeRuntime(JSRuntime *rt) {
    (void) rt;
}

JSContext *JS_NewContext(JSRuntime *rt) {
    (void) rt;
    return nullptr;
}

void JS_FreeContext(JSContext *s) {
    (void) s;
}

void JS_SetMemoryLimit(JSRuntime *rt, size_t limit) {
    (void) rt;
    (void) limit;
}

void JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold) {
    (void) rt;
    (void) gc_threshold;
}

void JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size) {
    (void) rt;
    (void) stack_size;
}

JSValue JS_NewCFunction(JSContext *ctx, JSCFunction *func, const char *name, int length) {
    (void) ctx;
    (void) func;
    (void) name;
    (void) length;
    return JSValue{};
}

JS_BOOL JS_IsFunction(JSContext* ctx, JSValueConst val) {
    (void) ctx;
    (void) val;
    return 0;
}

JSValue JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags) {
    (void) ctx;
    (void) input;
    (void) input_len;
    (void) filename;
    (void) eval_flags;
    return JSValue{};
}

JSValue JS_GetGlobalObject(JSContext *ctx) {
    (void) ctx;
    return JSValue{};
}

void JS_FreeValue(JSContext *ctx, JSValue v) {
    (void) ctx;
    (void) v;
}

JSValue JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop) {
    (void) ctx;
    (void) this_obj;
    (void) prop;
    return JSValue{};
}

int JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val) {
    (void) ctx;
    (void) this_obj;
    (void) prop;
    (void) val;
    return 0;
}

const char *JS_ToCStringLen(JSContext *ctx, size_t *plen, JSValueConst val1) {
    (void) ctx;
    (void) plen;
    (void) val1;
    return nullptr;
}

void JS_FreeCString(JSContext *ctx, const char *ptr) {
    (void) ctx;
    (void) ptr;
}

JSValue JS_Throw(JSContext *ctx, JSValue obj) {
    (void) ctx;
    (void) obj;
    return JSValue{};
}

JSValue JS_GetException(JSContext *ctx) {
    (void) ctx;
    return JSValue{};
}

JS_BOOL JS_IsObject(JSValueConst v) {
    (void) v;
    return 0;
}

JS_BOOL JS_IsString(JSValueConst v) {
    (void) v;
    return 0;
}

JS_BOOL JS_IsException(JSValueConst v) {
    (void) v;
    return 0;
}

JSValue JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1) {
    (void) ctx;
    (void) str1;
    (void) len1;
    return JSValue{};
}

JSValue JS_NewError(JSContext *ctx) {
    (void) ctx;
    return JSValue{};
}

JSValue JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv) {
    (void) ctx;
    (void) func_obj;
    (void) this_obj;
    (void) argc;
    (void) argv;
    return JSValue{};
}

void JS_RunGC(JSRuntime *rt) {
    (void) rt;
}

JSValue JS_WiltonUndefined() {
    return JSValue{};
}

JSValue JS_WiltonNull() {
    return JSValue{};
}

} // extern
