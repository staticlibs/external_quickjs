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
 * File:   quickjs_test.cpp
 * Author: alex
 *
 * Created on July 1, 2020, 1:10 PM
 */

#include <cstdlib>

using namespace std;

#include "quickjs.h"

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "staticlib/config/assert.hpp"

#include "staticlib/support.hpp"


void test_eval() {
    auto rt = JS_NewRuntime();
    slassert(nullptr != rt);
    auto ctx = JS_NewContext(rt);
    slassert(nullptr != ctx);

    auto hello = std::string("Hello world!");
    //auto code = std::string("let a = \"" + hello +"\"; a");
    auto code = std::string("\"Hello\" + \" \" + \"world!\"");
    auto val = JS_Eval(ctx, code.c_str(), code.length(), "hello.js", 0);
    slassert(JS_IsString(val) > 0);
    auto res = JS_ToCString(ctx, val);
    slassert(nullptr != res);
    auto res_str = std::string(res);
    slassert(hello == res_str);

    JS_FreeCString(ctx, res);
    JS_FreeValue(ctx, val);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
}

void test_errors() {
    auto rt = JS_NewRuntime();
    auto ctx = JS_NewContext(rt);

    auto code = std::string("AAAAAA");
    auto ret_val = JS_Eval(ctx, code.c_str(), code.length(), "text/fail.js", 0);
    slassert(JS_IsException(ret_val) > 0);
    auto exc_val = JS_GetException(ctx);
    slassert(JS_IsObject(exc_val) > 0);
    auto msg_val = JS_GetPropertyStr(ctx, exc_val, "message");
    slassert(JS_IsString(msg_val) > 0);
    auto msg = JS_ToCString(ctx, msg_val);
    //std::cout << "[" << msg << "]" << std::endl;
    auto stack_val = JS_GetPropertyStr(ctx, exc_val, "stack");
    slassert(JS_IsString(stack_val) > 0);
    auto stack = JS_ToCString(ctx, stack_val);
    //std::cout << "[" << stack << "]" << std::endl;

    JS_FreeValue(ctx, ret_val);
    JS_FreeValue(ctx, exc_val);
    JS_FreeCString(ctx, msg);
    JS_FreeValue(ctx, msg_val);
    JS_FreeCString(ctx, stack);
    JS_FreeValue(ctx, stack_val);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
}

static JSValue my_native_func(JSContext *ctx, JSValueConst this_val,
        int argc, JSValueConst *argv) {
    (void) this_val;
    (void) argc;
    auto input = JS_ToCString(ctx, argv[0]);
    std::cout << "my_native_func called" << std::endl;
    std::cout << argc << std::endl;
    std::cout << std::string(input) << std::endl;
    JS_FreeCString(ctx, input);
    auto res = JS_NewString(ctx, "foo");
    return res;
}

void test_call_native() {
    auto rt = JS_NewRuntime();
    auto ctx = JS_NewContext(rt);

    auto fun = JS_NewCFunction(ctx, my_native_func, "myfun", 1);
    slassert(JS_IsObject(fun) > 0);
    slassert(JS_IsFunction(ctx, fun) > 0);
    auto obj = JS_GetGlobalObject(ctx);
    slassert(JS_IsObject(obj) > 0);
    auto res_code = JS_SetPropertyStr(ctx, obj, "myfun", fun);
    slassert(res_code > 0);

    auto code = std::string("myfun(\"Hello!\")");
    auto ret_val = JS_Eval(ctx, code.c_str(), code.length(), "fun.js", 0);

    if (JS_IsException(ret_val) > 0) {
        auto exc_val = JS_GetException(ctx);
        auto msg = JS_ToCString(ctx, exc_val);
        std::cout << "[" << msg << "]" << std::endl;
        JS_FreeCString(ctx, msg);
        JS_FreeValue(ctx, exc_val);
    }

    slassert(JS_IsString(ret_val) > 0);
    auto ret = JS_ToCString(ctx, ret_val);
    auto ret_str = std::string(ret);
    slassert(ret_str == "foo");

    JS_FreeCString(ctx, ret);
    JS_FreeValue(ctx, ret_val);
    //JS_FreeValue(ctx, fun);
    JS_FreeValue(ctx, obj);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
}

int main() {
    try {
        test_eval();
        test_errors();
        test_call_native();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

