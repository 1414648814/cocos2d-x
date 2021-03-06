/*
 * Copyright (c) 2012 Zynga Inc.
 * Copyright (c) 2013-2014 Chukong Technologies Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __JS_COCOSBUILDER_SPECIFICS_H__
#define __JS_COCOSBUILDER_SPECIFICS_H__

#include "../cocos2d_specifics.hpp"

class JSCCBAnimationWrapper: public JSCallbackWrapper 
{
public:
    JSCCBAnimationWrapper(JS::HandleValue owner) : JSCallbackWrapper(owner) {}
    virtual ~JSCCBAnimationWrapper() {}
    
    void animationCompleteCallback()
    {
        JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
        JS::RootedValue callback(cx, getJSCallbackFunc());
        JS::RootedValue thisObj(cx, getJSCallbackThis());
        if(!callback.isNullOrUndefined()  && !thisObj.isNullOrUndefined())
        {

            JS::RootedValue retval(cx);

            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
            
            JS::RootedObject jsThis(cx, thisObj.toObjectOrNull());
            JS::RootedValue jsCallback(cx, callback);
            JS_CallFunctionValue(cx, jsThis, jsCallback, JS::HandleValueArray::empty(), &retval);
        }
    }
    
};

#endif
