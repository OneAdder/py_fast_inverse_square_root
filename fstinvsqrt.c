#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdint.h>
#include <math.h>

const char _VERSION[] = "0.0.1";
const char _MODULE_DOCSTRING[] = "Python bindings for C implementation of Fast Inverse Square Root";
const char _METHOD_DOCSTRING[] = "`inv_sqrt(num)`\n"
                                 "C implementation of Fast Inverse Square Root for Python\n"
                                 "\n"
                                 "Accepts `int` or `float`, returns `float`.\n";


float _Q_rsqrt( float number )
{
    // It's from Wikipedia
    const float x2 = number * 0.5F;
    const float threehalfs = 1.5F;

    union {
        float f;
        uint32_t i;
    } conv  = { .f = number };
    conv.i  = 0x5f3759df - ( conv.i >> 1 );
    conv.f  *= threehalfs - ( x2 * conv.f * conv.f );
    return conv.f;
}


double _round(double num){
    return roundl(num * 1000000) / 1000000;
}


static PyObject * fastinvscqrt_invsqrt(PyObject * self, PyObject * args){
    const double num;
    if (!PyArg_ParseTuple(args, "d", &num)){
        return NULL;
    }
    return PyFloat_FromDouble(_round(_Q_rsqrt((float) num)));
}


static PyMethodDef QrsqrtMethods[] = {
    {"inv_sqrt", fastinvscqrt_invsqrt, METH_VARARGS, PyDoc_STR(_METHOD_DOCSTRING)},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef QrstartModule = {
    PyModuleDef_HEAD_INIT,
    "fstinvsqrt",
    _MODULE_DOCSTRING,
    -1,
    QrsqrtMethods
};


PyMODINIT_FUNC PyInit_fstinvsqrt(void){
    PyObject * module = PyModule_Create(&QrstartModule);
    PyModule_AddStringConstant(module, "__version__", _VERSION);
    return module;
}
