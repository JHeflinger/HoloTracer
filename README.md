# HoloTracer
HoloTracer is a ray-tracer esque application that aims to allow users to upload 3D models and generate
interference patterns that can be used to create holograms (the laser with film kind)! This will enable
users to perfectly reconstruct scenes they with to turn into holograms easily. 

## Features
HoloTracer plans to include but is not limited to the following features:
- Intuitive Graphical Interface
- Optimized point cloud and interference pattern algorithm
- Full color interference pattern support

## Progress
HoloTracer is currently still in the early development stages which includes heavy research and testing. Currently we aim
to have a stable release by mid 2024

## Getting Started
To get started, run the following to clone the repository:

```
git clone --recursive https://github.com/JHeflinger/HoloTracer.git
```

This will initialize and download all the required git submodules for the dependencies Flora uses. If you've already
cloned Flora normally, you can also run the following to download submodules:

```
git submodule update --init --recursive
```

Once everything is properly cloned, run the respective build script in the scripts folder for your operating system. For example, for windows, run

```
cd scripts
./WIN_GenerateProj.bat
```

Note that this builds project files for **Visual Studio 2019**. If you use a different version of visual studio, you may need to use a different version of premake
(located in the `vendor/premake/bin` folder) and modify the respective build script. 

This will generate all the solution files needed using premake. Once that succeeds, you're all set! You can now open the .sln file in Visual Studio 2019 and start 
using HoloTracer!