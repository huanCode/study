- Android NDK r5开始支持了STL Port

名称|说明|功能|
-|-|-|
|libstdc++（默认）|默认最小系统 C++ 运行时库|不适用
|gabi++_static/gabi++_shared|GAbi++ 运行时|C++ 异常和 RTTI
|stlport_static/stlport_shared|STLport 运行时|C++ 异常和 RTTI；标准库
|gnustl_static/gnustl_shared|GNU STL|C++ 异常和 RTTI；标准库
c++_static/c++_shared|LLVM libc++ 运行时|C++ 异常和 RTTI；标准库
