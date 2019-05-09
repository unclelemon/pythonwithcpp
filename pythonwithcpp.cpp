#include <Python.h> // this is in <python-install-path>
#include <iostream>
#include <string>
 
using namespace std;
 
bool calc(string filename, string methodname, string expression, double *result)
{
    
    PyObject *pyFileName, *pyMod, *pyFunc;
    pyFileName = PyString_FromString(filename.c_str());
    pyMod = PyImport_Import(pyFileName);  // load the module
    if (pyMod)                                      // if ok
    {
        printf("test_2\n");
        pyFunc = PyObject_GetAttrString(pyMod, methodname.c_str());   // load the function
        if (pyFunc && PyCallable_Check(pyFunc))
        {
	    printf("test_3\n");
            PyObject *pyParams = PyTuple_New(1);
            PyObject *pyValue = PyString_FromString(expression.c_str());
            PyTuple_SetItem(pyParams, 0, pyValue);
            
            pyValue = PyObject_CallObject(pyFunc, pyParams);    // ok, call the function
            if (pyValue)
            {
	      printf("test_4\n");
                *result = PyFloat_AsDouble(pyValue);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}
 
int main(void)
{
    string filename = "ceshi";    // filename is settled!
    string methodname = "cala";    // method name is also settled!
    string expression = "";             // get user input!
    double result = 0.0;
    printf("\nPlease input the expression: ");
    getline(cin, expression);
 
    // first init
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    if(!Py_IsInitialized())
    {
        printf("end");
    }
    if (calc(filename, methodname, expression, &result))
    {
        printf("\nResult is : %lf\n", result);
    }
    else
    {
        printf("\nError occurred...\n");
    }
    // last fini!
    Py_Finalize();
 
    return 0;
}

