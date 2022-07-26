
Add the GCC compiler paths to `~/.bash_profile`:
```bash
#################
# GCC
export CC=/opt/homebrew/bin/gcc-11
export CXX=/opt/homebrew/bin/g++-11
```

## cmake

```bash
(base) ~/Coding/Udacity/C++/Proj1/lib/P0267_RefImpl/Debug> cmake ..
-- The CXX compiler identification is GNU 11.3.0
-- Checking whether CXX compiler has -isysroot
-- Checking whether CXX compiler has -isysroot - yes
-- Checking whether CXX compiler supports OSX deployment target flag
-- Checking whether CXX compiler supports OSX deployment target flag - yes
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /opt/homebrew/bin/g++-11 - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
Default IO2D backend was not specified, choosing automatically...
Found macOS, using CAIRO_XLIB.
-- Found PkgConfig: /opt/homebrew/bin/pkg-config (found version "0.29.2")
-- Found Cairo: /opt/homebrew/Cellar/cairo/1.16.0_5/include/cairo (found version "1.16.0")
-- Checking for module 'GraphicsMagick'
--   Found GraphicsMagick, version 1.3.38
-- Found GraphicsMagick: /opt/homebrew/Cellar/graphicsmagick/1.3.38/include/GraphicsMagick
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/billywu/Coding/Udacity/C++/Proj1/lib/P0267_RefImpl/Debug
```

## Install X11

`brew install --cask xquartz`

Header files at `/opt/X11/include/X11/` and 