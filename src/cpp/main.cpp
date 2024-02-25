#define NAPI_VERSION 9
#include <napi.h>
#include <math.h>

using namespace Napi;

void add(double a, double b, double& res)
{
    res = a + b;
}

Value add(const CallbackInfo& info) {
    Env env = info.Env();

    double res;
    Number a = info[0].As<Number>();
    Number b = info[1].As<Number>();

    add(a.DoubleValue(), b.DoubleValue(), res);

    Number output = Number::New(env, res);
    //return String::New(env, "Hello, world");
    return output;
}



Object Init(Env env, Object exports) {
    exports.Set(String::New(env, "add"), Function::New<add>(env));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)