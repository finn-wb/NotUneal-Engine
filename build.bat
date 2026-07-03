@echo off
REM Build script for NotUneal Engine (Windows)
REM Usage: build.bat [options]

setlocal enabledelayedexpansion

echo ============================================
echo NotUneal Engine - Build Script (Windows)
echo ============================================
echo.

REM Default options
set BUILD_TYPE=Release
set BUILD_EDITOR=ON
set BUILD_TOOLS=ON
set BUILD_EXAMPLES=ON
set BUILD_TESTS=OFF
set GENERATOR=Visual Studio 17 2022

REM Parse arguments
:parse_args
if "%~1"==" " goto end_parse
if "%~1"=="-d" goto set_debug
if "%~1"=="--debug" goto set_debug
if "%~1"=="--no-editor" (set BUILD_EDITOR=OFF & shift & goto parse_args)
if "%~1"=="--no-tools" (set BUILD_TOOLS=OFF & shift & goto parse_args)
if "%~1"=="--no-examples" (set BUILD_EXAMPLES=OFF & shift & goto parse_args)
if "%~1"=="--tests" (set BUILD_TESTS=ON & shift & goto parse_args)
if "%~1"=="--clean" (goto do_clean)
if "%~1"=="-h" goto show_help
if "%~1"=="--help" goto show_help
shift
goto parse_args

:set_debug
set BUILD_TYPE=Debug
shift
goto parse_args

:show_help
echo Usage: build.bat [options]
echo.
echo Options:
echo   -d, --debug           Build debug version
echo   --no-editor           Skip editor build
echo   --no-tools            Skip tools build
echo   --no-examples         Skip examples build
echo   --tests               Build tests
echo   --clean               Clean build directory
echo   -h, --help            Show this help message
goto end

:do_clean
if exist build rmdir /s /q build
echo Cleaned build directory
goto end

:end_parse
echo Configuration:
echo   Build Type: %BUILD_TYPE%
echo   Editor: %BUILD_EDITOR%
echo   Tools: %BUILD_TOOLS%
echo   Examples: %BUILD_EXAMPLES%
echo   Tests: %BUILD_TESTS%
echo.

REM Create build directory
if not exist "build" mkdir build
echo Created build directory

cd build

REM Configure
echo Configuring CMake...
cmake -G "%GENERATOR%" -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ^
      -DNOTUNEAL_BUILD_EDITOR=%BUILD_EDITOR% ^
      -DNOTUNEAL_BUILD_TOOLS=%BUILD_TOOLS% ^
      -DNOTUNEAL_BUILD_EXAMPLES=%BUILD_EXAMPLES% ^
      -DNOTUNEAL_BUILD_TESTS=%BUILD_TESTS% ^
      ..

if errorlevel 1 (
    echo CMake configuration failed
    cd ..
    goto end
)

echo CMake configuration complete
echo.

REM Build
echo Building...
cmake --build . --config %BUILD_TYPE% --parallel

if errorlevel 1 (
    echo Build failed
    cd ..
    goto end
)

echo.
echo ============================================
echo Build Complete!
echo ============================================
echo.
echo Output:
echo   Libraries: .\build\
if "%BUILD_EXAMPLES%"=="ON" echo   Examples: .\build\Examples\
if "%BUILD_TESTS%"=="ON" echo   Tests: Run with 'ctest --verbose'
echo.

cd ..

:end
endlocal
