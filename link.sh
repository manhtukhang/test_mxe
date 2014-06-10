#!/bin/bash
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/10-scale-bitmap-fonts.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/65-fonts-persian.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/20-unhint-small-vera.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/50-user.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/30-urw-aliases.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/60-latin.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/69-unifont.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/30-metric-aliases.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/90-synthetic.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/49-sansserif.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/45-latin.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/40-nonlatin.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/51-local.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/80-delicious.conf
rm $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d/65-nonlatin.conf
rm $(pwd)/usr/bin/i686-pc-mingw32-libgcrypt-config
rm $(pwd)/usr/bin/i686-pc-mingw32-icu-config
rm $(pwd)/usr/bin/i686-pc-mingw32-pg_config
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/10-scale-bitmap-fonts.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/65-fonts-persian.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/20-unhint-small-vera.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/50-user.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/30-urw-aliases.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/60-latin.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/69-unifont.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/30-metric-aliases.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/90-synthetic.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/49-sansserif.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/45-latin.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/40-nonlatin.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/51-local.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/80-delicious.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/share/fontconfig/conf.avail/65-nonlatin.conf $(pwd)/usr/i686-pc-mingw32/etc/fonts/conf.d
ln -s $(pwd)/usr/i686-pc-mingw32/bin/libgcrypt-config -T $(pwd)/usr/bin/i686-pc-mingw32-libgcrypt-config
ln -s $(pwd)/usr/i686-pc-mingw32/bin/icu-config -T $(pwd)/usr/bin/i686-pc-mingw32-icu-config
ln -s $(pwd)/usr/i686-pc-mingw32/bin/pg_config -T $(pwd)/usr/bin/i686-pc-mingw32-pg_config
