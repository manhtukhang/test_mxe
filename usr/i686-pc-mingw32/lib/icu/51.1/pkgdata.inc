GENCCODE_ASSEMBLY_TYPE=-a gcc-cygwin
SO=dll
SOBJ=dll
A=a
LIBPREFIX=libs
LIB_EXT_ORDER=51.dll
COMPILE=i686-pc-mingw32-gcc   -DHAVE_DLOPEN=0 -DU_HAVE_MMAP=0  -DU_STATIC_IMPLEMENTATION -DU_ATTRIBUTE_DEPRECATED= -DU_USING_ICU_NAMESPACE=0 -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings -mthreads -c
LIBFLAGS=-I/home/travis/mxe/usr/i686-pc-mingw32/include -DPIC 
GENLIB=i686-pc-mingw32-gcc -DU_USING_ICU_NAMESPACE=0 -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings -mthreads  -shared -Wl,-Bsymbolic -Wl,--enable-auto-import -Wl,--out-implib=./all.lib
LDICUDTFLAGS=
LD_SONAME=
RPATH_FLAGS=
BIR_LDFLAGS=
AR=i686-pc-mingw32-ar
ARFLAGS=r
RANLIB=i686-pc-mingw32-ranlib
INSTALL_CMD=/usr/bin/install -c
