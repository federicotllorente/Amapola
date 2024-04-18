# Amapola Engine

Under constuction... :)

I started this project following the [Game Engine series by The Cherno](https://thecherno.com/engine), to continue my learning path in OpenGL and C++. I will be documenting my progress here as well for now.

## Compile and run this project

*TODO*

## Libraries and modules

To handle/manage libraries and modules, specifically external ones, are managed with Git modules. You can find them listed in the `.gitmodules` file.

### GLFW

**Important**: if the GLFW submodule is updated and the `premake5.lua` file changes, verify that `staticruntime` is still the same value as in the Premake file in the root project, since both Amapola (and all other projects) and GLFW should be compiled the same. If not, you will get errors at compiling.

So for example, if you're using/want to use static links for the C++ runtime, make sure both `premake5.lua` files have `staticruntime "on"`
