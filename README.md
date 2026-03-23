# supermarket-management-system

> 基于 **Qt Widgets** 的超市管理系统课程项目，包含源码与 Windows 可执行文件。
> A **Qt Widgets** supermarket management system (course project) with source code and a Windows build.

## 项目目的 / Purpose
用于练习 Qt 桌面应用开发与基本业务流（商品入库、出库、退货、信息展示等）的完整实现。

## 功能 / Features
- 商品初始化
- 商品新增/删除
- 商品信息展示
- 商品售出/退货
- 数据保存

## 技术栈 / Tech Stack
- C++17
- Qt 5/6 Widgets
- CMake

## 目录结构 / Structure
```
.
├── supermarket-management-system/      # Qt 源码工程（.cpp/.h/.ui）
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── mainwindow.ui
│   └── ...
└── 超市管理系统（可执行文件）/           # Windows 可执行文件与运行依赖
    └── 超市管理系统.exe
```

## 运行方式 / Run

### 方式一：直接运行（Windows）
进入 `超市管理系统（可执行文件）/` 目录，双击 `超市管理系统.exe`。

### 方式二：源码构建（Qt Creator / CMake）
**依赖**：Qt 5/6（Widgets）、CMake ≥ 3.5、C++17

```bash
mkdir build && cd build
cmake ../supermarket-management-system
cmake --build .
```

## 说明 / Notes
- 工程入口：`main.cpp`
- UI 文件：`mainwindow.ui`、`form.ui`
- 可执行目录已包含运行所需的 Qt 依赖（Windows）

## License
未声明。
