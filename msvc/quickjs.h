
#ifndef QUICKJS_H
#define QUICKJS_H

#include <stdint.h>

extern "C" {

#define JS_BOOL int

typedef union JSValueUnion {
    int32_t int32;
    double float64;
    void *ptr;
} JSValueUnion;

typedef struct JSValue {
    JSValueUnion u;
    int64_t tag;
} JSValue;

#define JSValueConst JSValue

typedef struct JSRuntime JSRuntime;
typedef struct JSContext JSContext;

typedef JSValue JSCFunction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv);

JSRuntime *JS_NewRuntime(void);
void JS_FreeRuntime(JSRuntime *rt);
JSContext *JS_NewContext(JSRuntime *rt);
void JS_FreeContext(JSContext *s);
void JS_SetMemoryLimit(JSRuntime *rt, size_t limit);
void JS_SetGCThreshold(JSRuntime *rt, size_t gc_threshold);
void JS_SetMaxStackSize(JSRuntime *rt, size_t stack_size);
JSValue JS_NewCFunction(JSContext *ctx, JSCFunction *func, const char *name, int length);
JS_BOOL JS_IsFunction(JSContext* ctx, JSValueConst val);
JSValue JS_Eval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int eval_flags);
JSValue JS_GetGlobalObject(JSContext *ctx);
void JS_FreeValue(JSContext *ctx, JSValue v);
JSValue JS_GetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop);
int JS_SetPropertyStr(JSContext *ctx, JSValueConst this_obj, const char *prop, JSValue val);
const char *JS_ToCStringLen(JSContext *ctx, size_t *plen, JSValueConst val1);
void JS_FreeCString(JSContext *ctx, const char *ptr);
JSValue JS_Throw(JSContext *ctx, JSValue obj);
JSValue JS_GetException(JSContext *ctx);
JS_BOOL JS_IsObject(JSValueConst v);
JS_BOOL JS_IsString(JSValueConst v);
JS_BOOL JS_IsException(JSValueConst v);
JSValue JS_NewStringLen(JSContext *ctx, const char *str1, size_t len1);
JSValue JS_NewError(JSContext *ctx);
JSValue JS_Call(JSContext *ctx, JSValueConst func_obj, JSValueConst this_obj, int argc, JSValueConst *argv);
void JS_RunGC(JSRuntime *rt);

int JS_WiltonInitialize();
JSValue JS_WiltonUndefined();
JSValue JS_WiltonNull();

} // extern

#endif QUICKJS_H